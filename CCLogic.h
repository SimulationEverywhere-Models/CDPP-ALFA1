/*******************************************************************
*
*  DESCRIPTION: Atomic Model CCLogic
*
*  AUTHOR: Deborah Grinberg & Marcos Nu�ez Cort�s
*
*  EMAIL: mailto://dgrinber@dc.uba.ar
*         mailto://jnuniez@dc.uba.ar
*
*  DATE: 27/9/1998
*
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 28/01/1999
*
*******************************************************************/

#ifndef __CCLOGIC_H
#define __CCLOGIC_H

#include <list>

#include "bits.h"
#include <atomic.h>     // class Atomic

class CCLogic : public Atomic
{
public:
        CCLogic( const string &name = "CCLogic" );                                  //Default constructor
	~CCLogic();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        Port &C, &N, &Z, &V
, **COND, &RES;      
	Time preparationTime;
        bit c,n,z,v,cond[4];
	o_bit res;



};      // class CCLogic

// ** inline ** // 
inline
string CCLogic::className() const
{
        return "CCLogic" ;
}


#endif   //__CCLOGIC_H
