/*******************************************************************
*
*  DESCRIPTION: Atomic Model Mux
*
*  AUTHOR: Aureliano Calvo
*          Juan Manuel Barrionuevo
*          Andres Corvetto 
*
*  EMAIL: mailto://ecalvo@dc.uba.ar
*         mailto://jbarrio@dc.uba.ar
*         mailto://acorvett@dc.uba.ar
*
*  DATE: 12/10/1998
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 07/01/1999
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "Mux.h"      // class Mux
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Mux
* Description: Constructor
********************************************************************/
Mux::Mux( const string &name )
: Atomic( name )
, SELA_SELB( this->addOutputPort( "SELA_SELB" ) )
 // Incializa el puerto Select
, responseTime( 0, 0, 10, 0 ) // Inicializa el tiempo de respuesta del componente
{
	OPA = addPorts( ptInput, "A", 32, *this);
	OPB = addPorts( ptInput, "B", 32, *this);
	OUT = addPorts( ptOutput, "OUT", 32, *this);

	if (MainSimulator::Instance().existsParameter(this->description(),"response")) {
	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	  if( time != "" )
	    responseTime = time ; 
	} 

}


Mux::~Mux() {

    delete [] OPA;
    delete [] OPB;
    delete [] OUT;

}

/*******************************************************************
* Function Name: initFunction
* Description: 
*  Prepara una transicion interna para mandar la primera salida.
********************************************************************/
Model &Mux::initFunction()
{
    return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Recibe la entrada y calcula la nueva salida
.
*              Genera un evento interno en el tiempo especificado por delay
.
********************************************************************/
Model &Mux::externalFunction( const ExternalMessage &msg )
{
    //Ponego el bit de seleccion segun corresponda. 
    if( msg.port() == SELA_SELB )
 
        sel = bit( msg.value() );
    else {
	string portName;
	int portNum;
	nameNum( msg.port().name(), portName, portNum);
	if (portName == "a")
	    opa[portNum] = bit( msg.value());
	else
	    opb[portNum] = bit(msg.value());
    }

    // Pide una transicion interna para sacar el nuevo resultado
    holdIn( active, responseTime );

    return *this;

}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Mux::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: Emite mensajes solo por los puertos que cambiaron su valor
********************************************************************/
Model &Mux::outputFunction( const InternalMessage &msg )
{
      for (int i = 0; i < 32; i++) {
        out[i].val = (sel) ? opa[i] : opb[i];
	if ( needSend( out[i] ) )
	    this->sendOutput ( msg.time(), *OUT[i], out[i].val);
      
        }
	return *this ;
}
