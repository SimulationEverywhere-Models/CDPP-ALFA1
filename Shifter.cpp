/*******************************************************************
*
*  DESCRIPTION: Atomic Model Shifter
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
*  DATE: 23/01/2000
*
*
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "Shifter.h"      // class Shifter
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <iostream>
/** public functions **/

/*******************************************************************
* Function Name: Shifter
* Description: Constructor
********************************************************************/
Shifter::Shifter( const string &name )
: Atomic( name )
, preparationTime( 0, 0, 10, 0) // Inicializa el tiempo de respuesta del componente
{
	OPA = addPorts(ptInput, "OPA", 32, *this);
	OPB = addPorts(ptInput, "OPB", 5, *this);
	FCOD = addPorts(ptInput, "FCOD", 2, *this);
	RES = addPorts(ptOutput, "RES", 32, *this);
	
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

	  if( time != "" )
		preparationTime = time ; 
	}
	// Si se especifica otro tiempo de respuesta, lo lee
}

Shifter::~Shifter(){
    delete [] OPA;
    delete [] OPB;
    delete [] FCOD;
    delete [] RES;
}

/*******************************************************************
* Function Name: initFunction
* Description: Inicializa el componente con todos sus valores en cero y
*  prepara una transicion interna para mandar 0 por todos los ports de salida
********************************************************************/
Model &Shifter::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Recibe la entrada y calcula la nueva salida
. Genera un evento
*              interno para mandar la salida despues del tiempo de preparacion
********************************************************************/
Model &Shifter::externalFunction( const ExternalMessage &msg )
{
	// Encuentra la entrada y guarda el cambio
    int portNum;
    string portName;
    nameNum( msg.port().name(), portName, portNum);
    if (portName == "opa")
      opa[portNum] = bit(msg.value());
    else
      if (portName == "opb")
        opb[portNum] = bit(msg.value());
      else
        if (portName == "fcod")
          fcod[portNum] = bit(msg.value());



    // Y ahora calcula la nueva salida

    // Finalmente, se pide una transicion interna para sacar el nuevo resultado

   this->holdIn( active,  preparationTime );
   return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: Como ya se hizo el output, se actualizan los valores de la
* 	       salida anterior 
con los que se acaban de mandar.
********************************************************************/
Model &Shifter::internalFunction( const InternalMessage & )
{
	
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: Emite mensajes solo por los puertos que cambiaron su valor
********************************************************************/
Model &Shifter::outputFunction( const InternalMessage &msg )
{
	switch(fromBits(fcod,2)) {
	    case 1: toBits( (fromBits(opa,32) << fromBits(opb,5)) , res , 32 );
		    break;
	    case 2: toBits( (unsigned long)(fromBits(opa,32) >> fromBits(opb,5)), res, 32);
		    break;
	    case 3: toBits( (long(fromBits(opa,32)) >> fromBits(opb,5)), res, 32);
		    break;
	}
	for(int i=0;i<32;i++)
	  if (needSend(res[i]))
	    this->sendOutput( msg.time(), *RES[i], res[i].val ) ;
	return *this ;
}