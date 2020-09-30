#ifndef __UCTEST_H
#define __UCTEST_H

#include <atomic.h>
#include "bits.h"

class UCTest : public Atomic
{
public:
	UCTest( const string &name = "UCTest" );					//Default constructor
	~UCTest();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port &CLCK, &DTACK, &END, **OUT;
	bit off, end, waitfmc;
	o_bit *out;
	int fase;
};

inline string UCTest::className() const
{
	return "UC" ;
}

#endif
