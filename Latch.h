/*******************************************************************
*
*  DESCRIPTION: Atomic Model Latch
*
*  AUTHOR: Aureliano Calvo
*          Juan Manuel Barrionuevo
*          Andres Corvetto
*
*  EMAIL: mailto://ecalvo@dc.uba.ar
*         mailto://jbarrio@dc.uba.ar
*         mailto://acorvett@dc.uba.ar
*
*  DATE: 27/6/1998
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 15/01/2000
*
*******************************************************************/

#ifndef __Latch_H
#define __Latch_H

#include <list>

#include <atomic.h>     // class Atomic
#include "bits.h"

class Latch : public Atomic
{
public:
	Latch( const string &name = "Latch" );					//Default constructor

	~Latch();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

// Declaracion de puertos de entrada
	Port **IN, &EIN, &CLEAR, **OUT;
	bit in[32], ein, clear;
	o_bit out[32];
	Time preparationTime;

	unsigned int initial;

};	// class Latch

// ** inline ** // 
inline
 string Latch::className() const
{
	return "Latch" ;
}


#endif   //__Latch_H
