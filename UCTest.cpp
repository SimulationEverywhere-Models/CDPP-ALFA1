#include "UCTest.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

#define numports 17
static string portnames[numports] = { "AS", "RD_WR", "R0_IN", "R1_IN", "R2_IN", "R3_IN", "RBM_OUT_IN", "RDM_IN", "Y_IN", "Z_IN"
       , "R0_OUT", "R1_OUT", "R2_OUT", "R3_OUT", "RBMIN_OUT", "RDM_OUT", "Z_OUT" };

enum { _R0in = 2, _R1in, _R2in, _R3in, _RBM_OUTin, _RDMin, _Yin, _Zin, _R0out, _R1out, _R2out, _R3out, _RBM_INout, _RDMout, _Zout };

#define numfases 8
static bit signals[numfases][4] =
{
    { 0, 0, _Yin      , _R2out }
  , { 0, 1, _Zin      , _R0out }
  , { 0, 1, _RDMin    , _Zout }
  , { 1, 1, _Zin      , _R1out }
  , { 0, 1, _RBM_OUTin, _RBM_INout }
  , { 0, 1, _RDMin    , _Zout }
  , { 1, 0, _Zin      , _R3out }
  , { 0, 1, _R2in     , _Zout }
};


UCTest::UCTest( const string &name )
  : Atomic( name )
  , CLCK( this->addInputPort( "CLCK" ) )
  , DTACK( this->addInputPort( "DTACK" ) )
  , END( this->addInputPort( "END" ) )
  , off( 0 )
  , end( 0 )
  , waitfmc( 0 )
  , fase( -1 )

{
  OUT = new (Port *)[numports];
  for( int i = 0; i < numports; i++ )
    OUT[i] = & this->addOutputPort( portnames[i] );
  out = new o_bit[numports];
}

UCTest::~UCTest() {
  delete [] OUT;
  delete [] out;
}

Model &UCTest::initFunction()
{
   return *this;
}

Model &UCTest::externalFunction( const ExternalMessage &msg )
{
  if( msg.port() == CLCK ) {
    if( end == 1 && fase == 6 && !off ) {
      off = 1;
      this->passivate();
    } else if( !waitfmc && !off ) {
      fase = (fase + 1) % numfases;
      this->holdIn( active, 0 );
    }
  } else if( msg.port() == DTACK ) {
    if( msg.value() == 1 ) {
      waitfmc = 0;
      this->passivate();
    }
  } else if( msg.port() == END ) {
    end = bit( msg.value() );
    this->passivate();
  }
  return *this;
}

Model &UCTest::internalFunction( const InternalMessage & )
{
  if( signals[fase][0] == 1 )
    waitfmc = 1;
  this->passivate();
  return *this;
}

Model &UCTest::outputFunction( const InternalMessage &msg )
{
  out[0].val = signals[ fase ][0];
  out[1].val = signals[ fase ][1];
  for( int i = 2; i < numports; i++ )
    out[i].val = 0;
  out[signals[ fase ][2]].val = 1;
  out[signals[ fase ][3]].val = 1;

  for( int i = 0; i < numports; i++ )
    if( needSend( out[i] ) )
      this->sendOutput( msg.time(), *OUT[i], out[i].val );
  return *this;
}
