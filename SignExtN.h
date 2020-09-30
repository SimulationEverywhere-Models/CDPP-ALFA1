/*******************************************************************
*
*  DESCRIPTION: Atomic Model SignExtN
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 23/01/2000
*
*
*******************************************************************/

#ifndef __SIGNEXTN_H
#define __SIGNEXTN_H


#include <atomic.h>     // class Atomic
#include "bits.h"
class SignExtN : public Atomic
{
public:
	SignExtN( const string &name = "SignExtN" );	//Default constructor

        ~SignExtN();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **OP, **RES;
	bit *op;
	o_bit res[32];
	Time preparationTime;
	int nbits;
    
};	// class SIGNEXT13

// ** inline ** // 
inline
string SignExtN::className() const
{
	return "SignExtN" ;
}


#endif   //__SIGNEXTN_H
