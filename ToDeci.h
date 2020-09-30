#ifndef __TODECI_H
#define __TODECI_H

#include <atomic.h>
#include "bits.h"

class ToDeci : public Atomic
{
public:
	ToDeci( const string &name = "ToDeci" );					//Default constructor
	~ToDeci();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port **IN, &OUT;
	Time responseTime;
	bit *in;
	int nbits;
	unsigned int out;
};

inline string ToDeci::className() const
{
	return "ToDeci" ;
}

#endif
