/**************************************************************
*
*   DESCRIPTION: Atomic model ALU
* 
*   AUTHOR: Christian Durr
*           Ruben Festini
*           Diego Hereu
*           Martin Paoletta
*
*   DATE:   12/10/98
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 07/01/1999
*
**************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "ALU.h"      	// class ALU
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )



#define ADD  0
#define AND  1
#define OR   2
#define XOR  3
#define SUB  4
#define ANDN 5
#define ORN  6
#define XNOR 7
#define ADDX 8
#define SUBX 12



/** public functions **/

/*******************************************************************
* Function Name: ALU
* Description: Constructor
********************************************************************/
ALU::ALU( const string &name )
: Atomic( name )
, CIN( this->addInputPort( "CIN" ) )
, C( this->addOutputPort( "C" ) )
, N( this->addOutputPort( "N" ) )
, Z( this->addOutputPort( "Z" ) )
, V( this->addOutputPort( "V" ) )
, preparationTime( 0, 0, 10, 0 ) 

{
    OPA = addPorts( ptInput, "OPA", 32, *this);
    OPB = addPorts( ptInput, "OPB", 32, *this);
    FCOD = addPorts( ptInput, "FCOD", 4, *this);    
    RES = addPorts( ptOutput, "RES", 32, *this);
    if( MainSimulator::Instance().existsParameter( this->description(),"response" ) )
    {
	string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	if( time != "" )
		preparationTime = time ;
    }

}
ALU::~ALU() 
{
    delete [] OPA;
    delete [] OPB;
    delete [] FCOD;
    delete [] RES;
}


/*******************************************************************
* Function Name: initFunction
* Description: 
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &ALU::initFunction()
{
	cin = 0;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Recibe un valor en un port de entrada y lo pone en el arreglo o
  la variable que corresponde
********************************************************************/
Model &ALU::externalFunction( const ExternalMessage &msg )
{
    if(msg.port() == CIN)
      {cin = bit( msg.value()) ;}
    else
      {
      string portName;
      int portNum;
      nameNum(msg.port().name(), portName, portNum);
      if(portName == "opa")
	opa[portNum] = bit( msg.value() );
      if(portName == "opb")
    	opb[portNum] = bit( msg.value() );
      if(portName == "fcod")
	fcod[portNum] = bit( msg.value() );
      }
    this->holdIn( active, preparationTime );

    return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &ALU::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: Decide, de acuerdo al FCOD actual, cual es la operacion a 
  realizar, la ejecuta y envia el resultado por los ports RES, y si corresponde,
  los cambios de estado (carry y/o overflow)
********************************************************************/
Model &ALU::outputFunction( const InternalMessage &msg )
{

    
    long iopa, iopb;
    long long r;
    iopa = fromBits(opa, 32);
    iopb = fromBits(opb, 32);

    unsigned long ifcod = fromBits(fcod,4);
    int i;

    switch(ifcod)
    {
		case  ADD: r = iopa+iopb;     break;
		case  AND: r = iopa&iopb;     break;
		case   OR: r = iopa|iopb;     break;
		case  XOR: r = iopa ^ iopb;     break;
		case  SUB: r = iopa - iopb;     break;
		case ANDN: r = ~(iopa&iopb);     break;
		case  ORN: r = ~(iopa|iopb);     break;
		case XNOR: r = ~(iopa ^ iopb);     break;
		case ADDX: r = iopa + iopb + cin; break;
		case SUBX: r = iopa - iopb - cin; 
    }
    toBits((unsigned long)r, res, 32);
    switch(ifcod)
    {

		case  AND:;
		case   OR:;
               // Las operaciones logicas
		case  XOR:;
               // dejan en 0 carry y overflow
		case ANDN:;
		case  ORN:;
		case XNOR: carry.val = 0; over.val = 0; break;
 
		case ADDX: ;
		case  ADD: carry.val = (r > 0xFFFFFFFF);
		           over.val = ((opa[31] == opb[31]) && (opa[31]!=res[31].val));
			   break;
		case  SUB: carry.val = (fromBits(opa,32) < (fromBits(opb,32)+cin));
		case SUBX: over.val = ((opa[31] != opb[31]) && (opb[31]!=res[31].val));
			   break;
    }
    

    /******************************************************************/
    /*
               FALTAN LOS PONER LOS FLAGS.
                                                                      */
    /******************************************************************/
    zero.val = (r == 0);  //El zero flag para todas las operaciones es igual
    
    neg.val = res[31].val;  //El neg flag para todas las operaciones es igual
    for(i=0;i<32;i++)
     {
	if (needSend(res[i])) 
	    this->sendOutput( msg.time(), *RES[i], res[i].val);
    }
    if (needSend(zero))
      this->sendOutput( msg.time(), Z, zero.val);
    if (needSend(neg))
      this->sendOutput( msg.time(), N, neg.val);
    if (needSend(carry))
      this->sendOutput( msg.time(), C, carry.val);
    if (needSend(over))
      this->sendOutput( msg.time(), V, over.val);
    return *this;
}

