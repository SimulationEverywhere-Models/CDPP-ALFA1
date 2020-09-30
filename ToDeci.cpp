#include "ToDeci.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

ToDeci::ToDeci( const string &name )
  : Atomic( name )
  , OUT( this->addOutputPort( "OUT" ) )
  , responseTime( 0, 0, 0, 0 )
  , nbits( defnbits )
{
  string snbits( MainSimulator::Instance().getParameter( this->description(), "nbits" ) ) ;
  if( snbits != "" )
    nbits = atoi( snbits.c_str() );

  IN = addPorts( ptInput, "IN", nbits, *this );
  in = new bit [nbits];

  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

  if( time != "" )
    responseTime = time ;
}

ToDeci::~ToDeci() {
  delete [] IN;
  delete [] in;
}

Model &ToDeci::initFunction() {
   return *this;
}

Model &ToDeci::externalFunction( const ExternalMessage &msg ) {
  string portName;
  int portNum;
  nameNum( msg.port().name(), portName, portNum );
  in[portNum] = int( msg.value() );
  this->holdIn( active, responseTime );
  return *this;
}

Model &ToDeci::internalFunction( const InternalMessage & ) {
  this->passivate();
  return *this;
}

Model &ToDeci::outputFunction( const InternalMessage &msg ) {
  out = fromBits( in, nbits );
  this->sendOutput( msg.time(), OUT, out );
  return *this;
}
