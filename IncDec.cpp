/*******************************************************************
*
*  DESCRIPTION: Atomic Model IncDec
*
*  AUTHOR: Grupo 3
*
*Incrementa o decrementa el valor ingresado por los cinco ports
*de entrada (OP4..0). Es circular.
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
#include "IncDec.h"     // class IncDec
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: IncDec
* Description: 
********************************************************************/
IncDec::IncDec( const string &name )
: Atomic( name )
, FCOD( this->addInputPort( "FCOD" ) )
, preparationTime( 0, 0, 10, 0 )
{
	OP = addPorts( ptInput, "OP", 5, *this );
	RES = addPorts( ptOutput, "RES", 5, *this);

	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
  	  if( time != "" )
		preparationTime = time ;
	}
}
IncDec::~IncDec(){
    delete [] OP;
    delete [] RES;

}


/*******************************************************************
* Function Name: initFunction
* Description: Inicializa los valores de los puertos en 0
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &IncDec::initFunction()
{
  this->holdIn(active, preparationTime);
  return *this ;
}


/*******************************************************************
* Function Name: externalFunction
*Description: Con FCOD=1, Si OP4..0=11111, RES4..0 <-- 00000, por circular
                            Si no, RES4..0 <-- OP4..0 + 1
              Con FCOD=0, Si OP4..0=00000, RES4..0 <-- 11111, por circular
                            RES4..0 <-- OP4..0 - 1
********************************************************************/
Model &IncDec::externalFunction( const ExternalMessage &msg )
{
    // Pregunto por el port de entrada y asigno el valor
    if( msg.port() == FCOD ) 
	fcod =  bit(msg.value());
    else {
      int portNum;
      string portName;
      nameNum( msg.port().name(), portName, portNum);
      if (portName == "op")
        op[portNum] = bit(msg.value());
    }
    this->holdIn(active, preparationTime);
    return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: Pasiva
********************************************************************/
Model &IncDec::internalFunction( const InternalMessage & )
{
    this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: Envia RES0..4 si es distinto al output anterior.
********************************************************************/
Model &IncDec::outputFunction( const InternalMessage &msg )
{
	if (fcod)
	    toBits(fromBits(op,5)+1,res,5);
	else
	    toBits(fromBits(op,5)-1,res,5);
	for(int i = 0; i < 5; i++)
	  if(needSend( res[i]))
	    this->sendOutput( msg.time() , *RES[i], res[i].val );

	return *this ;
}

