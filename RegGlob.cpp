/*******************************************************************
*
*  DESCRIPTION: Modelo Atomico RegGlob (Bloque de registros globales)
*
*  AUTHOR:  Juan Manuel Barrionuevo
*	    Aureliano Calvo
*	    Andres Corvetto
*
*  EMAIL: jbarrio@dc.uba.ar
*	  ecalvo@dc.uba.ar
*	  acorvett@dc.uba.ar
*
*  DATE: 10/10/1998
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 21/01/2000
*
*
*******************************************************************/

/** include files **/
#include <string>
#include <iostream>

/** my include files **/
#include "RegGlob.h"    // class RegGlob
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: RegGlob
* Description: 
********************************************************************/
RegGlob::RegGlob( const string &name )
: Atomic( name )
, CEN( this->addInputPort( "CEN" ) )
, RESET( this->addInputPort( "RESET" ) )
, preparationTime( 0, 0, 0, 40 )
{
	ASEL = addPorts( ptInput, "ASEL", 4, *this );
	BSEL = addPorts( ptInput, "BSEL", 4, *this );
	CSEL = addPorts( ptInput, "CSEL", 4, *this );
	AOUT = addPorts( ptOutput, "AOUT", 32, *this);
	BOUT = addPorts( ptOutput, "BOUT", 32, *this);
	CIN = addPorts( ptInput, "CIN", 32, *this);
	
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {

	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

	  if( time != "" )
	    preparationTime = time ;
	}


}		
RegGlob::~RegGlob(){
  delete [] ASEL;
  delete [] BSEL;
  delete [] CSEL;
  delete [] AOUT;
  delete [] BOUT;
  delete [] CIN;
}


/*******************************************************************
* Function Name: initFunction
* Description: Resetea los registros y las variables internas
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &RegGlob::initFunction()
{
	for(int i=0;i<8;i++)
	    mReg[i] = 0;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Modifica las variables internas dependiendo del port. 
* 	       Cada evento nuevo inicia un nuevo conteo de duracion delay.
********************************************************************/
Model &RegGlob::externalFunction( const ExternalMessage &msg )
{
	if (msg.port() == RESET)
	  for(int i = 0; i < 8;i++)
	    mReg[i] = 0;
	else
	  if (msg.port() == CEN)
	    cen = bit(msg.value())
;
	  else {
            int portNum;
	    string portName;
	    nameNum( msg.port().name(), portName, portNum);
	    if (portName == "asel")
	      asel[portNum] = bit(msg.value());
	    else
	      if (portName == "bsel")
	        bsel[portNum] = bit(msg.value());
	      else
	        if (portName == "csel")
	          csel[portNum] = bit(msg.value());
	        else
		  if (portName == "cin")
	             cin[portNum] = bit(msg.value());

	  }

	this->holdIn( active,  preparationTime );
 	return *this;

}

/*******************************************************************
* Function Name: internalFunction
* Description: Hace los cambios internos
	       correspondientes y pasiva el modelo.
********************************************************************/
Model &RegGlob::internalFunction( const InternalMessage &msg )
{
	this->passivate();
	
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description:  Cuando no quedan delays pendientes, emite solo los bits 
		que cambiaron desde la ultima salida. 
********************************************************************/
Model &RegGlob::outputFunction( const InternalMessage &msg )
{
    	if (cen)
	  mReg[fromBits(csel, 4)] = fromBits(cin, 32);
	toBits((fromBits(asel,4) > 0)?mReg[fromBits(asel,4)]:0,aout,32); 
	toBits((fromBits(bsel,4) > 0)?mReg[fromBits(bsel,4)]:0,bout,32); 
	for(int i=0;i<32;i++) {
	    if(needSend(aout[i]))    
		this->sendOutput( msg.time(), *AOUT[i], aout[i].val ) ;
	    if(needSend(bout[i]))    
		this->sendOutput( msg.time(), *BOUT[i], bout[i].val ) ;

	}

	return *this ;
}
