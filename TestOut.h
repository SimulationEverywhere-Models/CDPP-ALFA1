#ifndef __TESTOUT_H
#define __TESTOUT_H

#include <atomic.h>

class TestOut : public Atomic
{
public:
	TestOut( const string &name = "TestOut" );					//Default constructor
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port &OUT0, &OUT1;
};

inline string TestOut::className() const
{
	return "TestOut" ;
}

#endif
