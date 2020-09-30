/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cmp
*
*  AUTHOR: Ariel Bender & Dario Brignardello 
*
*  EMAIL: mailto://abender@dc.uba.ar
*         mailto://dbrignar@dc.uba.ar
*
*  DATE: 3/10/1998
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 31/01/1999
*
*******************************************************************/

#ifndef __Cmp_H
#define __Cmp_H

#include <atomic.h>     // class Atomic
#include "bits.h"

class Cmp: public Atomic
{
public:
	Cmp( const string &name = "Cmp" );	//Default constructor
	~Cmp();
	virtual string className() const ;
	
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **OPA, **OPB, &EQ, &LW_GT;

	bit opa[32], opb[32]; 
	o_bit eq, lw_gt;
	Time preparationTime;				
	
};	// class Cmp

// ** inline ** // 
inline
string Cmp::className() const
{
	return "Cmp" ;
}


#endif  
