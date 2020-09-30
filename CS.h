/*******************************************************************
*
*  DESCRIPTION: Atomic Model CS
*
*  AUTHOR: Ariel Bender & Dario Brignardello 
*
*  EMAIL: mailto://abender@dc.uba.ar
*         mailto://dbrignar@dc.uba.ar
*
*  DATE: 12/10/1998
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 31/01/1999
*
*
*******************************************************************/

#ifndef __CS_H
#define __CS_H

#include <stdlib.h>
#include <atomic.h>     // class Atomic
#include "bits.h"


#define DEFAULT_BOTTOM 0x0
#define DEFAULT_TOP 0xFFFFFFFF

class CS: public Atomic
{
public:
	CS( const string &name = "CS" );	//Default constructor
	~CS();
	virtual string className() const ;
	
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **A, &AS, &CS1;
	bit a[32], as;
	unsigned long bottom, top;
	o_bit cs;
	Time preparationTime;				
	
};	// class CS

// ** inline ** // 
inline
string CS::className() const
{
	return "CS" ;
}


#endif  
