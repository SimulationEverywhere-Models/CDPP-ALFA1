/*******************************************************************
*
*  DESCRIPTION: Atomic Model INC4
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

#ifndef __INC4_H
#define __INC4_H

#include <list>

#include <atomic.h>     // class Atomic
#include "bits.h"

class Inc4 : public Atomic
{
public:
	Inc4( const string &name = "Inc4" );					//Default constructor

	~Inc4();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

// Declaracion de puertos de entrada
	Port **OP, **RES;
	bit op[32];
	o_bit res[32];
	Time preparationTime; // aqui guarda cuanto tiempo tarda en hacer la suma
	
};	// class Inc4

// ** inline ** // 
inline
string Inc4::className() const
{
	return "Inc4" ;
}


#endif   //__INC4_H
