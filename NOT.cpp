/*******************************************************************

*

*  DESCRIPTION: Atomic Model NOT

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

#include "NOT.h"      // class NOT

#include "message.h"    // class ExternalMessage, InternalMessage

#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )



/** public functions **/



/*******************************************************************

* Function Name: NOT

* Description: 

********************************************************************/

NOT::NOT( const string &name )

: Atomic( name )

, in( this->addInputPort( "in" ) )

, out( this->addOutputPort( "out" ) )

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

Model &NOT::initFunction()

{

	i = 0;

	this->holdIn( active, preparationTime );

	return *this ;

}





/*******************************************************************

* Function Name: externalFunction

* Description: 

********************************************************************/

Model &NOT::externalFunction( const ExternalMessage &msg )

{

	if( msg.port() == in )

	{

		i = static_cast< int >( msg.value());

		this->holdIn( active, preparationTime );

	}

	return *this;

}



/*******************************************************************

* Function Name: internalFunction

* Description:

********************************************************************/

Model &NOT::internalFunction( const InternalMessage & )

{

	this->passivate();

	return *this ;

}





/*******************************************************************

* Function Name: outputFunction

* Description:

********************************************************************/

Model &NOT::outputFunction( const InternalMessage &msg )

{

	this->sendOutput( msg.time(), out, !i ) ;

	return *this ;

}

