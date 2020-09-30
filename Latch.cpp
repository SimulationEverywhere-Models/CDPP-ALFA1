/*******************************************************************
*
*  DESCRIPTION: Atomic Model Latch
*
*  AUTHOR: Mario Bergotto & Tomas Heredia 

*

*  EMAIL: mailto://mbergott@dc.uba.ar

*         mailto://theredia@dc.uba.ar,tomas@intermedia.com.ar

*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 18/01/2000
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "Latch.h"      // class Latch
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <iostream.h>
/** public functions **/

/*******************************************************************
* Function Name: Latch
* Description: Constructor
********************************************************************/
Latch::Latch( const string &name )
: Atomic( name )
, EIN( this->addInputPort( "EIN" ) )
, CLEAR( this->addInputPort( "CLEAR" ) )
,preparationTime( 0, 0, 10, 0 ) // Inicializa el tiempo por defecto
{
	IN = addPorts(ptInput, "IN", 32, *this);
	OUT = addPorts(ptOutput, "OUT", 32, *this);
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
  	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	  if( time != "" )
	    preparationTime = time ; // si hay algun otro retraso, lo lee
	}
	if (MainSimulator::Instance().existsParameter( this->description(), "initial") ) {
	  string ini( MainSimulator::Instance().getParameter( this->description(), "initial" ) );
	  if (ini != "")
	    initial = atoi( ini.c_str() );
	}
}
Latch::~Latch(){
    delete [] IN;
    delete [] OUT;

}


/*******************************************************************
* Function Name: initFunction
* Description: Inicializa el modelo, genera una transicion interna para 
*              generar el primer resultado
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Latch::initFunction()
{
  if( initial ) {
    toBits( initial, out );
    this->holdIn( active, 0 );
  }
  return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Recibe la entrada y calcula la nueva salida
*              genera un evento interno en el tiempo especificado por delay
********************************************************************/
Model &Latch::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == EIN )

 {

		ein = bit(msg.value());

	}
	else
 {
	    if( msg.port() == CLEAR )

	    {

		clear = bit(msg.value())
;
	    }
	
	    else {
	      int portNum;
	      string portName;
	      nameNum( msg.port().name(), portName, portNum);
	      if (portName == "in")
	        in[portNum] = bit(msg.value());
	    }
	}

	this->holdIn( active, preparationTime );

	return *this;


}

/*******************************************************************
* Function Name: internalFunction
* Description: Como ya se hizo el output, guarda los nuevos valores del 
*              resultado.
********************************************************************/
Model &Latch::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: emite mensajes por los puertos que cambiaron su valor
********************************************************************/
Model &Latch::outputFunction( const InternalMessage &msg )
{
    


    if (clear) 
      for(int i = 0; i < 32; i++)
	out[i].val = 0;
    
    else
	if (ein) 
	    for(int i = 0; i < 32; i++)
	      out[i].val = in[i];
      
    for(int i = 0;i<32;i++)
	
if ( needSend( out[i] ) )
	      this->sendOutput( msg.time(), *OUT[i], out[i].val);
	      

    
    return *this ;
}
