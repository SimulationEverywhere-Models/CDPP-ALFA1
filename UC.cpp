#include "UC.h"
#include <string>
#include <mainsimu.h>   // MainSimulator::Instance().getParameter( ... )
#include <message.h>

inline bool isFormat2( bit i[] ) { return !i[31] && !i[30]; }
inline bool isFormat3( bit i[] ) { return i[31] && !i[30]; }
inline bool isBranch( bit i[] ) { return isFormat2( i ) && fromBits( i+22, 3 ) == 2; }
inline bool isUnimp( bit i[] ) { return isFormat2( i ) && fromBits( i+22, 3 ) == 0; }
inline bool isArit( bit i[] ) { return isFormat3( i ) && ( !i[24] || fromBits( i+21, 4 ) == 9 ); }
inline bool isRestSave( bit i[] ) { return isFormat3( i ) && fromBits( i+20, 5 ) == 30; }
inline bool isSetHi( bit i[] ) { return isFormat2( i ) && fromBits( i+22, 3 ) == 4; }
inline bool isMulDiv( bit i[] ) { return !i[24] && i[22] && i[20]; }
inline bool isMul( bit i[] ) { return isMulDiv( i ) && !i[19]; }
inline bool isShft( bit i[] ) { return i[24]; }
inline bool isAlu( bit i[] ) { return !isShft( i ) && !isMulDiv( i ); }
inline bool isJmp( bit i[] ) { return isFormat3( i ) && fromBits( i+20, 5 ) == 28; }
inline bool isCall( bit i[] ) { return !i[31] && i[30]; }
inline bool isLoad( bit i[] ) { return i[31] && i[30] && !i[21]; }
inline bool isStore( bit i[] ) { return i[31] && i[30] && i[21]; } 
inline bool isRd( bit i[] ) { return isFormat3( i ) && fromBits( i+22, 3 ) == 5; }
inline bool isWr( bit i[] ) { return isFormat3( i ) && fromBits( i+22, 3 ) == 6; }
inline bool isSpPSR( bit i[] )  { return fromBits( i+19, 3 ) == 1; }
inline bool isSpWIM( bit i[] )  { return fromBits( i+19, 3 ) == 2; }
inline bool isSpTBR( bit i[] )  { return fromBits( i+19, 3 ) == 3; }
inline bool isRdY( bit i[] )    { return fromBits( i+14, 8 ) == 0; }
inline bool isRdBase( bit i[] ) { return fromBits( i+14, 8 ) == 1; }
inline bool isRdLim( bit i[] )  { return fromBits( i+14, 8 ) == 2; }
inline bool isWrY( bit i[] )    { return fromBits( i+19, 3 ) == 0 && fromBits( i+25, 5 ) == 0; }
inline bool isWrBase( bit i[] ) { return fromBits( i+19, 3 ) == 0 && fromBits( i+25, 5 ) == 1; }
inline bool isWrLim( bit i[] )  { return fromBits( i+19, 3 ) == 0 && fromBits( i+25, 5 ) == 2; }


#define CSEL_O7 15
#define C_MUX_ARES 1
#define C_MUX_IR 2
#define C_MUX_PC 4
#define C_MUX_AL 8
#define C_MUX_SPREG 16
#define MUX_REG 1
#define ALU_ADD 0
#define ALU_XOR 3
#define PC_MUX_ARES 2
#define PC_MUX_ADD 4
#define PC_MUX_INC 1
#define ADDR_MUX_PC 1
#define ADDR_MUX_ARES 0
#define INCDEC_INC 1
#define SP_MUX_PSR   1
#define SP_MUX_Y     2
#define SP_MUX_TBR   4
#define SP_MUX_WIM   8
#define SP_MUX_LIM  16
#define SP_MUX_BASE 32

static string mportnames[nummports] =
    { "A_SEL", "B_SEL", "C_SEL", "C_MUX", "ALU_FCOD", "PC_MUX", "ALIGNL", "ALIGNS", "SP_OUT_MUX" };

static int mportsizes[nummports] =
    { 5      , 5      , 5      , 5      , 4         , 4       , 4       , 2       , 6 };

static string sportnames[numsports] =
{ "C_EN", "C_LATCH_EN", "A_MUX_REG", "A_LATCH_EN", "B_MUX_REG", "B_LATCH_EN", "ENABLE_MUL"
, "ENABLE_ALU", "ENABLE_SHFT", "ALU_RES_EN", "Y_EN", "Y_LATCH_EN", "NPC_LATCH_EN", "NPC_EN", "PC_LATCH_EN", "PC_EN"
, "DISP_MUX", "ADDR_MUX", "IR_LATCH_EN", "DATA_IN_EN", "DATA_OUT_EN", "ALIGNL_SIGN", "INCDEC_FCOD", "CWP_LATCH_EN", "CWP_EN"
, "CC_LATCH_EN", "CC_EN", "CC_MUX", "CWP_MUX", "Y_MUX", "TT_MUX", "TBA_EN", "TT_EN", "WIM_EN", "LIM_EN", "BASE_EN"
, "AS", "RD_WR", "BUSY", "RESET", "HALT" };

enum { c_I = -1, c_F, c_D, c_E, c_M, c_W };

#define numciclos 6

UC::UC( const string &name )
  : Atomic( name )
  , CCLOGIC( this->addInputPort( "CCLOGIC" ) )
  , CLCK( this->addInputPort( "CLCK" ) )
  , DTACK( this->addInputPort( "DTACK" ) )
  , waitfmc( 0 )
  , ciclo( c_I )

{
  IR = addPorts( ptInput, "IR", 32, *this );
  PSR = addPorts( ptInput, "PSR", 32, *this );
  
  o_bit **tmportbits[nummports] = { &a_sel, &b_sel, &c_sel, &c_mux, &alu_fcod, &pc_mux, &alignl, &aligns, &sp_out_mux };
  mOUT = new (Port **)[nummports];
  for( int i = 0; i < nummports; i++ ) {
    mportbits[i] = new o_bit[mportsizes[i]];
    *tmportbits[i] = mportbits[i];
    mOUT[i] = addPorts( ptOutput, mportnames[i], mportsizes[i], *this );
  }

  o_bit *tsportbits[numsports] =
  { &c_en, &c_latch_en, &a_mux_reg, &a_latch_en, &b_mux_reg, &b_latch_en, &enable_mul
  , &enable_alu, &enable_shft, &alu_res_en, &y_en, &y_latch_en, &npc_latch_en, &npc_en, &pc_latch_en, &pc_en
  , &disp_mux, &addr_mux, &ir_latch_en, &data_in_en, &data_out_en, &alignl_sign, &incdec_fcod, &cwp_latch_en, &cwp_en
  , &cc_latch_en, &cc_en, &cc_mux, &cwp_mux, &y_mux, &tt_mux, &tba_en, &tt_en, &wim_en, &lim_en, &base_en
  , &as, &rd_wr, &busy, &reset, &halt };

  sOUT = new (Port *)[numsports];

  for( int i = 0; i < numsports; i++ ) {
    sportbits[i]=tsportbits[i];
    sOUT[i] = & this->addOutputPort( sportnames[i] );
  }

}

UC::~UC() {
  delete [] IR;
  delete [] PSR;
  delete [] sOUT;
}

Model &UC::initFunction()
{
   return *this;
}

Model &UC::externalFunction( const ExternalMessage &msg )
{
  if( msg.port() == CLCK ) {
    if( ! waitfmc ) {
      ciclo = (ciclo + 1) % numciclos;
      this->holdIn( active, 0 );
    } else
      this->passivate();
  } else if( msg.port() == DTACK ) {
    if( msg.value() == 1 )
      waitfmc = 0;
    this->passivate();
  } else if( msg.port() == CCLOGIC ) {
    cclogic = bit( msg.value() );
    this->passivate();
  } else {
    string portName;
    int portNum;
    nameNum( msg.port().name(), portName, portNum );
    if( portName == "ir" )
      ir[portNum] = bit( msg.value() );
    else
      psr[portNum] = bit( msg.value() );
    this->passivate();
  }

  return *this;
}

Model &UC::internalFunction( const InternalMessage & )
{
  if( as.val )
    waitfmc = 1;
  this->passivate();
  return *this;
}

Model &UC::outputFunction( const InternalMessage &msg )
{
  if( ( ciclo == c_M || ciclo == c_W ) && isStore( ir ) )
    copyBits( ir+25, a_sel, 5 );
  else
    copyBits( ir+14, a_sel, 5 );
  copyBits( ir, b_sel, 5 );
  if( ciclo != c_F && isCall( ir ) )
    toBits( CSEL_O7, c_sel, 5 );
  else
    copyBits( ir+25, c_sel, 5 );

  c_en.val = ciclo == c_W && !isBranch( ir ) && !isStore( ir ) && !isWr( ir );

  if( isArit( ir ) || isRestSave( ir ) )
    toBits( C_MUX_ARES, c_mux, 5 );
  else if( isSetHi( ir ) )
    toBits( C_MUX_IR, c_mux, 5 );
  else if( isLoad( ir ) )
    toBits( C_MUX_AL, c_mux, 5 );
  else if( isRd( ir ) )
    toBits( C_MUX_SPREG, c_mux, 5 );
  else
    toBits( C_MUX_PC, c_mux, 5 );
  
  c_latch_en.val = ciclo == c_M;

  a_mux_reg.val = MUX_REG;

  a_latch_en.val = ciclo == c_D;

  b_mux_reg.val = !ir[13];

  b_latch_en.val = ciclo == c_D;

  if( isArit( ir ) ) {
    copyBits( ir+19, alu_fcod, 4 );
    enable_mul.val =  isMulDiv( ir );
    enable_alu.val =  isAlu( ir );
    enable_shft.val =  isShft( ir );
  } else {
    enable_mul.val = 0;
    enable_alu.val = 1;
    enable_shft.val = 0;
    if( isWr( ir ) )
      toBits( ALU_XOR, alu_fcod, 4 );
    else
      toBits( ALU_ADD, alu_fcod, 4 );
  }

  alu_res_en.val = ciclo == c_E;

  y_latch_en.val = ciclo == c_E || (ciclo == c_M && isWr( ir ) );

  y_en.val = ciclo == c_W && ( isMul( ir ) || isWr( ir ) && isWrY( ir ) );

  if( isJmp( ir ) )
    toBits( PC_MUX_ARES, pc_mux, 4 );
  else if( isCall( ir ) || isBranch( ir ) && cclogic )
    toBits( PC_MUX_ADD, pc_mux, 4 );
  else
    toBits( PC_MUX_INC, pc_mux, 4 );

  npc_latch_en.val = ciclo == c_M;

  npc_en.val = ciclo == c_W;

  pc_latch_en.val = ciclo == c_M;

  pc_en.val = ciclo == c_W;

  disp_mux.val = isCall( ir );

  addr_mux.val = ciclo == c_F ? ADDR_MUX_PC : ADDR_MUX_ARES;

  ir_latch_en.val = ciclo == c_F;

  data_in_en.val = ciclo == c_M;

  data_out_en.val = ciclo == c_M;

  copyBits( ir+19, alignl, 2 );
  alignl_sign.val = ir[22];

  copyBits( ir+19, aligns, 2 );

  if( isJmp( ir ) )
    incdec_fcod.val = INCDEC_INC;
  else
    incdec_fcod.val = ir[19];

  cwp_latch_en.val = ciclo == c_E || ( ciclo == c_M && isWr( ir ) );
  
  cwp_en.val = ciclo == c_W && ( isRestSave( ir ) || ( isJmp( ir ) && ir[19] ) || isWr( ir ) && isSpPSR( ir ) );

  cc_latch_en.val = ciclo == c_E || ( ciclo == c_M && isWr( ir ) );

  cc_en.val = ciclo == c_W && ( isArit( ir ) && ir[23] || isWr( ir ) && isSpPSR( ir ) );

  cc_mux.val = cwp_mux.val = y_mux.val = tt_mux.val = isWr( ir );

  tba_en.val = ciclo == c_W && isWr( ir ) && isSpTBR( ir );
  tt_en.val = ciclo == c_W && isWr( ir ) && isSpTBR( ir );
  wim_en.val = ciclo == c_W && isWr( ir ) && isSpWIM( ir );
  lim_en.val = ciclo == c_W && isWr( ir ) && isWrLim( ir );
  base_en.val = ciclo == c_W && isWr( ir ) && isWrBase( ir );

  if( ciclo == c_D && isRd( ir ) )
    if( isSpPSR( ir ) )
      toBits( SP_MUX_PSR, sp_out_mux, 6 );
    else if( isRdY( ir ) )
      toBits( SP_MUX_Y, sp_out_mux, 6 );
    else if( isSpTBR( ir ) )
      toBits( SP_MUX_TBR, sp_out_mux, 6 );
    else if( isSpWIM( ir ) )
      toBits( SP_MUX_WIM, sp_out_mux, 6 );
    else if( isRdLim( ir ) )
      toBits( SP_MUX_LIM, sp_out_mux, 6 );
    else if( isRdBase( ir ) )
      toBits( SP_MUX_BASE, sp_out_mux, 6 );

  busy.val = as.val = ciclo == c_F || ( ciclo == c_M && isLoad( ir ) ) || ( ciclo == c_W && isStore( ir ) );

  rd_wr.val = ciclo == c_F || !isStore( ir );

  if( ciclo == c_D && isUnimp( ir ) )
    halt.val = 1;

  for( int i = 0; i < numsports; i++ )
    if( needSend( *sportbits[i] ) )
      this->sendOutput( msg.time(), *sOUT[i], sportbits[i]->val );
  for( int i = 0; i < nummports; i++ )
    for( int j = 0; j < mportsizes[ i ]; j++ )
      if( needSend( mportbits[i][j] ) )
	this->sendOutput( msg.time(), *mOUT[i][j], mportbits[i][j].val );
  return *this;
}
