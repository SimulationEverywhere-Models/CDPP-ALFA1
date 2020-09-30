#ifndef __TESTIN_H
#define __TESTIN_H

#include <atomic.h>

class TestIn : public Atomic
{
public:
	TestIn( const string &name = "TestIn" );					//Default constructor
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port &IN;
};

inline string TestIn::className() const
{
	return "TestIn" ;
}

#endif
