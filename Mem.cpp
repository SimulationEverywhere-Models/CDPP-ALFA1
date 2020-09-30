/*******************************************************************
  DESCRIPTION: Atomic Model Mem

  AUTHOR: Barletta, Patricio - Enrique, Sebastian - Rubinstein, Diego


Simula lectura y escritura de memoria big-endian con direccionamiento a
byte.
La misma es tomada de un archivo MEMORY.MAP (en caso de que no se informe "memfile").
El tama¤o de la misma se especifica como par metro en MEM.MA con
"memorySize = "
Si no existe el archivo se crea una memoria de tama¤o especificado,
si no se hace expl¡cito ‚ste £ltimo, se considera de 32768 bytes.
Puede resetearse para volver al estado original.

PORTS DE ENTRADA:  

DATA_IN0..31    L¡nea de datos.
A2..31          L¡nea de direcciones.
BSEL0..3        Byte Select.
AS              Address Strobe.
RD_WR           Lectura (1) o escritura (0).
RESET           0 = Resetea la memoria. 1 = Continua como est .

PORTS DE SALIDA:

DATA_OUT0..31   L¡nea de datos.
DTACK           Data Aknowledge.
ERR             Error.
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 18/01/2000
*

*

*******************************************************************/

/** include files **/
#include <string>


/** my include files **/
#include "Mem.h"       // class Mem
#include <message.h>    // class ExternalMessage, InternalMessage
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <strutil.h>       // str2Int( ... )

/** public functions **/
/*******************************************************************
* Function Name: Mem
* Description:
********************************************************************/
Mem::Mem( const string &name )
: Atomic( name )
, AS( this->addInputPort( "AS" ) )
, RD_WR( this->addInputPort( "RD_WR" ) )
, RESET( this->addInputPort( "RESET" ) )
, DTACK( this->addOutputPort( "DTACK" ) )
, ERR( this->addOutputPort( "ERR" ) )
, preparationTime( 0, 0, 10, 0 )
, memorySize( 32768 )
, memoryFile( "memory.map" )
, dumpFile( "/dev/null" )
{
    DATA_IN = addPorts(ptInput, "IN_DATA", 32, *this);
    DATA_OUT = addPorts(ptOutput, "OUT_DATA", 32, *this);
    A = addPorts(ptInput, "A", 30, *this, 2);
    BSEL = addPorts(ptInput, "BSEL", 4, *this);
    
    if (MainSimulator::Instance().existsParameter( this->description(), "response")) {
	string time( MainSimulator::Instance().getParameter( this->description(), "response" ) ) ;
	if( time != "" )
		preparationTime = time ;
    }
    if (MainSimulator::Instance().existsParameter( this->description(), "memsize")) {
	string memsize( MainSimulator::Instance().getParameter( this->description(), "memsize" ) ) ;
	if( memsize != "" )
            memorySize = str2Int(memsize);
    }    
    if (MainSimulator::Instance().existsParameter( this->description(), "memfile")) {
	string memfile( MainSimulator::Instance().getParameter( this->description(), "memfile" ) ) ;
	if( memfile != "" )
	    memoryFile = memfile;
    }
    if (MainSimulator::Instance().existsParameter( this->description(), "dumpfile")) {
	string sDumpfile( MainSimulator::Instance().getParameter( this->description(), "dumpfile" ) ) ;
	if( sDumpfile != "" )
	    dumpFile = sDumpfile;
    }

}

void dumpmem( char memory[], unsigned long memorySize, string dumpFile ) {
    ofstream dump(dumpFile.c_str());
    if (dump.good())
      for( unsigned long i = 0; i < memorySize; i++ )
	dump << memory[i];
}

Mem::~Mem(){
  dumpmem( memory, memorySize, dumpFile );
  delete [] DATA_IN;
  delete [] DATA_OUT;
  delete [] A;
  delete [] BSEL;
  delete [] memory;
 
}

/*******************************************************************
* Function Name: initFunction
* Description: Inicializa las lineas en 0 y genera el archivo de memoria
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Mem::initFunction()
{
	// Inicializo las l¡neas de entrada en 0
    memory = new char[ memorySize ];
    a[0] = 0;
    a[1] = 0;
    freset();
    return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: Guarda los valores de entrada y si AS = 1 escribe o
                lee en la memoria segun RD_WR.
********************************************************************/
Model &Mem::externalFunction( const ExternalMessage &msg )
{
    // Pregunto por el port de entrada y asigno el valor

    if (msg.port() == AS) 
      as = bit( msg.value() );
    else if (msg.port() == RD_WR) 
      rd_wr = bit( msg.value() );
    else if (msg.port() == RESET) {
      reset = bit( msg.value() ); 
      dumpmem( memory, memorySize, dumpFile );
    } else {
      int portNum;
      string portName;
      nameNum( msg.port().name(), portName, portNum);
      if (portName == "in_data")
	dataIn[portNum] = bit(msg.value());
      else if (portName == "a")
	a[portNum] = bit(msg.value());
      else if (portName == "bsel")
	bsel[portNum] = bit(msg.value());
    }


    this->holdIn(active, preparationTime);
    return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: Pasiva
********************************************************************/
Model &Mem::internalFunction( const InternalMessage & )
{
    this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: Si es una lectura manda el dato por los ports DATA_OUT
********************************************************************/
Model &Mem::outputFunction( const InternalMessage &msg )
{


    if (!reset){
        freset(); //reseteo la memoria
    } else if (as) {
      unsigned long dir = fromBits(a, 32);
      if (dir > memorySize-4) {
        err.val = 1;
        if (needSend( err ))
          this->sendOutput( msg.time(), ERR, err.val); // la direccion es invalida
        return *this;
      } else {
        dtack.val = 1;
        err.val = 0;
        if (needSend(dtack))
          this->sendOutput( msg.time(), DTACK, dtack.val );
        if (needSend(err))
          this->sendOutput( msg.time(), ERR, err.val );  
        if (rd_wr){
	  char dato[4];
	  buscarDato(dir, dato);
	  for (int i=0; i<4; i++) {
	    unsigned int j = dato [i];
	    for (int h = 0; h<8; h++){
	      dataOut[h+(3-i)*8].val = j % 2;
	      j = j / 2;
	    }
	  }
          for(int i = 0; i< 32;i++)
	    if(needSend( dataOut[i] ))
	      this->sendOutput( msg.time() , *DATA_OUT[i], dataOut[i].val );
        } else { //Escritura
          for(int i = 0; i < 4; i ++){
	    if (bsel[3-i])
	      guardarDato(dir+i, fromBits(dataIn+(3-i)*8,8));
	  }
        }
      } 
    } else 
      if( dtack.val ) {
      //SD 22/6/1999
        dtack.val = 0;
        if (needSend( dtack ))
          this->sendOutput( msg.time(), DTACK, dtack.val );
       }

    return *this ;
}

/*******************************************************************
* Function Name: reset
* Description: Inicializa el archivo a usar como memoria.
*              Si se paso un archivo imagen como parametro, lo carga.
********************************************************************/
void Mem::freset()
{

    ifstream dump(memoryFile.c_str());

    if (dump.good()) {
	unsigned long i = 0;
	dump.flags(0);
	while (!dump.eof() && i < memorySize) {
    	  dump >> memory[i++];
	}
	dump.close();
    }
    else {
	//no se encontro el archivo
    } ;

        
}

/*******************************************************************
* Function Name: buscarDato
* Description: Busca un dato en la memoria y lo guarda en dato[i],
*              donde i es el byte correspondiente a la direccion dir.
********************************************************************/
void Mem::buscarDato(long dir, char *dato)
{
    dato[0]=memory[dir];
    dato[1]=memory[dir+1];
    dato[2]=memory[dir+2];
    dato[3]=memory[dir+3];
}

/*******************************************************************
* Function Name: guardarDato
* Description: Guarda el dato (1 byte).
********************************************************************/
void Mem::guardarDato(long dir, char dato)
{
    memory[dir]=dato;
}

