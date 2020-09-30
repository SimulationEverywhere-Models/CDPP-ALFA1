/*******************************************************************
*
*  DESCRIPTION: Model Atomico RegGlob (Bloque de registros globales)
*
*  AUTHOR: Juan Manuel Barrionuevo
*	   Aureliano Calvo
*          Andres Corvetto 
*
*  EMAIL: jbarrio@dc.uba.ar
*	  ecalvo@dc.uba.ar
*	  acorvett@dc.uba.ar
*
*  DATE: 10/10/1998
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 21/01/2000
*
*
*******************************************************************/

#ifndef __REGGLOB_H
#define __REGGLOB_H


#include <atomic.h>     // class Atomic
#include "bits.h"
class RegGlob : public Atomic
{
public:
	RegGlob( const string &name = "RegGlob" );					//Default constructor
	~RegGlob();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

	unsigned long mReg[8]; //Regs.		
	
	Port **ASEL, **BSEL, **CSEL, &CEN, &RESET, **AOUT, **BOUT, **CIN;
	bit asel[4], bsel[4], csel[4] , cin[32], cen; 
	o_bit aout[32], bout[32];
	Time preparationTime;


	
};	// class RegGlob

// ** inline ** // 
inline
string RegGlob::className() const
{
	return "RegGlob" ;
}


#endif   //__REGGLOB_H