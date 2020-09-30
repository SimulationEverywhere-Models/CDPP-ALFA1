/*******************************************************************
*
*  DESCRIPTION: Atomic Model TrapLogic
*
*  AUTHOR: Daniel Altman & Ezequiel Glinsky
*
*  EMAIL: mailto://daltman@cwanet.com
*         mailto://eglinsky@dc.uba.ar
*
*  DATE: 10/10/1998
*
*  FUNCIONALIDAD: indica qué interrupción debe atenderse según
*	su prioridad
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 28/01/1999
*
*
*******************************************************************/

#ifndef __TrapLogic_H
#define __TrapLogic_H

#include <atomic.h>     // class Atomic
#include "bits.h"
class TrapLogic : public Atomic
{
public:
	TrapLogic( const string &name = "TrapLogic" );	//Default constructor
	~TrapLogic();	
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	

	

	

	//Auxiliary functions	
	int getTrapIndexFromTrapName(const string &sTrapName) const;
	int getTrapTypeFromTrapIndex(const int iIndex) const;
	int getHighestPriorityTrapIndex();
	int getNumberFromString( const string& sSource, const unsigned int iStartPos ) const;


	Port &INST_ACC_EXCEP;
	Port &ILLEG_INST; 
	Port &PRIV_INST; 
	Port &WIN_OVER; 
	Port &WIN_UNDER; 
	Port &ADDR_NOT_ALIGN;
	Port &DATA_ACC_EXCEP; 
	Port &INST_ACC_ERR;
	Port &DATA_ACC_ERR;
	Port &DIV_ZERO;
	Port &DATA_ST_ERR;
	Port &TRAP_INST;
	Port **TN, &TF, **TT;

	bit tn[7], trap[12];
	o_bit tf, tt[8];



	//Output ports
	Time preparationTime; //Stabilization time


};	// class TrapLogic

// ** inline ** // 
inline
string TrapLogic::className() const
{
	return "TrapLogic" ;
}


#endif   //__TrapLogic_H
