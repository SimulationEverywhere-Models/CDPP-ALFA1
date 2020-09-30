/*******************************************************************
*
*  DESCRIPTION: Atomic Model Inc4
*
*  AUTHOR: Aureliano Calvo
*          Juan Manuel Barrionuevo
*          Andres Corvetto 
*
*  EMAIL: mailto://ecalvo@dc.uba.ar
*         mailto://jbarrio@dc.uba.ar
*         mailto://acorvett@dc.uba.ar
*
*  DATE: 27/6/1998
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 15/01/2000
*
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "Inc4.h"      // class Inc4
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Inc4
* Description: Constructor
********************************************************************/
Inc4::Inc4( const string &name )
: Atomic( name )
,preparationTime( 0, 0, 10, 0 ) // Inicializa el tiempo por defecto
{
	OP = addPorts(ptInput, "OP", 32, *this);
	RES = addPorts( ptOutput, "RES", 32, *this);
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
  	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

	  if( time != "" )
	    preparationTime = time ; // si hay algun otro retraso, lo lee
	}
}
Inc4::~Inc4(){
    delete [] OP;
    delete [] RES;

}


/*******************************************************************
* Function Name: initFunction
* Description: Inicializa el modelo, genera una transicion interna para 
*              generar el primer resultado
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Inc4::initFunction()
{
	this->holdIn( active, 0 );
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Recibe la entrada y calcula la nueva salida
*              genera un evento interno en el tiempo especificado por delay
********************************************************************/
Model &Inc4::externalFunction( const ExternalMessage &msg )
{
	// Encuentra la entrada y guarda el cambio
        int portNum;
        string portName;
        nameNum( msg.port().name(), portName, portNum);
        if (portName == "op")
          op[portNum] = bit(msg.value());
     	
        this->holdIn( active, preparationTime );

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: Como ya se hizo el output, guarda los nuevos valores del 
*              resultado.
********************************************************************/
Model &Inc4::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: emite mensajes por los puertos que cambiaron su valor
********************************************************************/
Model &Inc4::outputFunction( const InternalMessage &msg )
{
    toBits(fromBits(op, 32) + 4, res, 32);
    for(int i = 0;i<32;i++)
	
if ( needSend( res[i] ) )
	      this->sendOutput( msg.time(), *RES[i], res[i].val);
	      

    
    return *this ;
}
