#include "TestOut.h"
#include <message.h>

TestOut::TestOut( const string &name )
  : Atomic( name )
  , OUT0( this->addOutputPort( "OUT0" ) )
  , OUT1( this->addOutputPort( "OUT1" ) )
{
}

Model &TestOut::initFunction()
{
  this->holdIn( active, 1);
  return *this;
}

Model &TestOut::externalFunction( const ExternalMessage &msg )
{
  this->passivate();
  return *this;
}

Model &TestOut::internalFunction( const InternalMessage & )
{
  this->holdIn( active, 1 );
  return *this;
}

Model &TestOut::outputFunction( const InternalMessage &msg )
{
  this->sendOutput( msg.time(), OUT0, 1 );
  this->sendOutput( msg.time(), OUT1, 1 );
  return *this;
}
