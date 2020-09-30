/*******************************************************************
*
*  DESCRIPTION: Atomic Model CCLogic
*
*  AUTHOR: Deborah Grinberg & Marcos Nu¤ez Cort‚s
*
*  EMAIL: mailto://dgrinber@dc.uba.ar
*         mailto://jnuniez@dc.uba.ar
*
*  DATE: 27/9/1998
*
*
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 28/01/1999
*
*******************************************************************/

/** include files **/
#include <string>
#include <iostream>

/** my include files **/
#include "CCLogic.h"    // class CCLogic
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: CCLogic
* Description: Constructor del modelo (&name ser  su nombre)
********************************************************************/
CCLogic::CCLogic( const string &name )
: Atomic( name )
, C( this->addInputPort( "C" ) )
, N( this->addInputPort( "N" ) )
, Z( this->addInputPort( "Z" ) )
, V( this->addInputPort( "V" ) )
, RES( this->addOutputPort( "RES" ) )
, preparationTime( 0, 0, 10, 0 )
{
	COND = addPorts( ptInput, "COND", 4, *this);
	if( MainSimulator::Instance().existsParameter( this->description(),"response" ) )
	{
	    string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	    if( time != "" )
		preparationTime = time ;
	}
}
CCLogic::~CCLogic(){
    delete [] COND;
}

/*******************************************************************
* Function Name: initFunction
* Description: Pone a cero todas las variables internas
               Por convencion pone a cero el puerto de salida al inicio
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &CCLogic::initFunction()
{
        c = n = z = v = cond[0] = cond[1] = cond[2] = cond[3] = res.val = 0;
	return *this ;
}
/*******************************************************************
* Function Name: externalFunction
* Description: Almacena los datos de las entradas
********************************************************************/
Model &CCLogic::externalFunction( const ExternalMessage &msg )
{

       if( msg.port() == C ) c = bit(msg.value());
        else if( msg.port() == N ) n = bit(msg.value());
        else if( msg.port() == Z ) z = bit(msg.value());
        else if( msg.port() == V ) v = bit(msg.value());
	else
	  {
	  string portName;
          int portNum;
          nameNum(msg.port().name(), portName, portNum);
          if(portName == "cond")
	     cond[portNum] = bit( msg.value() );
          }
        this->holdIn( active, preparationTime );
        return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: Pasiva el modelo
********************************************************************/
Model &CCLogic::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: Envia el calculo de la salida al puerto RES
********************************************************************/
Model &CCLogic::outputFunction( const InternalMessage &msg )
{
        unsigned long lCond;
        lCond = fromBits(cond, 4);
        switch (lCond){
         case  0: res.val = 0;
                  break;
         case  1: res.val = z;
                  break;
         case  2: res.val = z || ((n || v) && !(n == v)); // Z v (N xor V)
                  break;
         case  3: res.val = (n || v) && !(n == v); 
                  break;
         case  4: res.val = c || z;
                  break;
         case  5: res.val = c;
                  break;
         case  6: res.val = n;
                  break;
         case  7: res.val = v;
                  break;
         case  8: res.val = 1;
                  break;
         case  9: res.val = !z;
                  break;
         case 10: res.val = !(z || ((n || v) && !(n == v)));
                  break;
         case 11: res.val = !((n || v) && !(n == v));
                  break;
         case 12: res.val = !(c || z);
                  break;
         case 13: res.val = !c;
                  break;
         case 14: res.val = !n;
                  break;
         case 15: res.val = !v;
                  break;
         default: res.val = lCond;
                  break;
        }
	if (needSend( res ))
    	    this->sendOutput( msg.time(), RES, res.val ) ;
	return *this ;
}
