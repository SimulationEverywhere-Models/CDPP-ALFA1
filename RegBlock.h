/*******************************************************************
*
*  DESCRIPTION: Atomic Model RegBlock
*
*  AUTHOR: Daniel Altman & Ezequiel Glinsky
*
*  EMAIL: mailto://daltman@cwanet.com
*         mailto://eglinsky@dc.uba.ar
*
*  DATE: 10/10/1998
*
*  FUNCIONALIDAD: ventana de registros
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

#ifndef __RegBlock_H
#define __RegBlock_H

#include <atomic.h>     // class Atomic
#include "bits.h"

class RegBlock : public Atomic
{
public:
	RegBlock( const string &name = "RegBlock" );	//Default constructor
	~RegBlock();	
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	
	unsigned long mReg[512]; //Regs.		
	
	Port **ASEL, **BSEL, **CSEL, &CEN, &RESET, **AOUT, **BOUT, **CIN;
	bit asel[9], bsel[9], csel[9] , cin[32], cen; 
	o_bit aout[32], bout[32];
	Time preparationTime;

	//Auxiliary functions	
	void reset();
	

};	// class RegBlock

// ** inline ** // 
inline
string RegBlock::className() const
{
	return "RegBlock" ;
}


#endif   //__RegBlock_H
