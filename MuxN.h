#ifndef __MUXN_H
#define __MUXN_H

#include <atomic.h>
#include "bits.h"

class MuxN : public Atomic
{
public:
	MuxN( const string &name = "MuxN" );					//Default constructor
	~MuxN();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port *** IN, ** SEL, ** OUT;
	Time responseTime;
	bit **in;
	int nbits, nports, sel;
	o_bit *out;
};

inline string MuxN::className() const
{
	return "MuxN" ;
}

#endif
