#include "Adder.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

Adder::Adder( const string &name )
  : Atomic( name )
  , C( this->addOutputPort( "C" ) )
  , responseTime( 0, 0, 0, 1 )
{
   OPA = addPorts( ptInput, "OPA", 32, *this );
   OPB = addPorts( ptInput, "OPB", 32, *this );
   RES = addPorts( ptOutput, "RES", 32, *this );
   if (MainSimulator::Instance().existsParameter( this->description(), "response")) { 
     string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
     if( time != "" )
       responseTime = time ;
   }
}

Adder::~Adder() {
  delete [] OPA;
  delete [] OPB;
  delete [] RES;
}

Model &Adder::initFunction()
{
   return *this;
}

Model &Adder::externalFunction( const ExternalMessage &msg )
{
   string portName;
   int portNum;
   nameNum( msg.port().name(), portName, portNum );
   if( portName == "opa" )
      opa[portNum] = bit( msg.value() );
   else
      opb[portNum] = bit( msg.value() );
   this->holdIn( active, responseTime );
   return *this;
}

Model &Adder::internalFunction( const InternalMessage & )
{
   this->passivate();
   return *this;
}

Model &Adder::outputFunction( const InternalMessage &msg )
{
   toBits( fromBits( opa ) + fromBits( opb ), res );
   c.val = (opa[31]&&opb[31]) || ((opa[31]||opb[31])&&!res[31].val);
   for( int i = 0; i < 32; i++ )
      if( needSend( res[i] ) )
	 this->sendOutput( msg.time(), *RES[i], res[i].val );
   if( needSend( c ) )
      this->sendOutput( msg.time(), C, c.val );
   return *this;
}
