#ifndef __ADDER_H
#define __ADDER_H

#include <atomic.h>
#include "bits.h"

class Adder : public Atomic
{
public:
	Adder( const string &name = "Adder" );					//Default constructor
	~Adder();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port ** OPA, ** OPB, **RES, &C;
	Time responseTime;
	bit opa[32], opb[32];
	o_bit res[32], c;
};

inline string Adder::className() const
{
	return "Adder" ;
}

#endif
