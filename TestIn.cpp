#include "TestIn.h"

TestIn::TestIn( const string &name )
  : Atomic( name )
  , IN( this->addInputPort( "IN" ) )
{
}

Model &TestIn::initFunction()
{
  return *this;
}

Model &TestIn::externalFunction( const ExternalMessage &msg )
{
  this->passivate();
  return *this;
}

Model &TestIn::internalFunction( const InternalMessage & )
{
  this->passivate();
  return *this;
}

Model &TestIn::outputFunction( const InternalMessage &msg )
{
  return *this;
}
