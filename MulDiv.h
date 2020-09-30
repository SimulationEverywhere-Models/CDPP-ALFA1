/*******************************************************************
*
*  DESCRIPTION: Atomic Model MulDiv
*
*  AUTHOR: Mario Bergotto & Tomas Heredia 
*
*  EMAIL: mailto://mbergott@dc.uba.ar
*         mailto://theredia@dc.uba.ar,tomas@intermedia.com.ar
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 14/02/2000
*
*
* Nota: Ya que el simulador requiere GCC, vamos a operar con un
* feature del gcc: long long integers
*******************************************************************/

#ifndef __MULDIV_H
#define __MULDIV_H

#include <atomic.h>     // class Atomic
#include "bits.h"            // class bit, o_bit
class MulDiv : public Atomic
{
public:
	MulDiv( const string &name = "MulDiv" );					//Default constructor
	~MulDiv();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **OPA, **OPB, **YIN, **YOUT, **FCOD, **RES, &N, &Z, &V, &DIV_ZERO;
	bit opa[32], opb[32], yin[32], fcod[2];
	o_bit yout[32], res[32], n, z, v, div_zero;
	Time preparationTime;
	



};	// class MulDiv

// ** inline ** // 
inline
string MulDiv::className() const
{
	return "MulDiv" ;
}


#endif   //__MULDIV_H
