#ifndef __BITS_H
#define __BITS_H

#include <string>
#include <atomic.h>

const int defnbits = 32;

typedef bool bit;

enum PortType { ptInput, ptOutput };

class o_bit {
public:
        bit val, lastval;
	o_bit();
};

Port **addPorts( PortType pt, const string &basename, int number, Atomic &m, int start = 0 );
void nameNum( const string &n, string &name, int &num );
unsigned long fromBits( const bit b[], int nbits = defnbits );
void toBits( unsigned long v, o_bit b[], int nbits = defnbits );
void copyBits( const bit source[], o_bit dest[], int nbits = defnbits );
int needSend( o_bit &v );
string itos( int i );

#endif
