/*******************************************************************
*
*  DESCRIPTION: Atomic Model IRQLogic
*
*  AUTHOR: Christian Durr
*          Ruben Festini
*          Diego Hereu
*          Martin Paoletta
*
*  DATE:   00/10/998
*
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 27/01/1999
*
*******************************************************************/

#ifndef __IRQLOGIC_H
#define __IRQLOGIC_H


#include <atomic.h>     // class Atomic
#include "bits.h"
class IRQLogic : public Atomic
{
public:
	IRQLogic( const string &name = "IRQLogic" );	//Default constructor
	~IRQLogic();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port **IRQ, **PIL, &TF, **TT;
	
bit irq[15], pil[4];
	o_bit tf, tt[8];
		
	Time preparationTime;

	
};	// class IRQLOGIC

// ** inline ** // 
inline
string IRQLogic::className() const
{
	return "IRQLogic" ;
}


#endif   //__IRQLOGIC_H
