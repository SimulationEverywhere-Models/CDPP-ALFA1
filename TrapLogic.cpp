/*******************************************************************
*
*  DESCRIPTION: Atomic Model TrapLogic
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
*  DATE: 28/01/1999
*
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "TrapLogic.h"   // class TrapLogic
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )


/*******************************************************************
* Function Name: TrapLogic
* Description: 
********************************************************************/
TrapLogic::TrapLogic( const string &name )
: Atomic( name )
, INST_ACC_EXCEP( this->addInputPort( "INST_ACC_EXCEP" ) ) 
, ILLEG_INST( this->addInputPort( "ILLEG_INST" ) )
, PRIV_INST( this->addInputPort( "PRIV_INST" ) ) 
, WIN_OVER( this->addInputPort( "WIN_OVER" ) ) 
, WIN_UNDER( this->addInputPort( "WIN_UNDER" ) ) 
, ADDR_NOT_ALIGN( this->addInputPort( "ADDR_NOT_ALIGN" ) ) 
, DATA_ACC_EXCEP( this->addInputPort( "DATA_ACC_EXCEP" ) ) 
, INST_ACC_ERR( this->addInputPort( "INST_ACC_ERR" ) ) 
, DATA_ACC_ERR( this->addInputPort( "DATA_ACC_ERR" ) ) 
, DIV_ZERO( this->addInputPort( "DIV_ZERO" ) ) 
, DATA_ST_ERR( this->addInputPort( "DATA_ST_ERR" ) )
, TRAP_INST( this->addInputPort( "TRAP_INST" ) ) 
, TF( this->addOutputPort( "TF" ) ) 
, preparationTime( 0, 0, 0, 40 )

{
	TN = addPorts( ptInput, "TN", 7, *this );
	TT = addPorts( ptOutput, "TT", 8, *this);

	if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
    	    string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;

	    if( time != "" )
		preparationTime = time ;
	}
}

TrapLogic::~TrapLogic(){
    delete [] TN;
    delete [] TT;
}


/*******************************************************************
* Function Name: initFunction
* Description: no hace nada
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &TrapLogic::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &TrapLogic::externalFunction( const ExternalMessage &msg )
{


        int portNum;
        string portName;
        nameNum( msg.port().name(), portName, portNum);
        if (portName == "tn")
	    tn[portNum] = bit(msg.value());
	else
	{
		//get Trap Index
		trap[ getTrapIndexFromTrapName( msg.port().name() )] = bit(msg.value());
		
	}
	
	this->holdIn( active,  preparationTime );
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: pasiva el modelo
********************************************************************/
Model &TrapLogic::internalFunction( const InternalMessage & )
{
	this -> passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: muestra por el port RES el resultado del cálculo
********************************************************************/
Model &TrapLogic::outputFunction( const InternalMessage &msg )
{
	int iTT;
	
	iTT = getTrapTypeFromTrapIndex( getHighestPriorityTrapIndex() );	
	if (!iTT)
 
          tf.val = 0;
	else
	{
          tf.val = 1;
	  toBits( iTT, tt, 8);
	  for(int i = 0; i < 8; i++)
	    if (needSend( tt[i] ))
	      this->sendOutput( msg.time(), *TT[i], tt[i].val ) ;
	  
	}
	if (needSend( tf ))
	  this->sendOutput( msg.time(), TF, tf.val ) ;

	return *this ;
}


/*******************************************************************
* Function Name: getNumberFromString
* Description: devuelve el número que indica el string desde la 
*	posición iStartPos
********************************************************************/
int TrapLogic::getNumberFromString( const string &sSource, const unsigned int iStartPos ) const
 {
	string::const_iterator curs ;
	int iRes = 0;
	bool bNumber;	
	
	assert ( iStartPos <= sSource.size() && iStartPos >= 0);

	//advance iterator to iStartPos position
	curs = sSource.begin();
	for (unsigned int iPos = 1; iPos < iStartPos; iPos++) {
		curs++;
	};

	//Get the number
	bNumber = true;
	while (curs != sSource.end() && bNumber ) {
		bNumber = (*curs >= '0' && *curs <= '9');
		if (bNumber) 
			iRes = iRes * 10 + (*curs) - '0';	
		curs++;
	}

	return iRes;	
}




/*******************************************************************
* Function Name: getTrapIndexFromTrapName
* Description: devuelve el índice del array de traps
* 	correspondiente al trap sTrapName
********************************************************************/
int TrapLogic::getTrapIndexFromTrapName(const string &sTN) const
{
	if (sTN ==  "DATA_ST_ERR")
		return 0;
	if (sTN == "INST_ACC_ERR")
		return 1;
	if (sTN == "INST_ACC_EXCEP")
		return 2;
	if (sTN == "PRIV_INST")
		return 3;
	if (sTN == "ILLEG_INST")
		return 4;
	if (sTN == "WIN_OVER")
		return 5;
	if (sTN == "WIN_UNDER")
		return 6;
	if (sTN == "ADDR_NOT_ALIGN")
		return 7;
	if (sTN == "DATA_ACC_ERR")
	 	return 8;
	if (sTN == "DATA_ACC_EXCEP")
		return 9;
	if (sTN ==  "DIV_ZERO")
		return 10;
	if (sTN == "TRAP_INST")
		return 11;

	
	assert (false);	 	
	return -1; //Para evitar el Warning

}

/*******************************************************************
* Function Name: getTrapTypeFromTrapIndex
* Description: devuelve el Trap type del trap de índice iIndex
********************************************************************/
int TrapLogic::getTrapTypeFromTrapIndex(const int iIndex) const
{
	switch (iIndex) {
		case 0: return 0x2B; //0x2B
		case 1: return 0x21; //0x21
		case 2: return 0x1;
		case 3: return 0x3;
		case 4: return 0x2;
		case 5: return 0x5;
		case 6: return 0x6;
		case 7: return 0x7;
		case 8: return 0x29;//41; //0x29
		case 9: return 0x9;
		case 10: return 0x2A;//42; //0x2A
		case 11: return 0x80 + fromBits(tn, 7); //128 + TNValue(); //0x80 + TN
		default: return 0;
	}
}


/*******************************************************************
* Function Name: getHighestPriorityTrapIndex
* Description: devuelve el índice del trap de mayor prioridad
********************************************************************/
int TrapLogic::getHighestPriorityTrapIndex()
{
	int iIndex;

	for (iIndex = 0; (iIndex < 12) && !(trap[iIndex]); iIndex++);

	if (iIndex == 12) 
		return -1;
	else
		return iIndex;		
}
