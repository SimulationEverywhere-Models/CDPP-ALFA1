#include "AlignL.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

AlignL::AlignL( const string &name )
  : Atomic( name )
  , SIGN( this->addOutputPort( "SIGN" ) )
  , responseTime( 0, 0, 0, 1 )
{
   OP = addPorts( ptInput, "OP", 32, *this );
   SIZE = addPorts( ptInput, "SIZE", 2, *this );
   A = addPorts( ptInput, "A", 2, *this );
   RES = addPorts( ptOutput, "RES", 32, *this );

   if (MainSimulator::Instance().existsParameter( this->description(), "response")) { 
     string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
     if( time != "" )
       responseTime = time ;
   }
}
AlignL::~AlignL() {
  delete [] OP;
  delete [] SIZE;
  delete [] A;
  delete [] RES;
}

Model &AlignL::initFunction()
{
  return *this;
}

Model &AlignL::externalFunction( const ExternalMessage &msg )
{
  if( msg.port() == SIGN )
    sign = bit( msg.value() );
  else {
    string portName;
    int portNum;
    nameNum( msg.port().name(), portName, portNum );
    if( portName == "op" )
      op[portNum] = bit( msg.value() );
    else if( portName == "size" )
      size[portNum] = bit( msg.value() );
    else
      a[portNum] = bit( msg.value() );
  }
  this->holdIn( active, responseTime );
  return *this;
}

Model &AlignL::internalFunction( const InternalMessage & ) {
  this->passivate();
  return *this;
}

enum sizeValues { svWord = 0, svByte = 1, svHalfWord = 2 };

Model &AlignL::outputFunction( const InternalMessage &msg ) {
  if( sign ) {
    int o = fromBits( op ), r;
    switch( fromBits( size, 2 ) ) {
    case svWord:
      r = o;
      break;
    case svByte:
      r = ( o >> (16 * a[1]) ) & 0xFF;
      break;
    case svHalfWord:
      r = ( o >> (8 * fromBits( a, 2 )) ) & 0xF;
    }
    toBits( r, res );
  } else {
    unsigned int o = fromBits( op ), r;
    switch( fromBits( size, 2 ) ) {
    case svWord:
      r = o;
      break;
    case svHalfWord:
      r = ( o >> (16 * (1 - a[1]) ) ) & 0xFFFF;
      break;
    case svByte:
      r = ( o >> (8 * (3 - fromBits( a, 2 ) )) ) & 0xFF;
    }
    toBits( r, res );
  }

  for( int i = 0; i < 32; i++ )
    if( needSend( res[i] ) )
      this->sendOutput( msg.time(), *RES[i], res[i].val );
  return *this;
}
