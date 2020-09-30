#ifndef __ALIGNL_H
#define __ALIGNL_H

#include <atomic.h>
#include "bits.h"

class AlignL : public Atomic
{
public:
	AlignL( const string &name = "AlignL" );					//Default constructor
	~AlignL();

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port ** OP, ** SIZE, **A, &SIGN, **RES;
	Time responseTime;
	bit op[32], size[2], a[2], sign;
	o_bit res[32];
};

inline string AlignL::className() const
{
	return "AlignL" ;
}

#endif
