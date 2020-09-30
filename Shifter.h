/*******************************************************************
*
*  DESCRIPTION: Atomic Model SHIFTER
*
*  AUTHOR: Aureliano Calvo
*          Juan Manuel Barrionuevo
*          Andres Corvetto
*
*  EMAIL: mailto://ecalvo@dc.uba.ar
*         mailto://jbarrio@dc.uba.ar
*         mailto://acorvett@dc.uba.ar
*
*  DATE: 12/10/98
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 23/01/2000
*
*
*
*******************************************************************/

#ifndef __SHIFTER_H
#define __SHIFTER_H

#include <atomic.h>     // class Atomic
#include "bits.h"

class Shifter : public Atomic
{
public:
	Shifter( const string &name = "Shifter" );	//Default constructor

        ~Shifter();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

// Declaracion de puertos de entrada
	Port **OPA, **OPB, **FCOD, **RES;
	bit opa[32], opb[5], fcod[2];
	o_bit res[32];

	Time preparationTime; // Tiempo de respuesta del componente
	
};	// class Shifter

// ** inline ** // 
inline
string Shifter::className() const
{
	return "Shifter" ;
}

#endif   //__SHIFTER_H
