/*******************************************************************
*
*  DESCRIPTION: Atomic Model IncDec
*
*  AUTHOR: Barletta, Patricio / Enrique, Sebastian / Rubinstein, Diego
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 15/01/2000
*
*
*******************************************************************/

#ifndef __IncDec_H
#define __IncDec_H

#include <list>

#include <atomic.h>     // class Atomic
#include "bits.h"

class IncDec : public Atomic
{
public:
        IncDec( const string &name = "IncDec" );                  //Default constructor

	~IncDec();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        Port **OP, &FCOD, **RES;
	bit op[5], fcod;
	o_bit res[5];
	Time preparationTime;
	
	
};  // class IncDec

// ** inline ** // 
inline
string IncDec::className() const
{
    return "IncDec" ;
}


#endif   //__IncDec_H
