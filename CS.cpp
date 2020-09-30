/*---------------------------------------------------------------------------
-								   	    -
-  NOMBRE DEL MODELO: 	CS					   	    -
-								   	    -
-  AUTORES:	Ariel Bender 		abender@dc.uba.ar  	   	    -
-		Dario Brignardello	dbrignar@dc.uba.ar 	   	    -
-								   	    -
-  FECHA: 10/10/98						   	    -
-								   	    -
-  ESPECIFICACION GENERICA DEL COMPORTAMIENTO: Determina si una direccio'n  - 
-  se encuentra en un rango dado. El rango debe ser especificado en el      -
-									    -
-  PORTS DE ENTRADA:	A0-A31  AS				   	    - 
-								   	    -
-  PORTS DE SALIDA:	CS1					   	    -
-								   	    -
-  dint:	So'lo pasiva el modelo.				   	    -
-								   	    -
-  dext:	Cualquier ingreso por un port de entrada pasiva el modelo,  -
-		almacena el valor ingresado ( debe ser 0 o 1 ) en un vector -
-		y activa un tiempo de preparacio'n. 			    -	
-									    -
-  lambda:	Luego de cumplido el tiempo de preparacion, se realiza la   -
-		comparacio'n de los valores de los vectores, y se emiten los-
-		resultados por el port CS1		    		    - 
-									    - 
-
-  MODIFICADO POR: Pablo L. Cremona
-                  Pablo S. Sor
-
-  DATE: 31/01/1999
-
-
---------------------------------------------------------------------------*/

/** include files **/
#include <string>

/** my include files **/
#include "CS.h"      	// class CS
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )


/** private functions **/

unsigned long string2long( string source);


/** public functions **/

/*******************************************************************
* Function Name: CS						   *	
* Description: 							   *
********************************************************************/
CS::CS( const string &name ) : Atomic( name )
, AS( this->addInputPort( "AS" ) )
, CS1( this->addOutputPort( "CS" ) )
, bottom( DEFAULT_BOTTOM )
, top( DEFAULT_TOP )
, preparationTime( 0, 0, 10, 0 )
{

	A = addPorts( ptInput, "A", 32, *this);
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
   	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

  	  if( time != "" )
	    preparationTime = time ;

	
}
	if (MainSimulator::Instance().existsParameter( this->description(), "bottom")) {
	   string in_bottom( MainSimulator::Instance().getParameter( this->description(), "bottom" ) ) ;
    	   if( in_bottom != "" )
	     bottom = strtoul(in_bottom.c_str(), (char**)NULL, 0);
	}
	if (MainSimulator::Instance().existsParameter( this->description(), "top")) {
	  string in_top( MainSimulator::Instance().getParameter( this->description(), "top" ) ) ;
	  if( in_top != "" )
            top = strtoul(in_top.c_str(), (char**)NULL, 0);
;
	}
			
}

CS::~CS()
{
    delete [] A;    
}


/*******************************************************************
* Function Name: initFunction					   *	
* Description: 	Inicializa las variables temporales.		   *	
* Precondition: El tiempo del proximo evento interno es Infinito   *	
********************************************************************/
Model &CS::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction				   *	
* Description: 							   *
********************************************************************/
Model &CS::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == AS )
 	{
	    as = bit(msg.value());
	}
	else {
	    int portNum;
	    string portName;
	    nameNum( msg.port().name(), portName, portNum);
	    if (portName == "a")
	      a[portNum] = bit(msg.value());
	}
	
	this->holdIn( active, preparationTime );

	return *this;
}

/*******************************************************************
* Function Name: internalFunction				   *  
* Description: 							   *
********************************************************************/
Model &CS::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this;
}


/*******************************************************************
* Function Name: outputFunction					   *	
* Description: 							   *	
********************************************************************/
Model &CS::outputFunction( const InternalMessage &msg )
{
	unsigned long atmp = fromBits(a, 32);
	cs.val = as && (bottom <= atmp) && (atmp <= top);
	if (needSend( cs ))
	    this->sendOutput( msg.time(), CS1, cs.val ) ;
	return *this ;

}



