/*******************************************************************

*

*  DESCRIPTION: Atomic Model AND

*

*  AUTHOR: Federico Petronio

*

*  EMAIL: mailto://fpetroni@dc.uba.ar

*

*  DATE: 9/7/1999

*

*******************************************************************/



/** include files **/

#include <string>



/** my include files **/

#include "AND.h"      // class AND

#include "message.h"    // class ExternalMessage, InternalMessage

#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )



/** public functions **/



/*******************************************************************

* Function Name: AND

* Description: 

********************************************************************/

AND::AND( const string &name )

: Atomic( name )

, INA( this->addInputPort( "INA" ) )

, INB( this->addInputPort( "INB" ) )

, OUT( this->addOutputPort( "OUT" ) )

, preparationTime( 0, 0, 10, 0 )

{

	string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;



	if( time != "" )

		preparationTime = time ;

}







/*******************************************************************

* Function Name: initFunction

* Description: Limpia los valores en las entradas

* Precondition: El tiempo del proximo evento interno es Infinito

********************************************************************/

Model &AND::initFunction()

{

	return *this ;

}





/*******************************************************************

* Function Name: externalFunction

* Description: 

********************************************************************/

Model &AND::externalFunction( const ExternalMessage &msg )

{

	if( msg.port() == INA )

	{

		ina = bit( msg.value() );

		this->holdIn( active, preparationTime );

	}

	if( msg.port() == INB )

	{

		inb = bit( msg.value() );

		this->holdIn( active, preparationTime );

	}

	return *this;

}



/*******************************************************************

* Function Name: internalFunction

* Description:

********************************************************************/

Model &AND::internalFunction( const InternalMessage & )

{

	this->passivate();

	return *this ;

}





/*******************************************************************

* Function Name: outputFunction

* Description:

********************************************************************/

Model &AND::outputFunction( const InternalMessage &msg )

{

  out.val = ina & inb;
  if( needSend( out ) )
    this->sendOutput( msg.time(), OUT, out.val ) ;

  return *this ;

}

