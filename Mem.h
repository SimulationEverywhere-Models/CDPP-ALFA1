/*******************************************************************
*
*  DESCRIPTION: Atomic Model Mem
*
*  AUTHOR: Barletta, Patricio / Enrique, Sebastian / Rubinstein, Diego
*
*
*  MODIFICADO POR: Pablo L. Cremona
*                  Pablo S. Sor
*
*  DATE: 18/01/2000
*

*

*
*******************************************************************/

#ifndef __Mem_H
#define __Mem_H


#include <atomic.h>     // class Atomic
#include "stdio.h" // class stdio
#include <fstream>
#include "bits.h"

class Mem : public Atomic
{
public:
        Mem( const string &name = "Mem" );                  //Default constructor

        ~Mem();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
    void freset();
    void guardarDato(long dir, char dato);
    void buscarDato(long dir, char *dato);


    // Puertos de direccion (l¡neas de in)
    Port **DATA_IN, **DATA_OUT, **A, **BSEL,&AS, &RD_WR, &RESET, &DTACK, &ERR;
    bit dataIn[32], a[32], bsel[4], as, rd_wr, reset;
    o_bit dataOut[32], dtack, err;

    Time preparationTime;
    unsigned long memorySize;
    string memoryFile;
    string dumpFile;
    char *memory; //Memoria;

    
    

};  // class Mem

// ** inline ** //
inline
string Mem::className() const
{
    return "Mem" ;
}


#endif   //__Mem_H
