/*******************************************************************
*
*  DESCRIPTION: Atomic Model MulDiv
*
*  AUTHOR: Mario Bergotto & Tomas Heredia 
*
*  EMAIL: mailto://mbergott@dc.uba.ar
*         mailto://theredia@dc.uba.ar,tomas@intermedia.com.ar
*
*******************************************************************/

/** my include files **/
#include "MulDiv.h"      // class MulDiv
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
/** public functions **/

/*******************************************************************
* Function Name: MulDiv
* Description: 
********************************************************************/
MulDiv::MulDiv( const string &name )
: Atomic( name )
, N( this->addOutputPort( "N" ) )
, Z( this->addOutputPort( "Z" ) )
, V( this->addOutputPort( "V" ) )
, DIV_ZERO( this->addOutputPort( "DIV_ZERO" ) )
, preparationTime( 0, 0, 30, 0)
{
    OPA = addPorts( ptInput, "OPA", 32, *this );
    OPB = addPorts( ptInput, "OPB", 32, *this );
    YIN = addPorts( ptInput, "YIN", 32, *this );
    FCOD = addPorts( ptInput, "FCOD", 2, *this);
    RES = addPorts( ptOutput, "RES", 32, *this);
    YOUT = addPorts( ptOutput, "YOUT", 32, *this);
	
    if (MainSimulator::Instance().existsParameter( this->description(), "response") ) {
	string time( MainSimulator::Instance().getParameter( this->description(), "response" ) );
	if (time != "") 
	    preparationTime = time;
    }
}
MulDiv::~MulDiv(){
    delete [] OPA;
    delete [] OPB;
    delete [] YIN;
    delete [] FCOD;
    delete [] RES;
    delete [] YOUT;
}



/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &MulDiv::initFunction()
{
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &MulDiv::externalFunction( const ExternalMessage &msg )
{
	int portNum;
	string portName;
	nameNum( msg.port().name(), portName, portNum);
	if (portName == "opa")
	  opa[portNum] = bit(msg.value());
	else 
	if (portName == "opb")
	  opb[portNum] = bit(msg.value());
	else
	if (portName == "yin")
	  yin[portNum] = bit(msg.value());
	if (portName == "fcod")
	  fcod[portNum] = bit(msg.value());
	
	

	this->holdIn( active, preparationTime );
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &MulDiv::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &MulDiv::outputFunction( const InternalMessage &msg )
{
	long long r;
	unsigned long long ur;
	unsigned long uob;
	long ob;
	int ifcod = fromBits(fcod, 2);
	switch(ifcod) {
	    case 0: ur = fromBits(opa, 32) * fromBits(opb, 32);
	            toBits((unsigned long)(ur>>32), yout, 32);
		    toBits((unsigned long)ur, res, 32);
		    z.val = ((unsigned long)ur == 0);
		    break;
	    case 1: r = long(fromBits(opa, 32)) * long(fromBits(opb, 32));
	            toBits((unsigned long)((unsigned long long)r>>32), yout, 32);
		    toBits((unsigned long)r, res, 32);
		    z.val = (long(r) == 0);
		    break;
	    case 2: if(!( uob = fromBits(opb, 32) ))
		      div_zero.val = 1;
		    else {
		      ur = ( ( ((unsigned long long)(fromBits(yin, 32)) ) << 32 ) + fromBits(opb, 32) )/uob;
		      if (ur > 0xFFFFFFFF) {
			toBits(0xFFFFFFFF,res,32);
			v.val = 1;
			}
		      else {
			toBits((unsigned long)ur,res,32);
			v.val = 0;
		      }
		    }
		    z.val = ((unsigned long)ur == 0);		    
		    break;
	    case 3: if(!(ob = fromBits(opb, 32)))
		      div_zero.val = 1;
		    else {
		      r = ((((long long)(fromBits(yin, 32)))<<32) + fromBits(opb, 32))/ob;
		      if (r > 0xFFFFFFFF)  {
			toBits((yin[31]==opb[31])?0x7FFFFFF:0xFFFFFFFF,res,32);
			v.val = 1; 
			}
		      else {
			toBits((unsigned long)r,res,32);
			v.val = 0;
		      }
		    }
		    z.val = (long(r) == 0);
		    break;
	}
        n.val = res[31].val;


	int i;
        for(i=0; i<32; i++) {
          if ( needSend( res[i] ) )
	      this->sendOutput( msg.time(), *RES[i], res[i].val);
	}
        for(i=0; i<32; i++) {
          if ( needSend( yout[i] ) )
	      this->sendOutput( msg.time(), *YOUT[i], yout[i].val);
	}


	if (needSend(n)) {
		this->sendOutput( msg.time(), N, n.val ) ;
	}
	if (needSend(z)) {
		this->sendOutput( msg.time(), Z, z.val ) ;
	}
	if (needSend(v)) {
		this->sendOutput( msg.time(), V, v.val ) ;
	}

	if ( needSend(div_zero) ) {
		this->sendOutput( msg.time(), DIV_ZERO, div_zero.val ) ;
	}

	return *this ;
}
