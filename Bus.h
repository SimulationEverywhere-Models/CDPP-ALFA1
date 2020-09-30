#ifndef __BUS_H
#define __BUS_H

#include <atomic.h>
#include "bits.h"

class Bus : public Atomic
{
public:
	Bus( const string &name = "Bus" );					//Default constrBustor
	~Bus();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port **IN, **OUT;
	o_bit *out;
	Time responseTime;
	int numports;
};

inline string Bus::className() const
{
	return "Bus" ;
}

#endif
