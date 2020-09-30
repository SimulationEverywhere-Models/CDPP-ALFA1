#include "FromDeci.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

FromDeci::FromDeci( const string &name )
  : Atomic( name )
  , IN( this->addInputPort( "IN" ) )
  , responseTime( 0, 0, 0, 0 )
  , nbits( defnbits )
{
  string snbits( MainSimulator::Instance().getParameter( this->description(), "nbits" ) ) ;
  if( snbits != "" )
    nbits = atoi( snbits.c_str() );

  OUT = addPorts( ptOutput, "OUT", nbits, *this );
  out = new o_bit [nbits];

  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

  if( time != "" )
    responseTime = time ;
}

FromDeci::~FromDeci() {
  delete [] OUT;
  delete [] out;
}

Model &FromDeci::initFunction() {
   return *this;
}

Model &FromDeci::externalFunction( const ExternalMessage &msg ) {
  in = int( msg.value() );
  this->holdIn( active, responseTime );
  return *this;
}

Model &FromDeci::internalFunction( const InternalMessage & ) {
   this->passivate();
   return *this;
}

Model &FromDeci::outputFunction( const InternalMessage &msg ) {
  toBits( in, out, nbits );
  for( int i = 0; i < nbits; i++ )
    if( needSend( out[i] ) )
      this->sendOutput( msg.time(), *OUT[i], out[i].val );
  return *this;
}
