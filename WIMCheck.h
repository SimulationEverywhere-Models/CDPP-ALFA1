/*******************************************************************
*
*  DESCRIPTION: Atomic Model WIMCheck
*
*  AUTHOR: Daniel Altman & Ezequiel Glinsky
*
*  EMAIL: mailto://daltman@cwanet.com
*         mailto://eglinsky@dc.uba.ar
*
*  DATE: 10/10/1998
*
*  FUNCIONALIDAD: recibe el CWP por los ports CWPX
*	y el WIM por los ports WIMXX y devuelve el 
*	bit CWP-ésimo del WIM. Esto indica si debe 
*	dispararse un trap para grabar la ventana 
*	de registros antes de usarse.
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 26/01/2000
*
*
*******************************************************************/

#ifndef __WIMCheck_H
#define __WIMCheck_H

#include <atomic.h>     // class Atomic
#include "bits.h" 

class WIMCheck : public Atomic
{
public:
	WIMCheck( const string &name = "WIMCheck" );					//Default constructor

	~WIMCheck();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	
		

	Port **CWP, **WIM, &RES;
	bit wim[32], cwp[5]; 
	
	o_bit res;
	Time preparationTime; //Stabilization time
};	//Class WIMCheck

// ** inline ** // 
inline
string WIMCheck::className() const
{
	return "WIMCheck" ;
}


#endif   //__WIMCheck_H
