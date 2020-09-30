/*******************************************************************
*
*  DESCRIPTION: Atomic Model AlignS
*
*  AUTHOR: Deborah Grinberg & Marcos Nu¤ez Cort‚s
*
*  EMAIL: mailto://dgrinber@dc.uba.ar
*         mailto://jnuniez@dc.uba.ar
*
*  DATE: 27/9/1998
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 07/01/1999
*
*******************************************************************/

#ifndef __ALIGNS_H
#define __ALIGNS_H

#include <list>

#include <atomic.h>     // class Atomic
#include "bits.h" 

class AlignS : public Atomic
{
public:
        AlignS( const string &name = "AlignS" );   //Default constructor

	~AlignS();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        // Palabras de entrada
	Port  **OP, **RES, **BSEL, &SIZE0, &SIZE1, &A0, &A1;

        Time preparationTime;
	bit op[32], size0, size1, a0, a1;
	o_bit res[32], bsel[4];
	

};      // class AlignS

// ** inline ** // 
inline
string AlignS::className() const
{
        return "AlignS" ;
}


#endif   //__ALIGNS_H
