/*******************************************************************
*
*  DESCRIPTION: Atomic Model WIMCheck
*
*  AUTHOR: Daniel Altman & Ezequiel Glinsky
*
*  EMAIL: mailto://daltman@cwanet.com
*         mailto://eglinsky@dc.uba.ar
*
*  DATE: 10/10/1998
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 26/01/2000
*
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "WIMCheck.h"   // class WIMCheck
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )


/*******************************************************************
* Function Name: WIMCheck
* Description: 
********************************************************************/
WIMCheck::WIMCheck( const string &name )
: Atomic( name )
, RES( this->addOutputPort( "RES" ) )
, preparationTime( 0, 0, 0, 40 )
{
	CWP = addPorts( ptInput, "CWP", 5, *this);
	WIM = addPorts( ptInput, "WIM", 32, *this);

	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	  if( time != "" )
	    preparationTime = time ;
	}
}

WIMCheck::~WIMCheck(){
    delete [] CWP;
    delete [] WIM;
}


/*******************************************************************
* Function Name: initFunction
* Description: no hace nada
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &WIMCheck::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &WIMCheck::externalFunction( const ExternalMessage &msg )
{
        int portNum;
        string portName;
        nameNum( msg.port().name(), portName, portNum);
        if (portName == "cwp")
          cwp[portNum] = bit(msg.value());
	else
	  if (portName == "wim")
	    wim[portNum] = bit(msg.value());

	this->holdIn( active,  preparationTime);
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: pasiva el modelo
********************************************************************/
Model &WIMCheck::internalFunction( const InternalMessage & )
{
	this -> passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: muestra por el port RES el resultado del cálculo
********************************************************************/
Model &WIMCheck::outputFunction( const InternalMessage &msg )
{
	
	res.val = wim[fromBits(cwp,5)];
	if (needSend( res ))
	    this->sendOutput( msg.time(), RES, res.val ) ;
	return *this ;
}
