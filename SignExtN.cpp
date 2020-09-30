/**
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 23/01/2000
*
*

*/
/** include files **/
#include <string>

/** my include files **/
#include "SignExtN.h"      // class 
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: SignExtN
* Description: Constructor
********************************************************************/
SignExtN::SignExtN( const string &name )
: Atomic( name )
, preparationTime( 0, 0, 10, 0 )
, nbits ( defnbits )
{
    if( MainSimulator::Instance().existsParameter( this->description(),"nbits" ) )
    {
	string sBits( MainSimulator::Instance().getParameter( this->description(), "nbits" ) ) ;
        if( sBits != "" )
	    nbits = atoi(sBits.c_str()) ;

    }

    OP = addPorts(ptInput, "OP", nbits, *this);
    op = new bit [nbits];
    RES = addPorts(ptOutput, "RES", 32, *this);
    if( MainSimulator::Instance().existsParameter( this->description(),"response" ) )
    {
	string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
        if( time != "" )
	    preparationTime = time ;

    }

}
SignExtN::~SignExtN(){
    delete [] OP;
    delete [] RES;
}


/*******************************************************************
* Function Name: initFunction
* Description: 
* Precondition: 
********************************************************************/
Model &SignExtN::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &SignExtN::externalFunction( const ExternalMessage &msg )
{
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
* Description: 
********************************************************************/
Model &SignExtN::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &SignExtN::outputFunction( const InternalMessage &msg ){
    for (int i = 0; i < 32; i++) {
	if (i<(nbits-1))
	    res[i].val = op[i];
	else
	    res[i].val = op[nbits-1];
	if(needSend( res[i]))
	   this->sendOutput( msg.time(), *RES[i], res[i].val);
    }
    

return *this;
}
