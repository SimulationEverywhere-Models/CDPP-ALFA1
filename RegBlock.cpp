/*******************************************************************
*
*  DESCRIPTION: Atomic Model RegBlock
*
*  AUTHOR: Daniel Altman & Ezequiel Glinsky
*
*  EMAIL: mailto://daltman@cwanet.com
*         mailto://eglinsky@dc.uba.ar
*
*  DATE: 10/10/1998
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

/** my include files **/
#include "RegBlock.h"   // class RegBlock
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )


/*******************************************************************
* Function Name: RegBlock
* Description: 
********************************************************************/
RegBlock::RegBlock( const string &name )
: Atomic( name )
, CEN( this->addInputPort( "CEN" ) )
, RESET( this->addInputPort( "RESET" ) )
, preparationTime( 0, 0, 0, 40 )
{
	ASEL = addPorts( ptInput, "ASEL", 9, *this );
	BSEL = addPorts( ptInput, "BSEL", 9, *this );
	CSEL = addPorts( ptInput, "CSEL", 9, *this );
	AOUT = addPorts( ptOutput, "AOUT", 32, *this);
	BOUT = addPorts( ptOutput, "BOUT", 32, *this);
	CIN = addPorts( ptInput, "CIN", 32, *this);
	
	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {

	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

	  if( time != "" )
	    preparationTime = time ;
	}
}


RegBlock::~RegBlock() {
  delete [] ASEL;
  delete [] BSEL;
  delete [] CSEL;
  delete [] AOUT;
  delete [] BOUT;
  delete [] CIN;
}

/*******************************************************************
* Function Name: initFunction
* Description: no hace nada
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &RegBlock::initFunction()
{
	for(int i=0;i<512;i++)
	    mReg[i] = 0;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &RegBlock::externalFunction( const ExternalMessage &msg )
{

	if (msg.port() == RESET)
		this->reset();
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
* Description: pasiva el modelo
********************************************************************/
Model &RegBlock::internalFunction( const InternalMessage & )
{

	this -> passivate();


	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: muestra por el port RES el resultado del cálculo
********************************************************************/
Model &RegBlock::outputFunction( const InternalMessage &msg )
{
	if (cen)
	  mReg[fromBits(csel, 9)] = fromBits(cin, 32);

	toBits(mReg[fromBits(asel,9)],aout,32); 
	toBits(mReg[fromBits(bsel,9)],bout,32); 
	for(int i=0;i<32;i++) {
	    if(needSend(aout[i])) {
		this->sendOutput( msg.time(), *AOUT[i], aout[i].val ) ;

		}
	    if(needSend(bout[i]))   
		this->sendOutput( msg.time(), *BOUT[i], bout[i].val ) ;
	    

	}

	return *this ;
}

void RegBlock::reset(){
    for (int i = 0; i < 512; i++)
      mReg[i] = 0;
}