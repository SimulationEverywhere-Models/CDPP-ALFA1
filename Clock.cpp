/*---------------------------------------------------------------------------
-								   	    -
-  NOMBRE DEL MODELO: 	Clock					   	    -
-								   	    -
-  AUTORES:	Ariel Bender 		abender@dc.uba.ar  	   	    -
-		Dario Brignardello	dbrignar@dc.uba.ar 	   	    -
-								   	    -
-  FECHA: 28/10/98						   	    -
-								   	    -
-  ESPECIFICACION GENERICA DEL COMPORTAMIENTO:	Simulacion de un Clock. El  -
-  periodo del mismo es configurable mediante el parametro 'periodo' del    -
-  archivo del modelo atomico.						    -	
-									    -
-  PORTS DE ENTRADA:	-					   	    -
-								   	    -
-  PORTS DE SALIDA:	CLCK					   	    -
-								   	    -
-  dint:	Mantiene el modelo activo durante 'periodo'	   	    -
-								   	    -
-  dext:	-							    -
-									    -
-  lambda:	Se emite un '1' por el port CLCK			    -
-									    -
-
-
-  MODIFICADO POR: Pablo L. Cremona
-                  Pablo S. Sor
-
-  DATE: 30/01/1999
-
---------------------------------------------------------------------------*/

/** my include files **/
#include "Clock.h"         // base header
#include <message.h>       // class InternalMessage 
#include <mainsimu.h>      // class Simulator

/** public functions **/

/*******************************************************************
* Function Name: Clock
* Description: constructor
********************************************************************/
Clock::Clock( const string &name )
: Atomic( name )
, CLCK( this->addOutputPort( "CLCK" ) )
, STOP( this->addInputPort( "STOP" ) )
, periodo( 0, 0, 10, 0 )           
{
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) { 
   	  string in_period( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	  if( in_period != "" )
		periodo = in_period ;
	}

}

/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &Clock::initFunction()
{
	this->holdIn( active, Time::Zero ) ;
	return *this ;
}

Model &Clock::externalFunction( const ExternalMessage &msg )
{
  this->passivate();
  return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Clock::internalFunction( const InternalMessage & )
{
	this->holdIn( active, periodo );
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Clock::outputFunction( const InternalMessage &msg )
{
	clck = !clck; 
	this->sendOutput( msg.time(), CLCK, clck ) ;
	return *this ;
}
