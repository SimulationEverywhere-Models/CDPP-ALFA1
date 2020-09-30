/*******************************************************************
*
*  DESCRIPTION: Atomic Model MUX
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
*  DATE: 01/07/1999
*
*******************************************************************/

#ifndef __MUX_H
#define __MUX_H

#include <atomic.h>     // class Atomic
#include "bits.h"

class Mux : public Atomic
{
public:
	Mux( const string &name = "Mux" );	//Default constructor

	~Mux();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **OPA, **OPB, **OUT
, &SELA_SELB;
	Time responseTime; // Tiempo de respuesta del componente
	bit opa[32], opb[32], sel;
	o_bit out[32];


};	// class Mux

// ** inline ** // 
inline
string Mux::className() const
{
	return "Mux" ;
}

#endif   //__MUX_H
