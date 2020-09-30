#include "bits.h"
#include <stdio.h>

o_bit::o_bit()
   : val( 0 )
   , lastval( 0 )
{}

string itos( int i )
{
   char buf[20];
   sprintf( buf, "%d", i );
   return string( buf );
}

Port **addPorts( PortType portType, const string &basename, int number, Atomic &m, int start = 0 )
{
   Port **r = new (Port *)[number];
   for( int i = 0; i < number; i++ )
      if( portType == ptInput )
         r[i] = & m.addInputPort( basename + itos( i + start ) );
      else
         r[i] = & m.addOutputPort( basename + itos( i + start ) );
   return r;
}

void nameNum( const string &n, string &name, int &num )
{
   int i;
   for( i = 0; ! isdigit( n[ i ] ); i++ );
   name = n.substr( 0, i );
   num = atoi( n.substr( i, n.length() - i ).c_str() );
}

unsigned long fromBits( const bit b[], int nbits = defnbits )
{
   unsigned long r = 0;
   for( int i = 0; i < nbits; i++ )
      r |= b[ i ] << i;
   return r;
}

void toBits( unsigned long v, o_bit b[], int nbits = defnbits )
{
   for( int i = 0; i < nbits; i++ )
   {
      b[ i ].val = v % 2;
      v >>= 1;
   }
}
void copyBits( const bit source[], o_bit dest[], int nbits = defnbits )
{
   for( int i = 0; i < nbits; i++ )
      dest[ i ].val = source[ i ];
}
int needSend( o_bit &v )
{
   int need = ( v.val != v.lastval );
   v.lastval = v.val;
   return need;
}
