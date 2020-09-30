#ifndef __FROMDECI_H
#define __FROMDECI_H

#include <atomic.h>
#include "bits.h"

class FromDeci : public Atomic
{
public:
	FromDeci( const string &name = "FromDeci" );					//Default constructor
	~FromDeci();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port &IN, ** OUT;
	Time responseTime;
	unsigned int in;
	int nbits;
	o_bit *out;
};

inline string FromDeci::className() const
{
	return "FromDeci" ;
}

#endif
