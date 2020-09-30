/*******************************************************************
*
*  DESCRIPTION: Atomic Model AlignS
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
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 07/01/1999
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "AlignS.h"     // class AlignS
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: AlignS
* Description: Constructor del modelo (&name ser  su nombre)
********************************************************************/
AlignS::AlignS( const string &name )
: Atomic( name )
, SIZE0( this->addInputPort( "SIZE0" ) )
, SIZE1( this->addInputPort( "SIZE1" ) )
, A0( this->addInputPort( "A0" ) )
, A1( this->addInputPort( "A1" ) )
, preparationTime( 0, 0, 10, 0 )
{
	OP = addPorts( ptInput, "OP", 32, *this );
	RES = addPorts( ptOutput, "RES", 32, *this);
	BSEL = addPorts( ptOutput, "BSEL", 4, *this);

	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
  	  string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	  if( time != "" )
	    preparationTime = time ;
	}
}

AlignS::~AlignS()
{
  delete [] OP;
  delete [] RES;
}


/*******************************************************************
* Function Name: initFunction
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &AlignS::initFunction()
{
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: Almacena los datos de las entradas
********************************************************************/
Model &AlignS::externalFunction( const ExternalMessage &msg )
{
// Asigno el valor del puerto de entrada a la variable correspondiente
// para luego poder calcular el valor de la salida. 

  if ( msg.port() == SIZE0 ) 
    size0  = bit(msg.value());
  else if( msg.port() == SIZE1 ) 
    size1  = bit(msg.value());
  else if( msg.port() == A0 ) 
    a0  = bit(msg.value());
  else if( msg.port() == A1 ) 
    a1  = bit(msg.value()); 
  else {
    int portNum;
    string portName;
    nameNum( msg.port().name(), portName, portNum);
    if (portName == "op")
      op[portNum] = bit(msg.value());
  }
	
  this->holdIn( active, preparationTime );

  return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: Pasiva el modelo
********************************************************************/
Model &AlignS::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: Envia el calculo de la salida al puerto RES
********************************************************************/
Model &AlignS::outputFunction( const InternalMessage &msg )
{
        char i,j;

        if (size0==0 && size1==0) {                // Word
          j = 31;
	  toBits( 15, bsel, 4 );

        } else if (size1==1 && size0==0) {         // HalfWord
          j = (!a1 ? 15 : 31);
	  toBits( a1 ? 3 : 12, bsel, 4 );

        } else if (size1==0 && size0==1) {                // Byte
	  toBits(  1 << ( 3 - a1 * 2 - a0 ), bsel, 4 );
          if (a1==0 && a0==0) j = 7;
          if (a1==0 && a0==1) j = 15;
          if (a1==1 && a0==0) j = 23;
          if (a1==1 && a0==1) j = 31;
        }

        for(i=31; i>=0; i--,j--) {
          res[i].val = (j>=0 ? op[j] : 0);
          if ( needSend( res[i] ) )
	      this->sendOutput( msg.time(), *RES[i], res[i].val);
	}
	for( int i = 0; i < 4; i++ )
          if ( needSend( bsel[i] ) )
	      this->sendOutput( msg.time(), *BSEL[i], bsel[i].val);
	return *this ;
}
