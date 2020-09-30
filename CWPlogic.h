/*******************************************************************

*

*  DESCRIPTION: Atomic Model CWPlogic

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
*  DATE: 31/01/2000
*
*

*******************************************************************/



#ifndef __CWPLOGIC_H

#define __CWPLOGIC_H



#include <atomic.h>     // class Atomic

#include "bits.h"


class CWPlogic : public Atomic

{

public:

	CWPlogic( const string &name = "CWPlogic" );					//Default constructor

	~CWPlogic();

	virtual string className() const ;

protected:

	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );



private:

	Port **CWP, **SEL, **GSEL, **RSEL, &R_G;
	Time preparationTime;

	bit cwp[5], sel[5];

	o_bit gsel[3], rsel[9], r_g;


};	// class CWPlogic



// ** inline ** // 

inline

string CWPlogic::className() const

{

	return "CWPlogic" ;

}





#endif   //__CWPLOGIC_H

