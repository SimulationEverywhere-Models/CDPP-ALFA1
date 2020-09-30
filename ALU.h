/*******************************************************************
*
*  DESCRIPTION: Atomic Model ALU
*
*  AUTHOR: Christian Durr
*          Ruben Festini
*          Diego Hereu
*          Martin Paoletta
*
*  DATE:   12/10/998
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 07/01/1999
*
*******************************************************************/

#ifndef __ALU_H
#define __ALU_H


#include <atomic.h>     // class Atomic
#include "bits.h"

class ALU : public Atomic
{
public:
	ALU( const string &name = "ALU" );	//Default constructor
	~ALU();
	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **OPA, **OPB, **FCOD, &CIN, **RES, &C, &N, &Z, &V;

	bit opa[32], opb[32], fcod[4], cin;
	o_bit res[32], carry, neg, zero, over;

	Time preparationTime;

	Time timeLeft;

};	// class ALU

// ** inline ** // 
inline
string ALU::className() const
{
	return "ALU" ;
}


#endif   //__ALU_H
