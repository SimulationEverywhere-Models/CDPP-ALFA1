/*
// Mail a cdurr@secind.mecon.ar cc computos@cbc.uba.ar
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 27/01/1999
*
*/


/** include files **/
#include <string>

/** my include files **/
#include "IRQLogic.h"      // class IRQLogic 
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: IRQLogic
* Description: Constructor
********************************************************************/
IRQLogic::IRQLogic( const string &name )
: Atomic( name )
, TF( this->addOutputPort( "TF" ) )
, preparationTime( 0, 0, 10, 0 )
{
    IRQ = addPorts( ptInput, "IRQ", 15, *this,1);
    PIL = addPorts( ptInput, "PIL", 4, *this);
    TT = addPorts( ptOutput, "TT", 8, *this);
    if(MainSimulator::Instance().existsParameter(this->description(),"response"))
	{
	string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	
	if( time != "" )
		preparationTime = time ;
	}
}

IRQLogic::~IRQLogic(){
    delete [] IRQ;
    delete [] PIL;
    delete [] TT;

}


/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &IRQLogic::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &IRQLogic::externalFunction( const ExternalMessage &msg )
{

    int portNum;
    string portName;
    nameNum( msg.port().name(), portName, portNum);
    if (portName == "irq")
      irq[portNum-1] = bit(msg.value());
    else
      if (portName == "pil")
        pil[portNum] = bit(msg.value());


    this->holdIn( active, preparationTime );
    return *this;
}


/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &IRQLogic::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &IRQLogic::outputFunction( const InternalMessage &msg )
{
    int ipil = fromBits(pil, 4);
    int i;
    for(i=15;i > ipil && !pil[i-1];i--);
    if (i != ipil) {
      tf.val = 1;
      if (needSend( tf ))
        this->sendOutput( msg.time(), TF, tf.val) ;
      toBits( 0x10 + i, tt, 8);
      for (int j=0; j < 8; j++)
        if (needSend( tt[i] ))
          this->sendOutput( msg.time(), *TT[i], tt[i].val) ;
    
    }
    return *this;
}

