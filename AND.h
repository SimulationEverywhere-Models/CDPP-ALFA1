/*******************************************************************

*

*  DESCRIPTION: Atomic Model AND

*

*  AUTHOR: Federico Petronio

*

*  EMAIL: mailto://fpetroni@dc.uba.ar

*

*  DATE: 9/7/1999

*

*******************************************************************/



#ifndef __AND_H

#define __AND_H



// #include <list>



#include "atomic.h"     // class Atomic



#include "bits.h"

class AND : public Atomic

{

public:

	AND( const string &name = "AND" );	//Default constructor



	virtual string className() const ;

protected:

	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );



private:

	const Port &INA;

	const Port &INB;

	Port &OUT;

	Time preparationTime;

	bit ina, inb;
	o_bit out;



};	// class AND



// ** inline ** //

inline

string AND::className() const

{

	return "AND" ;

}





#endif   //__AND_H

