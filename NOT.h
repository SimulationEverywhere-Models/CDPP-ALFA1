/*******************************************************************

*

*  DESCRIPTION: Atomic Model NOT

*

*  AUTHOR: Federico Petronio

*

*  EMAIL: mailto://fpetroni@dc.uba.ar

*

*  DATE: 9/7/1999

*

*******************************************************************/



#ifndef __NOT_H

#define __NOT_H



// #include <list>



#include "atomic.h"     // class Atomic



class NOT : public Atomic

{

public:

	NOT( const string &name = "NOT" );	//Default constructor



	virtual string className() const ;

protected:

	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );



private:

	const Port &in;

	Port &out;

	Time preparationTime;

	int i;



};	// class NOT



// ** inline ** //

inline

string NOT::className() const

{

	return "NOT" ;

}





#endif   //__NOT_H

