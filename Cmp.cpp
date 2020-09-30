/*---------------------------------------------------------------------------
-								   	    -
-  NOMBRE DEL MODELO: 	Cmp					   	    -
-								   	    -
-  AUTORES:	Ariel Bender 		abender@dc.uba.ar  	   	    -
-		Dario Brignardello	dbrignar@dc.uba.ar 	   	    -
-								   	    -
-  FECHA: 3/10/98						   	    -
-								   	    -
-  ESPECIFICACION GENERICA DEL COMPORTAMIENTO:			   	    -
-  Simulacion de un comparador. La comparacio'n se realiza bit a bit. Cada  -
-  operando es almacenado en un vector de 32 posiciones.		    -
-									    -
-  PORTS DE ENTRADA:	OPA0-OPA31  OPB0-OPB31			   	    -
-								   	    -
-  PORTS DE SALIDA:	EQ LW					   	    -
-								   	    -
-  dint:	So'lo pasiva el modelo.				   	    -
-								   	    -
-  dext:	Cualquier ingreso por un port de entrada pasiva el modelo,  -
-		almacena el valor ingresado ( debe ser 0 o 1 ) en un vector -
-		y activa un tiempo de preparacio'n. 			    -	
-									    -
-  lambda:	Luego de cumplido el tiempo de preparacion, se realiza la   -
-		comparacio'n de los valores de los vectores, y se emiten los-
-		resultados por los ports EQ y LW (por ambos)		    -
-									    -
-									    -
-
-  MODIFICADO POR: Pablo L. Cremona
-                  Pablo S. Sor
-
-  DATE: 31/01/1999
-
---------------------------------------------------------------------------*/

/** include files **/
#include <string>

/** my include files **/
#include "Cmp.h"      // class Cmp
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Cmp						   *	
* Description: 							   *
********************************************************************/
Cmp::Cmp( const string &name )
: Atomic( name )
, EQ( this->addOutputPort( "EQ" ) )
, LW_GT( this->addOutputPort( "LW_GT" ) )
, preparationTime( 0, 0, 10, 0 )
{
	OPA = addPorts( ptInput, "OPA", 32, *this);
	OPB = addPorts( ptInput, "OPB", 32, *this);
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	  if( time != "" )
		preparationTime = time ;
	}
}

Cmp::~Cmp()
{
  delete [] OPA;
  delete [] OPB;
}



/*******************************************************************
* Function Name: initFunction					   *	
* Description: 	Inicializa los arreglos temporales.		   *	
* Precondition: El tiempo del proximo evento interno es Infinito   *	
********************************************************************/
Model &Cmp::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction				   *	
* Description: 							   *
********************************************************************/
Model &Cmp::externalFunction( const ExternalMessage &msg )
{
        int portNum;
        string portName;
        nameNum( msg.port().name(), portName, portNum);
        if (portName == "opa") 
          opa[portNum] = bit(msg.value());
	else 
          if (portName == "opb")
	    opb[portNum] = bit(msg.value());

	this->holdIn( active, preparationTime );

	return *this;
}

/*******************************************************************
* Function Name: internalFunction				   *  
* Description: 							   *
********************************************************************/
Model &Cmp::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction					   *	
* Description: 							   *	
********************************************************************/
Model &Cmp::outputFunction( const InternalMessage &msg )
{
	
	eq.val = 1;
	for( int i = 31; i >= 0 && eq.val; i-- )
	    {
	    eq.val = ( opa[i] == opb[i] ) ;
	    lw_gt.val = ( opa[i] < opb[i] ) ;
	    }
	if (needSend( eq ))
            this->sendOutput( msg.time(), EQ, eq.val ) ;
	if (needSend( lw_gt ))
	    this->sendOutput( msg.time(), LW_GT, lw_gt.val ) ;
	return *this ;
}
