/*******************************************************************

*

*  DESCRIPTION: Atomic Model CWPlogic

*

*  AUTHOR: Mario Bergotto & Tomas Heredia 

*

*  EMAIL: mailto://mbergott@dc.uba.ar

*         mailto://theredia@dc.uba.ar,tomas@intermedia.com.ar

*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 31/01/2000
*
*

*******************************************************************/



/** my include files **/

#include "CWPlogic.h"      // class CWPlogic

#include <message.h>    // class ExternalMessage, InternalMessage

#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )

/** public functions **/


/*******************************************************************

* Function Name: CWPlogic

* Description: 

********************************************************************/

CWPlogic::CWPlogic( const string &name )

: Atomic( name )

, R_G( this->addOutputPort( "R_G" ) )

, preparationTime( 0, 0, 10, 0)

{

	CWP = addPorts( ptInput, "CWP", 5, *this);
	SEL = addPorts( ptInput, "SEL",5, *this);
	GSEL = addPorts( ptOutput, "GSEL",3, *this);
	RSEL = addPorts( ptOutput, "RSEL",9, *this);
	if (MainSimulator::Instance().existsParameter( this->description(), "response") ) {

		string time( MainSimulator::Instance().getParameter( this->description(), "response" ) );

		if (time != "")

			preparationTime = time;

	}

}





CWPlogic::~CWPlogic

()
{
    delete [] CWP;
    delete [] SEL;
    delete [] GSEL;
    delete [] RSEL;


}
/*******************************************************************

* Function Name: initFunction

* todas las variables se inicializan en cero

********************************************************************/

Model &CWPlogic::initFunction()

{

	toBits(0, rsel, 9);
	return *this ;

}





/*******************************************************************

* Function Name: externalFunction

* Description: 

********************************************************************/

Model &CWPlogic::externalFunction( const ExternalMessage &msg )

{

        int portNum;
        string portName;
        nameNum( msg.port().name(), portName, portNum);
        if (portName == "cwp")
          cwp[portNum] = bit(msg.value());
	else
          if (portName == "sel")
          sel[portNum] = bit(msg.value());
	this->holdIn( active, preparationTime );

	return *this;

}



/*******************************************************************

* Function Name: internalFunction

* Description: 

********************************************************************/

Model &CWPlogic::internalFunction( const InternalMessage & )

{

	this->passivate();

	return *this ;

}





/*******************************************************************

* Function Name: outputFunction

* Description: 

* Asumo que la primera vez me vienen TODAS las entradas juntas.

* EN caso contrario, NO SE GARANTIZA EL COMPORTAMIENTO DEL MODELO.

* segunda opcion: (implementada) la primera vez se manda gsel o rsel

* (segun corresponda), y rg. Las siguientes veces se envian unicamente

* los ports que hayan cambiado. Si se efectiviza la salida antes de

* recibir todas las entradas, no se garantiza el comportamiento de la

* salida.

********************************************************************/

Model &CWPlogic::outputFunction( const InternalMessage &msg )

{


	if (fromBits( sel, 5) < 8) {
	    
	    for(int i=0; i<3 ; i++) {
	      gsel[i].val = sel[i];
	      if (needSend( gsel[i] )) 
	         this->sendOutput( msg.time(), *GSEL[i], gsel[i].val);
	    }
	    r_g.val = 0;
	}
	else {

	  toBits((fromBits(cwp,5)*16+fromBits( sel, 5) - 8), rsel, 9);
	  r_g.val = 1;
	  for(int i = 0; i < 9; i ++)
  	    if (needSend( rsel[i] )) 
	      this->sendOutput( msg.time(), *RSEL[i], rsel[i].val);

	}
	if (needSend( r_g )) 
	     this->sendOutput( msg.time(), R_G, r_g.val);
	return *this ;

}

