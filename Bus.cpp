#include "Bus.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

#define numpn 7
static string pn[numpn] = { "AS", "RD_WR", "DTACK", "ERR", "RESET", "BUSY", "CLOCK" };

Bus::Bus( const string &name )
  : Atomic( name )
  , responseTime( 0, 0, 0, 1 )

{
  numports = numpn + 32 * 2 + 4 + 15;
  OUT = new (Port *)[numports];
  IN = new (Port *)[numports];
  int i = 0;
  for( ; i < numpn; i++ ) {
    OUT[i] = & this->addOutputPort( "OUT_" + pn[i] );
    IN[i] = & this->addInputPort( "IN_" + pn[i] );
  }
  for( int j = 0; j < 32; j++ ) {
    OUT[i] = & this->addOutputPort( "OUT_DATA" + itos( j ) );
    IN[i] = & this->addInputPort( "IN_DATA" + itos( j ) );
    i++;
  }
  for( int j = 0; j < 32; j++ ) {
    OUT[i] = & this->addOutputPort( "OUT_A" + itos( j ) );
    IN[i] = & this->addInputPort( "IN_A" + itos( j ) );
    i++;
  }
  for( int j = 0; j < 4; j++ ) {
    OUT[i] = & this->addOutputPort( "OUT_BSEL" + itos( j ) );
    IN[i] = & this->addInputPort( "IN_BSEL" + itos( j ) );
    i++;
  }
  for( int j = 1; j < 16; j++ ) {
    OUT[i] = & this->addOutputPort( "OUT_IRQ" + itos( j ) );
    IN[i] = & this->addInputPort( "IN_IRQ" + itos( j ) );
    i++;
  }
  out = new o_bit[numports];

  if (MainSimulator::Instance().existsParameter( this->description(), "response")) { 
    string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
    if( time != "" )
      responseTime = time ;
  }
}

Bus::~Bus() {
  delete [] OUT;
  delete [] IN;
  delete [] out;
}

Model &Bus::initFunction()
{
   return *this;
}

Model &Bus::externalFunction( const ExternalMessage &msg )
{
  int i;
  for( i = 0; i < numports && !( *IN[i] == msg.port() ); i++ )
    ;
  out[i].val = bit( msg.value() );
  this->holdIn( active, responseTime );
  return *this;
}

Model &Bus::internalFunction( const InternalMessage & )
{
  this->passivate();
  return *this;
}

Model &Bus::outputFunction( const InternalMessage &msg )
{
  for( int i = 0; i < numports; i++ )
    if( needSend( out[i] ) )
      this->sendOutput( msg.time(), *OUT[i], out[i].val );
  return *this;
}
