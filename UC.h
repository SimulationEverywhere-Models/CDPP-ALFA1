#ifndef __UC_H
#define __UC_H

#include <atomic.h>
#include "bits.h"

class UC : public Atomic
{
public:
	UC( const string &name = "UC" );					//Default constructor
	~UC();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	Port **IR, **PSR, &CCLOGIC, &CLCK, &DTACK, **sOUT, ***mOUT;
	bit waitfmc, cclogic, ir[32], psr[32];
	int ciclo;

#define nummports 9

o_bit *a_sel, *b_sel, *c_sel, *c_mux, *alu_fcod, *pc_mux, *alignl, *aligns, *sp_out_mux;

o_bit *mportbits[nummports];

#define numsports 41

o_bit c_en, c_latch_en, a_mux_reg, a_latch_en, b_mux_reg, b_latch_en, enable_mul
, enable_alu, enable_shft, alu_res_en, y_en, y_latch_en, npc_latch_en, npc_en, pc_latch_en, pc_en
, disp_mux, addr_mux, ir_latch_en, data_in_en, data_out_en, alignl_sign, incdec_fcod, cwp_latch_en, cwp_en
, cc_latch_en, cc_en, cc_mux, cwp_mux, y_mux, tt_mux, tba_en, tt_en, wim_en, lim_en, base_en
, as, rd_wr, busy, reset, halt;

o_bit *sportbits[numsports];

};

inline string UC::className() const
{
	return "UC" ;
}

#endif

