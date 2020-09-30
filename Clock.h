/*******************************************************************
*								   *	
*  DESCRIPTION: Clock						   * 
*								   *	
*  AUTHOR: 	Ariel Bender		< abender@dc.uba.ar  >     *	
*		Dario Brignardello	< dbrignar@dc.uba.ar >     *
*								   *	
*  DATE: 10/10/1998						   *
*								   *	
********************************************************************/

#ifndef __Clock_H
#define __Clock_H

/** include files **/

/** my include files **/
#include <atomic.h>     // class Atomic
#include <except.h>     // class InvalidMessageException


/** forward declarations **/
class Distribution ;

/** declarations **/
class Clock : public Atomic
{
public:
	Clock( const string &name = "Clock" );				  // Default constructor
	virtual string className() const ;

protected:
	Model &initFunction() ;
	Model &externalFunction( const ExternalMessage & ) ;
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &CLCK, &STOP ;
	bool clck;
	Time periodo;

};	// class Clock

/** inline **/

inline
string Clock::className() const
{
	return "Clock" ;
}

#endif   //__Clock_H 
