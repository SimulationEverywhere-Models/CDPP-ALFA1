#include "MuxN.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

MuxN::MuxN( const string &name )
  : Atomic( name )
  , responseTime( 0, 0, 0, 1 )
  , nbits( defnbits )
  , nports( 4 )
  , sel( 0 )
{
  string snbits( MainSimulator::Instance().getParameter( this->description(), "nbits" ) ) ;
  string snports( MainSimulator::Instance().getParameter( this->description(), "nports" ) ) ;
  if( snbits != "" )
    nbits = atoi( snbits.c_str() );
  if( snports != "" )
    nports = atoi( snports.c_str() );
  IN = new (Port **) [nports];
  in = new (bit *) [nports];
  SEL = new (Port *) [nports];
  string sn("A");
  for( int i = 0; i < nports; i++ ) {
    sn[0] = 'A' + i;
    IN[i] = addPorts( ptInput, sn, nbits, *this );
    in[i] = new bit [nbits];
    SEL[nports] = & this->addInputPort( "SEL" + sn );
  }
  OUT = addPorts( ptOutput, "OUT", nbits, *this );
  out = new o_bit [nbits];

  if (MainSimulator::Instance().existsParameter( this->description(), "response")) { 
    string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
    if( time != "" )
      responseTime = time ;
  }
}

MuxN::~MuxN() {
  for( int i = 0; i < nports; i++ ) {
    delete [] IN[i];
    delete [] in[i];
  }
  delete [] SEL;
  delete [] OUT;
  delete [] out;
}

Model &MuxN::initFunction() {
   return *this;
}

Model &MuxN::externalFunction( const ExternalMessage &msg ) {
  if( msg.port().name().substr( 0, 3 ) == "sel" ) {
    if( msg.value() == 1 )
      sel = msg.port().name()[3] - 'a';
  } else {
    string portName;
    int portNum;
    nameNum( msg.port().name(), portName, portNum );
    in[portName[0] - 'a'][portNum] = bit( msg.value() );
  }
  this->holdIn( active, responseTime );
  return *this;
}

Model &MuxN::internalFunction( const InternalMessage & ) {
   this->passivate();
   return *this;
}

Model &MuxN::outputFunction( const InternalMessage &msg ) {
  for( int i = 0; i < nbits; i++ ) {
    out[i].val = in[sel][i];
    if( needSend( out[i] ) )
      this->sendOutput( msg.time(), *OUT[i], out[i].val );
  }
  return *this;
}
