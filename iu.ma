[top]
components : Mem@Mem bus@bus csmem@cs cpu c1@latch

in : DUMP
Link : DUMP RESET@Mem
Link : HALT@cpu RESET@Mem
out : HALT PC
Link : HALT@cpu HALT
components : dpc@todeci
Link : PC0@cpu IN0@dpc
Link : PC1@cpu IN1@dpc
Link : PC2@cpu IN2@dpc
Link : PC3@cpu IN3@dpc
Link : PC4@cpu IN4@dpc
Link : PC5@cpu IN5@dpc
Link : PC6@cpu IN6@dpc
Link : PC7@cpu IN7@dpc
Link : PC8@cpu IN8@dpc
Link : PC9@cpu IN9@dpc
Link : PC10@cpu IN10@dpc
Link : PC11@cpu IN11@dpc
Link : PC12@cpu IN12@dpc
Link : PC13@cpu IN13@dpc
Link : PC14@cpu IN14@dpc
Link : PC15@cpu IN15@dpc
Link : PC16@cpu IN16@dpc
Link : PC17@cpu IN17@dpc
Link : PC18@cpu IN18@dpc
Link : PC19@cpu IN19@dpc
Link : PC20@cpu IN20@dpc
Link : PC21@cpu IN21@dpc
Link : PC22@cpu IN22@dpc
Link : PC23@cpu IN23@dpc
Link : PC24@cpu IN24@dpc
Link : PC25@cpu IN25@dpc
Link : PC26@cpu IN26@dpc
Link : PC27@cpu IN27@dpc
Link : PC28@cpu IN28@dpc
Link : PC29@cpu IN29@dpc
Link : PC30@cpu IN30@dpc
Link : PC31@cpu IN31@dpc
Link : OUT@dpc PC

Link : OUT_AS@bus AS@csMem
Link : CS@csMem AS@Mem
Link : OUT_A0@bus A0@csMem
Link : OUT_A1@bus A1@csMem
Link : OUT_A2@bus A2@csMem
Link : OUT_A3@bus A3@csMem
Link : OUT_A4@bus A4@csMem
Link : OUT_A5@bus A5@csMem
Link : OUT_A6@bus A6@csMem
Link : OUT_A7@bus A7@csMem
Link : OUT_A8@bus A8@csMem
Link : OUT_A9@bus A9@csMem
Link : OUT_A10@bus A10@csMem
Link : OUT_A11@bus A11@csMem
Link : OUT_A12@bus A12@csMem
Link : OUT_A13@bus A13@csMem
Link : OUT_A14@bus A14@csMem
Link : OUT_A15@bus A15@csMem
Link : OUT_A16@bus A16@csMem
Link : OUT_A17@bus A17@csMem
Link : OUT_A18@bus A18@csMem
Link : OUT_A19@bus A19@csMem
Link : OUT_A20@bus A20@csMem
Link : OUT_A21@bus A21@csMem
Link : OUT_A22@bus A22@csMem
Link : OUT_A23@bus A23@csMem
Link : OUT_A24@bus A24@csMem
Link : OUT_A25@bus A25@csMem
Link : OUT_A26@bus A26@csMem
Link : OUT_A27@bus A27@csMem
Link : OUT_A28@bus A28@csMem
Link : OUT_A29@bus A29@csMem
Link : OUT_A30@bus A30@csMem
Link : OUT_A31@bus A31@csMem
Link : OUT_A2@bus A2@Mem
Link : OUT_A3@bus A3@Mem
Link : OUT_A4@bus A4@Mem
Link : OUT_A5@bus A5@Mem
Link : OUT_A6@bus A6@Mem
Link : OUT_A7@bus A7@Mem
Link : OUT_A8@bus A8@Mem
Link : OUT_A9@bus A9@Mem
Link : OUT_A10@bus A10@Mem
Link : OUT_A11@bus A11@Mem
Link : OUT_A12@bus A12@Mem
Link : OUT_A13@bus A13@Mem
Link : OUT_A14@bus A14@Mem
Link : OUT_A15@bus A15@Mem
Link : OUT_A16@bus A16@Mem
Link : OUT_A17@bus A17@Mem
Link : OUT_A18@bus A18@Mem
Link : OUT_A19@bus A19@Mem
Link : OUT_A20@bus A20@Mem
Link : OUT_A21@bus A21@Mem
Link : OUT_A22@bus A22@Mem
Link : OUT_A23@bus A23@Mem
Link : OUT_A24@bus A24@Mem
Link : OUT_A25@bus A25@Mem
Link : OUT_A26@bus A26@Mem
Link : OUT_A27@bus A27@Mem
Link : OUT_A28@bus A28@Mem
Link : OUT_A29@bus A29@Mem
Link : OUT_A30@bus A30@Mem
Link : OUT_A31@bus A31@Mem

Link : OUT_DATA0@Mem IN_DATA0@cpu
Link : OUT_DATA1@Mem IN_DATA1@cpu
Link : OUT_DATA2@Mem IN_DATA2@cpu
Link : OUT_DATA3@Mem IN_DATA3@cpu
Link : OUT_DATA4@Mem IN_DATA4@cpu
Link : OUT_DATA5@Mem IN_DATA5@cpu
Link : OUT_DATA6@Mem IN_DATA6@cpu
Link : OUT_DATA7@Mem IN_DATA7@cpu
Link : OUT_DATA8@Mem IN_DATA8@cpu
Link : OUT_DATA9@Mem IN_DATA9@cpu
Link : OUT_DATA10@Mem IN_DATA10@cpu
Link : OUT_DATA11@Mem IN_DATA11@cpu
Link : OUT_DATA12@Mem IN_DATA12@cpu
Link : OUT_DATA13@Mem IN_DATA13@cpu
Link : OUT_DATA14@Mem IN_DATA14@cpu
Link : OUT_DATA15@Mem IN_DATA15@cpu
Link : OUT_DATA16@Mem IN_DATA16@cpu
Link : OUT_DATA17@Mem IN_DATA17@cpu
Link : OUT_DATA18@Mem IN_DATA18@cpu
Link : OUT_DATA19@Mem IN_DATA19@cpu
Link : OUT_DATA20@Mem IN_DATA20@cpu
Link : OUT_DATA21@Mem IN_DATA21@cpu
Link : OUT_DATA22@Mem IN_DATA22@cpu
Link : OUT_DATA23@Mem IN_DATA23@cpu
Link : OUT_DATA24@Mem IN_DATA24@cpu
Link : OUT_DATA25@Mem IN_DATA25@cpu
Link : OUT_DATA26@Mem IN_DATA26@cpu
Link : OUT_DATA27@Mem IN_DATA27@cpu
Link : OUT_DATA28@Mem IN_DATA28@cpu
Link : OUT_DATA29@Mem IN_DATA29@cpu
Link : OUT_DATA30@Mem IN_DATA30@cpu
Link : OUT_DATA31@Mem IN_DATA31@cpu
Link : OUT_DATA0@cpu IN_DATA0@Mem
Link : OUT_DATA1@cpu IN_DATA1@Mem
Link : OUT_DATA2@cpu IN_DATA2@Mem
Link : OUT_DATA3@cpu IN_DATA3@Mem
Link : OUT_DATA4@cpu IN_DATA4@Mem
Link : OUT_DATA5@cpu IN_DATA5@Mem
Link : OUT_DATA6@cpu IN_DATA6@Mem
Link : OUT_DATA7@cpu IN_DATA7@Mem
Link : OUT_DATA8@cpu IN_DATA8@Mem
Link : OUT_DATA9@cpu IN_DATA9@Mem
Link : OUT_DATA10@cpu IN_DATA10@Mem
Link : OUT_DATA11@cpu IN_DATA11@Mem
Link : OUT_DATA12@cpu IN_DATA12@Mem
Link : OUT_DATA13@cpu IN_DATA13@Mem
Link : OUT_DATA14@cpu IN_DATA14@Mem
Link : OUT_DATA15@cpu IN_DATA15@Mem
Link : OUT_DATA16@cpu IN_DATA16@Mem
Link : OUT_DATA17@cpu IN_DATA17@Mem
Link : OUT_DATA18@cpu IN_DATA18@Mem
Link : OUT_DATA19@cpu IN_DATA19@Mem
Link : OUT_DATA20@cpu IN_DATA20@Mem
Link : OUT_DATA21@cpu IN_DATA21@Mem
Link : OUT_DATA22@cpu IN_DATA22@Mem
Link : OUT_DATA23@cpu IN_DATA23@Mem
Link : OUT_DATA24@cpu IN_DATA24@Mem
Link : OUT_DATA25@cpu IN_DATA25@Mem
Link : OUT_DATA26@cpu IN_DATA26@Mem
Link : OUT_DATA27@cpu IN_DATA27@Mem
Link : OUT_DATA28@cpu IN_DATA28@Mem
Link : OUT_DATA29@cpu IN_DATA29@Mem
Link : OUT_DATA30@cpu IN_DATA30@Mem
Link : OUT_DATA31@cpu IN_DATA31@Mem

Link : AS@cpu IN_AS@bus
Link : DTACK@Mem IN_DTACK@bus
Link : OUT_DTACK@bus DTACK@cpu
Link : OUT_RD_WR@bus RD_WR@Mem
Link : RD_WR@cpu IN_RD_WR@bus
Link : A0@cpu IN_A0@bus
Link : A1@cpu IN_A1@bus
Link : A2@cpu IN_A2@bus
Link : A3@cpu IN_A3@bus
Link : A4@cpu IN_A4@bus
Link : A5@cpu IN_A5@bus
Link : A6@cpu IN_A6@bus
Link : A7@cpu IN_A7@bus
Link : A8@cpu IN_A8@bus
Link : A9@cpu IN_A9@bus
Link : A10@cpu IN_A10@bus
Link : A11@cpu IN_A11@bus
Link : A12@cpu IN_A12@bus
Link : A13@cpu IN_A13@bus
Link : A14@cpu IN_A14@bus
Link : A15@cpu IN_A15@bus
Link : A16@cpu IN_A16@bus
Link : A17@cpu IN_A17@bus
Link : A18@cpu IN_A18@bus
Link : A19@cpu IN_A19@bus
Link : A20@cpu IN_A20@bus
Link : A21@cpu IN_A21@bus
Link : A22@cpu IN_A22@bus
Link : A23@cpu IN_A23@bus
Link : A24@cpu IN_A24@bus
Link : A25@cpu IN_A25@bus
Link : A26@cpu IN_A26@bus
Link : A27@cpu IN_A27@bus
Link : A28@cpu IN_A28@bus
Link : A29@cpu IN_A29@bus
Link : A30@cpu IN_A30@bus
Link : A31@cpu IN_A31@bus
Link : OUT_BSEL0@bus BSEL0@Mem
Link : OUT_BSEL1@bus BSEL1@Mem
Link : OUT_BSEL2@bus BSEL2@Mem
Link : OUT_BSEL3@bus BSEL3@Mem
Link : BSEL0@cpu IN_BSEL0@bus
Link : BSEL1@cpu IN_BSEL1@bus
Link : BSEL2@cpu IN_BSEL2@bus
Link : BSEL3@cpu IN_BSEL3@bus
OUT0@c1 RESET@Mem

[cpu]
components : 
ir@latch
pc_add@adder
pc_mux@muxn
npc_latch@latch
npc@latch
pc_latch@latch
pc@latch
pc_inc@inc4
addr_mux@mux
a_mux@mux
b_mux@mux
c_mux@muxn
a_latch@latch
b_latch@latch
c_latch@latch
alu_res@latch
data_out@latch
align_out@aligns
data_in@latch
align_in@alignl
regfile
aluf

uc@uc
cclogic@cclogic
clock@clock
disp_mux@mux

cc@latch
cc_latch@latch
cwp@latch
cwp_latch@latch
inc_dec_cwp@incdec
y_latch@latch
y@latch
tba@latch
tt@latch
wim@latch
lim@latch
base@latch
cc_mux@mux
cwp_mux@mux
y_mux@mux
tt_mux@mux
sp_out_mux@muxn


out : A0
out : A1
out : A2
out : A3
out : A4
out : A5
out : A6
out : A7
out : A8
out : A9
out : A10
out : A11
out : A12
out : A13
out : A14
out : A15
out : A16
out : A17
out : A18
out : A19
out : A20
out : A21
out : A22
out : A23
out : A24
out : A25
out : A26
out : A27
out : A28
out : A29
out : A30
out : A31
out : OUT_DATA0
out : OUT_DATA1
out : OUT_DATA2
out : OUT_DATA3
out : OUT_DATA4
out : OUT_DATA5
out : OUT_DATA6
out : OUT_DATA7
out : OUT_DATA8
out : OUT_DATA9
out : OUT_DATA10
out : OUT_DATA11
out : OUT_DATA12
out : OUT_DATA13
out : OUT_DATA14
out : OUT_DATA15
out : OUT_DATA16
out : OUT_DATA17
out : OUT_DATA18
out : OUT_DATA19
out : OUT_DATA20
out : OUT_DATA21
out : OUT_DATA22
out : OUT_DATA23
out : OUT_DATA24
out : OUT_DATA25
out : OUT_DATA26
out : OUT_DATA27
out : OUT_DATA28
out : OUT_DATA29
out : OUT_DATA30
out : OUT_DATA31
in : IN_DATA0
in : IN_DATA1
in : IN_DATA2
in : IN_DATA3
in : IN_DATA4
in : IN_DATA5
in : IN_DATA6
in : IN_DATA7
in : IN_DATA8
in : IN_DATA9
in : IN_DATA10
in : IN_DATA11
in : IN_DATA12
in : IN_DATA13
in : IN_DATA14
in : IN_DATA15
in : IN_DATA16
in : IN_DATA17
in : IN_DATA18
in : IN_DATA19
in : IN_DATA20
in : IN_DATA21
in : IN_DATA22
in : IN_DATA23
in : IN_DATA24
in : IN_DATA25
in : IN_DATA26
in : IN_DATA27
in : IN_DATA28
in : IN_DATA29
in : IN_DATA30
in : IN_DATA31

out : AS RD_WR
in : DTACK
out : BSEL0
out : BSEL1
out : BSEL2
out : BSEL3

out : HALT
Link : HALT@uc HALT
out : PC0
out : PC1
out : PC2
out : PC3
out : PC4
out : PC5
out : PC6
out : PC7
out : PC8
out : PC9
out : PC10
out : PC11
out : PC12
out : PC13
out : PC14
out : PC15
out : PC16
out : PC17
out : PC18
out : PC19
out : PC20
out : PC21
out : PC22
out : PC23
out : PC24
out : PC25
out : PC26
out : PC27
out : PC28
out : PC29
out : PC30
out : PC31
Link : OUT0@pc PC0
Link : OUT1@pc PC1
Link : OUT2@pc PC2
Link : OUT3@pc PC3
Link : OUT4@pc PC4
Link : OUT5@pc PC5
Link : OUT6@pc PC6
Link : OUT7@pc PC7
Link : OUT8@pc PC8
Link : OUT9@pc PC9
Link : OUT10@pc PC10
Link : OUT11@pc PC11
Link : OUT12@pc PC12
Link : OUT13@pc PC13
Link : OUT14@pc PC14
Link : OUT15@pc PC15
Link : OUT16@pc PC16
Link : OUT17@pc PC17
Link : OUT18@pc PC18
Link : OUT19@pc PC19
Link : OUT20@pc PC20
Link : OUT21@pc PC21
Link : OUT22@pc PC22
Link : OUT23@pc PC23
Link : OUT24@pc PC24
Link : OUT25@pc PC25
Link : OUT26@pc PC26
Link : OUT27@pc PC27
Link : OUT28@pc PC28
Link : OUT29@pc PC29
Link : OUT30@pc PC30
Link : OUT31@pc PC31
Link : HALT@uc STOP@clock



Link :

OUT0@addr_mux A0
OUT1@addr_mux A1
OUT2@addr_mux A2
OUT3@addr_mux A3
OUT4@addr_mux A4
OUT5@addr_mux A5
OUT6@addr_mux A6
OUT7@addr_mux A7
OUT8@addr_mux A8
OUT9@addr_mux A9
OUT10@addr_mux A10
OUT11@addr_mux A11
OUT12@addr_mux A12
OUT13@addr_mux A13
OUT14@addr_mux A14
OUT15@addr_mux A15
OUT16@addr_mux A16
OUT17@addr_mux A17
OUT18@addr_mux A18
OUT19@addr_mux A19
OUT20@addr_mux A20
OUT21@addr_mux A21
OUT22@addr_mux A22
OUT23@addr_mux A23
OUT24@addr_mux A24
OUT25@addr_mux A25
OUT26@addr_mux A26
OUT27@addr_mux A27
OUT28@addr_mux A28
OUT29@addr_mux A29
OUT30@addr_mux A30
OUT31@addr_mux A31

RES0@align_out OUT_DATA0
RES1@align_out OUT_DATA1
RES2@align_out OUT_DATA2
RES3@align_out OUT_DATA3
RES4@align_out OUT_DATA4
RES5@align_out OUT_DATA5
RES6@align_out OUT_DATA6
RES7@align_out OUT_DATA7
RES8@align_out OUT_DATA8
RES9@align_out OUT_DATA9
RES10@align_out OUT_DATA10
RES11@align_out OUT_DATA11
RES12@align_out OUT_DATA12
RES13@align_out OUT_DATA13
RES14@align_out OUT_DATA14
RES15@align_out OUT_DATA15
RES16@align_out OUT_DATA16
RES17@align_out OUT_DATA17
RES18@align_out OUT_DATA18
RES19@align_out OUT_DATA19
RES20@align_out OUT_DATA20
RES21@align_out OUT_DATA21
RES22@align_out OUT_DATA22
RES23@align_out OUT_DATA23
RES24@align_out OUT_DATA24
RES25@align_out OUT_DATA25
RES26@align_out OUT_DATA26
RES27@align_out OUT_DATA27
RES28@align_out OUT_DATA28
RES29@align_out OUT_DATA29
RES30@align_out OUT_DATA30
RES31@align_out OUT_DATA31

IN_DATA0 IN0@ir
IN_DATA1 IN1@ir
IN_DATA2 IN2@ir
IN_DATA3 IN3@ir
IN_DATA4 IN4@ir
IN_DATA5 IN5@ir
IN_DATA6 IN6@ir
IN_DATA7 IN7@ir
IN_DATA8 IN8@ir
IN_DATA9 IN9@ir
IN_DATA10 IN10@ir
IN_DATA11 IN11@ir
IN_DATA12 IN12@ir
IN_DATA13 IN13@ir
IN_DATA14 IN14@ir
IN_DATA15 IN15@ir
IN_DATA16 IN16@ir
IN_DATA17 IN17@ir
IN_DATA18 IN18@ir
IN_DATA19 IN19@ir
IN_DATA20 IN20@ir
IN_DATA21 IN21@ir
IN_DATA22 IN22@ir
IN_DATA23 IN23@ir
IN_DATA24 IN24@ir
IN_DATA25 IN25@ir
IN_DATA26 IN26@ir
IN_DATA27 IN27@ir
IN_DATA28 IN28@ir
IN_DATA29 IN29@ir
IN_DATA30 IN30@ir
IN_DATA31 IN31@ir
IN_DATA0 IN0@data_in
IN_DATA1 IN1@data_in
IN_DATA2 IN2@data_in
IN_DATA3 IN3@data_in
IN_DATA4 IN4@data_in
IN_DATA5 IN5@data_in
IN_DATA6 IN6@data_in
IN_DATA7 IN7@data_in
IN_DATA8 IN8@data_in
IN_DATA9 IN9@data_in
IN_DATA10 IN10@data_in
IN_DATA11 IN11@data_in
IN_DATA12 IN12@data_in
IN_DATA13 IN13@data_in
IN_DATA14 IN14@data_in
IN_DATA15 IN15@data_in
IN_DATA16 IN16@data_in
IN_DATA17 IN17@data_in
IN_DATA18 IN18@data_in
IN_DATA19 IN19@data_in
IN_DATA20 IN20@data_in
IN_DATA21 IN21@data_in
IN_DATA22 IN22@data_in
IN_DATA23 IN23@data_in
IN_DATA24 IN24@data_in
IN_DATA25 IN25@data_in
IN_DATA26 IN26@data_in
IN_DATA27 IN27@data_in
IN_DATA28 IN28@data_in
IN_DATA29 IN29@data_in
IN_DATA30 IN30@data_in
IN_DATA31 IN31@data_in

OUT0@pc_mux IN0@npc_latch
OUT1@pc_mux IN1@npc_latch
OUT2@pc_mux IN2@npc_latch
OUT3@pc_mux IN3@npc_latch
OUT4@pc_mux IN4@npc_latch
OUT5@pc_mux IN5@npc_latch
OUT6@pc_mux IN6@npc_latch
OUT7@pc_mux IN7@npc_latch
OUT8@pc_mux IN8@npc_latch
OUT9@pc_mux IN9@npc_latch
OUT10@pc_mux IN10@npc_latch
OUT11@pc_mux IN11@npc_latch
OUT12@pc_mux IN12@npc_latch
OUT13@pc_mux IN13@npc_latch
OUT14@pc_mux IN14@npc_latch
OUT15@pc_mux IN15@npc_latch
OUT16@pc_mux IN16@npc_latch
OUT17@pc_mux IN17@npc_latch
OUT18@pc_mux IN18@npc_latch
OUT19@pc_mux IN19@npc_latch
OUT20@pc_mux IN20@npc_latch
OUT21@pc_mux IN21@npc_latch
OUT22@pc_mux IN22@npc_latch
OUT23@pc_mux IN23@npc_latch
OUT24@pc_mux IN24@npc_latch
OUT25@pc_mux IN25@npc_latch
OUT26@pc_mux IN26@npc_latch
OUT27@pc_mux IN27@npc_latch
OUT28@pc_mux IN28@npc_latch
OUT29@pc_mux IN29@npc_latch
OUT30@pc_mux IN30@npc_latch
OUT31@pc_mux IN31@npc_latch
OUT0@npc_latch IN0@npc
OUT1@npc_latch IN1@npc
OUT2@npc_latch IN2@npc
OUT3@npc_latch IN3@npc
OUT4@npc_latch IN4@npc
OUT5@npc_latch IN5@npc
OUT6@npc_latch IN6@npc
OUT7@npc_latch IN7@npc
OUT8@npc_latch IN8@npc
OUT9@npc_latch IN9@npc
OUT10@npc_latch IN10@npc
OUT11@npc_latch IN11@npc
OUT12@npc_latch IN12@npc
OUT13@npc_latch IN13@npc
OUT14@npc_latch IN14@npc
OUT15@npc_latch IN15@npc
OUT16@npc_latch IN16@npc
OUT17@npc_latch IN17@npc
OUT18@npc_latch IN18@npc
OUT19@npc_latch IN19@npc
OUT20@npc_latch IN20@npc
OUT21@npc_latch IN21@npc
OUT22@npc_latch IN22@npc
OUT23@npc_latch IN23@npc
OUT24@npc_latch IN24@npc
OUT25@npc_latch IN25@npc
OUT26@npc_latch IN26@npc
OUT27@npc_latch IN27@npc
OUT28@npc_latch IN28@npc
OUT29@npc_latch IN29@npc
OUT30@npc_latch IN30@npc
OUT31@npc_latch IN31@npc
OUT0@npc IN0@pc_latch
OUT1@npc IN1@pc_latch
OUT2@npc IN2@pc_latch
OUT3@npc IN3@pc_latch
OUT4@npc IN4@pc_latch
OUT5@npc IN5@pc_latch
OUT6@npc IN6@pc_latch
OUT7@npc IN7@pc_latch
OUT8@npc IN8@pc_latch
OUT9@npc IN9@pc_latch
OUT10@npc IN10@pc_latch
OUT11@npc IN11@pc_latch
OUT12@npc IN12@pc_latch
OUT13@npc IN13@pc_latch
OUT14@npc IN14@pc_latch
OUT15@npc IN15@pc_latch
OUT16@npc IN16@pc_latch
OUT17@npc IN17@pc_latch
OUT18@npc IN18@pc_latch
OUT19@npc IN19@pc_latch
OUT20@npc IN20@pc_latch
OUT21@npc IN21@pc_latch
OUT22@npc IN22@pc_latch
OUT23@npc IN23@pc_latch
OUT24@npc IN24@pc_latch
OUT25@npc IN25@pc_latch
OUT26@npc IN26@pc_latch
OUT27@npc IN27@pc_latch
OUT28@npc IN28@pc_latch
OUT29@npc IN29@pc_latch
OUT30@npc IN30@pc_latch
OUT31@npc IN31@pc_latch
OUT0@pc_latch IN0@pc
OUT1@pc_latch IN1@pc
OUT2@pc_latch IN2@pc
OUT3@pc_latch IN3@pc
OUT4@pc_latch IN4@pc
OUT5@pc_latch IN5@pc
OUT6@pc_latch IN6@pc
OUT7@pc_latch IN7@pc
OUT8@pc_latch IN8@pc
OUT9@pc_latch IN9@pc
OUT10@pc_latch IN10@pc
OUT11@pc_latch IN11@pc
OUT12@pc_latch IN12@pc
OUT13@pc_latch IN13@pc
OUT14@pc_latch IN14@pc
OUT15@pc_latch IN15@pc
OUT16@pc_latch IN16@pc
OUT17@pc_latch IN17@pc
OUT18@pc_latch IN18@pc
OUT19@pc_latch IN19@pc
OUT20@pc_latch IN20@pc
OUT21@pc_latch IN21@pc
OUT22@pc_latch IN22@pc
OUT23@pc_latch IN23@pc
OUT24@pc_latch IN24@pc
OUT25@pc_latch IN25@pc
OUT26@pc_latch IN26@pc
OUT27@pc_latch IN27@pc
OUT28@pc_latch IN28@pc
OUT29@pc_latch IN29@pc
OUT30@pc_latch IN30@pc
OUT31@pc_latch IN31@pc

OUT0@npc OP0@pc_inc
OUT1@npc OP1@pc_inc
OUT2@npc OP2@pc_inc
OUT3@npc OP3@pc_inc
OUT4@npc OP4@pc_inc
OUT5@npc OP5@pc_inc
OUT6@npc OP6@pc_inc
OUT7@npc OP7@pc_inc
OUT8@npc OP8@pc_inc
OUT9@npc OP9@pc_inc
OUT10@npc OP10@pc_inc
OUT11@npc OP11@pc_inc
OUT12@npc OP12@pc_inc
OUT13@npc OP13@pc_inc
OUT14@npc OP14@pc_inc
OUT15@npc OP15@pc_inc
OUT16@npc OP16@pc_inc
OUT17@npc OP17@pc_inc
OUT18@npc OP18@pc_inc
OUT19@npc OP19@pc_inc
OUT20@npc OP20@pc_inc
OUT21@npc OP21@pc_inc
OUT22@npc OP22@pc_inc
OUT23@npc OP23@pc_inc
OUT24@npc OP24@pc_inc
OUT25@npc OP25@pc_inc
OUT26@npc OP26@pc_inc
OUT27@npc OP27@pc_inc
OUT28@npc OP28@pc_inc
OUT29@npc OP29@pc_inc
OUT30@npc OP30@pc_inc
OUT31@npc OP31@pc_inc
OUT0@pc OPA0@pc_add
OUT1@pc OPA1@pc_add
OUT2@pc OPA2@pc_add
OUT3@pc OPA3@pc_add
OUT4@pc OPA4@pc_add
OUT5@pc OPA5@pc_add
OUT6@pc OPA6@pc_add
OUT7@pc OPA7@pc_add
OUT8@pc OPA8@pc_add
OUT9@pc OPA9@pc_add
OUT10@pc OPA10@pc_add
OUT11@pc OPA11@pc_add
OUT12@pc OPA12@pc_add
OUT13@pc OPA13@pc_add
OUT14@pc OPA14@pc_add
OUT15@pc OPA15@pc_add
OUT16@pc OPA16@pc_add
OUT17@pc OPA17@pc_add
OUT18@pc OPA18@pc_add
OUT19@pc OPA19@pc_add
OUT20@pc OPA20@pc_add
OUT21@pc OPA21@pc_add
OUT22@pc OPA22@pc_add
OUT23@pc OPA23@pc_add
OUT24@pc OPA24@pc_add
OUT25@pc OPA25@pc_add
OUT26@pc OPA26@pc_add
OUT27@pc OPA27@pc_add
OUT28@pc OPA28@pc_add
OUT29@pc OPA29@pc_add
OUT30@pc OPA30@pc_add
OUT31@pc OPA31@pc_add
OUT0@pc A0@addr_mux
OUT1@pc A1@addr_mux
OUT2@pc A2@addr_mux
OUT3@pc A3@addr_mux
OUT4@pc A4@addr_mux
OUT5@pc A5@addr_mux
OUT6@pc A6@addr_mux
OUT7@pc A7@addr_mux
OUT8@pc A8@addr_mux
OUT9@pc A9@addr_mux
OUT10@pc A10@addr_mux
OUT11@pc A11@addr_mux
OUT12@pc A12@addr_mux
OUT13@pc A13@addr_mux
OUT14@pc A14@addr_mux
OUT15@pc A15@addr_mux
OUT16@pc A16@addr_mux
OUT17@pc A17@addr_mux
OUT18@pc A18@addr_mux
OUT19@pc A19@addr_mux
OUT20@pc A20@addr_mux
OUT21@pc A21@addr_mux
OUT22@pc A22@addr_mux
OUT23@pc A23@addr_mux
OUT24@pc A24@addr_mux
OUT25@pc A25@addr_mux
OUT26@pc A26@addr_mux
OUT27@pc A27@addr_mux
OUT28@pc A28@addr_mux
OUT29@pc A29@addr_mux
OUT30@pc A30@addr_mux
OUT31@pc A31@addr_mux
OUT0@pc C0@c_mux
OUT1@pc C1@c_mux
OUT2@pc C2@c_mux
OUT3@pc C3@c_mux
OUT4@pc C4@c_mux
OUT5@pc C5@c_mux
OUT6@pc C6@c_mux
OUT7@pc C7@c_mux
OUT8@pc C8@c_mux
OUT9@pc C9@c_mux
OUT10@pc C10@c_mux
OUT11@pc C11@c_mux
OUT12@pc C12@c_mux
OUT13@pc C13@c_mux
OUT14@pc C14@c_mux
OUT15@pc C15@c_mux
OUT16@pc C16@c_mux
OUT17@pc C17@c_mux
OUT18@pc C18@c_mux
OUT19@pc C19@c_mux
OUT20@pc C20@c_mux
OUT21@pc C21@c_mux
OUT22@pc C22@c_mux
OUT23@pc C23@c_mux
OUT24@pc C24@c_mux
OUT25@pc C25@c_mux
OUT26@pc C26@c_mux
OUT27@pc C27@c_mux
OUT28@pc C28@c_mux
OUT29@pc C29@c_mux
OUT30@pc C30@c_mux
OUT31@pc C31@c_mux

RES0@pc_inc  A0@pc_mux
RES1@pc_inc  A1@pc_mux
RES2@pc_inc  A2@pc_mux
RES3@pc_inc  A3@pc_mux
RES4@pc_inc  A4@pc_mux
RES5@pc_inc  A5@pc_mux
RES6@pc_inc  A6@pc_mux
RES7@pc_inc  A7@pc_mux
RES8@pc_inc  A8@pc_mux
RES9@pc_inc  A9@pc_mux
RES10@pc_inc  A10@pc_mux
RES11@pc_inc  A11@pc_mux
RES12@pc_inc  A12@pc_mux
RES13@pc_inc  A13@pc_mux
RES14@pc_inc  A14@pc_mux
RES15@pc_inc  A15@pc_mux
RES16@pc_inc  A16@pc_mux
RES17@pc_inc  A17@pc_mux
RES18@pc_inc  A18@pc_mux
RES19@pc_inc  A19@pc_mux
RES20@pc_inc  A20@pc_mux
RES21@pc_inc  A21@pc_mux
RES22@pc_inc  A22@pc_mux
RES23@pc_inc  A23@pc_mux
RES24@pc_inc  A24@pc_mux
RES25@pc_inc  A25@pc_mux
RES26@pc_inc  A26@pc_mux
RES27@pc_inc  A27@pc_mux
RES28@pc_inc  A28@pc_mux
RES29@pc_inc  A29@pc_mux
RES30@pc_inc  A30@pc_mux
RES31@pc_inc  A31@pc_mux
OUT0@alu_res B0@pc_mux
OUT1@alu_res B1@pc_mux
OUT2@alu_res B2@pc_mux
OUT3@alu_res B3@pc_mux
OUT4@alu_res B4@pc_mux
OUT5@alu_res B5@pc_mux
OUT6@alu_res B6@pc_mux
OUT7@alu_res B7@pc_mux
OUT8@alu_res B8@pc_mux
OUT9@alu_res B9@pc_mux
OUT10@alu_res B10@pc_mux
OUT11@alu_res B11@pc_mux
OUT12@alu_res B12@pc_mux
OUT13@alu_res B13@pc_mux
OUT14@alu_res B14@pc_mux
OUT15@alu_res B15@pc_mux
OUT16@alu_res B16@pc_mux
OUT17@alu_res B17@pc_mux
OUT18@alu_res B18@pc_mux
OUT19@alu_res B19@pc_mux
OUT20@alu_res B20@pc_mux
OUT21@alu_res B21@pc_mux
OUT22@alu_res B22@pc_mux
OUT23@alu_res B23@pc_mux
OUT24@alu_res B24@pc_mux
OUT25@alu_res B25@pc_mux
OUT26@alu_res B26@pc_mux
OUT27@alu_res B27@pc_mux
OUT28@alu_res B28@pc_mux
OUT29@alu_res B29@pc_mux
OUT30@alu_res B30@pc_mux
OUT31@alu_res B31@pc_mux
RES0@pc_add  C0@pc_mux
RES1@pc_add  C1@pc_mux
RES2@pc_add  C2@pc_mux
RES3@pc_add  C3@pc_mux
RES4@pc_add  C4@pc_mux
RES5@pc_add  C5@pc_mux
RES6@pc_add  C6@pc_mux
RES7@pc_add  C7@pc_mux
RES8@pc_add  C8@pc_mux
RES9@pc_add  C9@pc_mux
RES10@pc_add  C10@pc_mux
RES11@pc_add  C11@pc_mux
RES12@pc_add  C12@pc_mux
RES13@pc_add  C13@pc_mux
RES14@pc_add  C14@pc_mux
RES15@pc_add  C15@pc_mux
RES16@pc_add  C16@pc_mux
RES17@pc_add  C17@pc_mux
RES18@pc_add  C18@pc_mux
RES19@pc_add  C19@pc_mux
RES20@pc_add  C20@pc_mux
RES21@pc_add  C21@pc_mux
RES22@pc_add  C22@pc_mux
RES23@pc_add  C23@pc_mux
RES24@pc_add  C24@pc_mux
RES25@pc_add  C25@pc_mux
RES26@pc_add  C26@pc_mux
RES27@pc_add  C27@pc_mux
RES28@pc_add  C28@pc_mux
RES29@pc_add  C29@pc_mux
RES30@pc_add  C30@pc_mux
RES31@pc_add  C31@pc_mux

OUT0@alu_res B0@addr_mux
OUT1@alu_res B1@addr_mux
OUT2@alu_res B2@addr_mux
OUT3@alu_res B3@addr_mux
OUT4@alu_res B4@addr_mux
OUT5@alu_res B5@addr_mux
OUT6@alu_res B6@addr_mux
OUT7@alu_res B7@addr_mux
OUT8@alu_res B8@addr_mux
OUT9@alu_res B9@addr_mux
OUT10@alu_res B10@addr_mux
OUT11@alu_res B11@addr_mux
OUT12@alu_res B12@addr_mux
OUT13@alu_res B13@addr_mux
OUT14@alu_res B14@addr_mux
OUT15@alu_res B15@addr_mux
OUT16@alu_res B16@addr_mux
OUT17@alu_res B17@addr_mux
OUT18@alu_res B18@addr_mux
OUT19@alu_res B19@addr_mux
OUT20@alu_res B20@addr_mux
OUT21@alu_res B21@addr_mux
OUT22@alu_res B22@addr_mux
OUT23@alu_res B23@addr_mux
OUT24@alu_res B24@addr_mux
OUT25@alu_res B25@addr_mux
OUT26@alu_res B26@addr_mux
OUT27@alu_res B27@addr_mux
OUT28@alu_res B28@addr_mux
OUT29@alu_res B29@addr_mux
OUT30@alu_res B30@addr_mux
OUT31@alu_res B31@addr_mux
OUT0@alu_res A0@c_mux
OUT1@alu_res A1@c_mux
OUT2@alu_res A2@c_mux
OUT3@alu_res A3@c_mux
OUT4@alu_res A4@c_mux
OUT5@alu_res A5@c_mux
OUT6@alu_res A6@c_mux
OUT7@alu_res A7@c_mux
OUT8@alu_res A8@c_mux
OUT9@alu_res A9@c_mux
OUT10@alu_res A10@c_mux
OUT11@alu_res A11@c_mux
OUT12@alu_res A12@c_mux
OUT13@alu_res A13@c_mux
OUT14@alu_res A14@c_mux
OUT15@alu_res A15@c_mux
OUT16@alu_res A16@c_mux
OUT17@alu_res A17@c_mux
OUT18@alu_res A18@c_mux
OUT19@alu_res A19@c_mux
OUT20@alu_res A20@c_mux
OUT21@alu_res A21@c_mux
OUT22@alu_res A22@c_mux
OUT23@alu_res A23@c_mux
OUT24@alu_res A24@c_mux
OUT25@alu_res A25@c_mux
OUT26@alu_res A26@c_mux
OUT27@alu_res A27@c_mux
OUT28@alu_res A28@c_mux
OUT29@alu_res A29@c_mux
OUT30@alu_res A30@c_mux
OUT31@alu_res A31@c_mux
C0@aluf IN0@alu_res
C1@aluf IN1@alu_res
C2@aluf IN2@alu_res
C3@aluf IN3@alu_res
C4@aluf IN4@alu_res
C5@aluf IN5@alu_res
C6@aluf IN6@alu_res
C7@aluf IN7@alu_res
C8@aluf IN8@alu_res
C9@aluf IN9@alu_res
C10@aluf IN10@alu_res
C11@aluf IN11@alu_res
C12@aluf IN12@alu_res
C13@aluf IN13@alu_res
C14@aluf IN14@alu_res
C15@aluf IN15@alu_res
C16@aluf IN16@alu_res
C17@aluf IN17@alu_res
C18@aluf IN18@alu_res
C19@aluf IN19@alu_res
C20@aluf IN20@alu_res
C21@aluf IN21@alu_res
C22@aluf IN22@alu_res
C23@aluf IN23@alu_res
C24@aluf IN24@alu_res
C25@aluf IN25@alu_res
C26@aluf IN26@alu_res
C27@aluf IN27@alu_res
C28@aluf IN28@alu_res
C29@aluf IN29@alu_res
C30@aluf IN30@alu_res
C31@aluf IN31@alu_res

OUT0@a_latch A0@aluf
OUT1@a_latch A1@aluf
OUT2@a_latch A2@aluf
OUT3@a_latch A3@aluf
OUT4@a_latch A4@aluf
OUT5@a_latch A5@aluf
OUT6@a_latch A6@aluf
OUT7@a_latch A7@aluf
OUT8@a_latch A8@aluf
OUT9@a_latch A9@aluf
OUT10@a_latch A10@aluf
OUT11@a_latch A11@aluf
OUT12@a_latch A12@aluf
OUT13@a_latch A13@aluf
OUT14@a_latch A14@aluf
OUT15@a_latch A15@aluf
OUT16@a_latch A16@aluf
OUT17@a_latch A17@aluf
OUT18@a_latch A18@aluf
OUT19@a_latch A19@aluf
OUT20@a_latch A20@aluf
OUT21@a_latch A21@aluf
OUT22@a_latch A22@aluf
OUT23@a_latch A23@aluf
OUT24@a_latch A24@aluf
OUT25@a_latch A25@aluf
OUT26@a_latch A26@aluf
OUT27@a_latch A27@aluf
OUT28@a_latch A28@aluf
OUT29@a_latch A29@aluf
OUT30@a_latch A30@aluf
OUT31@a_latch A31@aluf
OUT0@b_latch B0@aluf
OUT1@b_latch B1@aluf
OUT2@b_latch B2@aluf
OUT3@b_latch B3@aluf
OUT4@b_latch B4@aluf
OUT5@b_latch B5@aluf
OUT6@b_latch B6@aluf
OUT7@b_latch B7@aluf
OUT8@b_latch B8@aluf
OUT9@b_latch B9@aluf
OUT10@b_latch B10@aluf
OUT11@b_latch B11@aluf
OUT12@b_latch B12@aluf
OUT13@b_latch B13@aluf
OUT14@b_latch B14@aluf
OUT15@b_latch B15@aluf
OUT16@b_latch B16@aluf
OUT17@b_latch B17@aluf
OUT18@b_latch B18@aluf
OUT19@b_latch B19@aluf
OUT20@b_latch B20@aluf
OUT21@b_latch B21@aluf
OUT22@b_latch B22@aluf
OUT23@b_latch B23@aluf
OUT24@b_latch B24@aluf
OUT25@b_latch B25@aluf
OUT26@b_latch B26@aluf
OUT27@b_latch B27@aluf
OUT28@b_latch B28@aluf
OUT29@b_latch B29@aluf
OUT30@b_latch B30@aluf
OUT31@b_latch B31@aluf

OUT0@a_mux IN0@a_latch
OUT1@a_mux IN1@a_latch
OUT2@a_mux IN2@a_latch
OUT3@a_mux IN3@a_latch
OUT4@a_mux IN4@a_latch
OUT5@a_mux IN5@a_latch
OUT6@a_mux IN6@a_latch
OUT7@a_mux IN7@a_latch
OUT8@a_mux IN8@a_latch
OUT9@a_mux IN9@a_latch
OUT10@a_mux IN10@a_latch
OUT11@a_mux IN11@a_latch
OUT12@a_mux IN12@a_latch
OUT13@a_mux IN13@a_latch
OUT14@a_mux IN14@a_latch
OUT15@a_mux IN15@a_latch
OUT16@a_mux IN16@a_latch
OUT17@a_mux IN17@a_latch
OUT18@a_mux IN18@a_latch
OUT19@a_mux IN19@a_latch
OUT20@a_mux IN20@a_latch
OUT21@a_mux IN21@a_latch
OUT22@a_mux IN22@a_latch
OUT23@a_mux IN23@a_latch
OUT24@a_mux IN24@a_latch
OUT25@a_mux IN25@a_latch
OUT26@a_mux IN26@a_latch
OUT27@a_mux IN27@a_latch
OUT28@a_mux IN28@a_latch
OUT29@a_mux IN29@a_latch
OUT30@a_mux IN30@a_latch
OUT31@a_mux IN31@a_latch
OUT0@b_mux IN0@b_latch
OUT1@b_mux IN1@b_latch
OUT2@b_mux IN2@b_latch
OUT3@b_mux IN3@b_latch
OUT4@b_mux IN4@b_latch
OUT5@b_mux IN5@b_latch
OUT6@b_mux IN6@b_latch
OUT7@b_mux IN7@b_latch
OUT8@b_mux IN8@b_latch
OUT9@b_mux IN9@b_latch
OUT10@b_mux IN10@b_latch
OUT11@b_mux IN11@b_latch
OUT12@b_mux IN12@b_latch
OUT13@b_mux IN13@b_latch
OUT14@b_mux IN14@b_latch
OUT15@b_mux IN15@b_latch
OUT16@b_mux IN16@b_latch
OUT17@b_mux IN17@b_latch
OUT18@b_mux IN18@b_latch
OUT19@b_mux IN19@b_latch
OUT20@b_mux IN20@b_latch
OUT21@b_mux IN21@b_latch
OUT22@b_mux IN22@b_latch
OUT23@b_mux IN23@b_latch
OUT24@b_mux IN24@b_latch
OUT25@b_mux IN25@b_latch
OUT26@b_mux IN26@b_latch
OUT27@b_mux IN27@b_latch
OUT28@b_mux IN28@b_latch
OUT29@b_mux IN29@b_latch
OUT30@b_mux IN30@b_latch
OUT31@b_mux IN31@b_latch

A0@regfile A0@a_mux
A1@regfile A1@a_mux
A2@regfile A2@a_mux
A3@regfile A3@a_mux
A4@regfile A4@a_mux
A5@regfile A5@a_mux
A6@regfile A6@a_mux
A7@regfile A7@a_mux
A8@regfile A8@a_mux
A9@regfile A9@a_mux
A10@regfile A10@a_mux
A11@regfile A11@a_mux
A12@regfile A12@a_mux
A13@regfile A13@a_mux
A14@regfile A14@a_mux
A15@regfile A15@a_mux
A16@regfile A16@a_mux
A17@regfile A17@a_mux
A18@regfile A18@a_mux
A19@regfile A19@a_mux
A20@regfile A20@a_mux
A21@regfile A21@a_mux
A22@regfile A22@a_mux
A23@regfile A23@a_mux
A24@regfile A24@a_mux
A25@regfile A25@a_mux
A26@regfile A26@a_mux
A27@regfile A27@a_mux
A28@regfile A28@a_mux
A29@regfile A29@a_mux
A30@regfile A30@a_mux
A31@regfile A31@a_mux
B0@regfile A0@b_mux
B1@regfile A1@b_mux
B2@regfile A2@b_mux
B3@regfile A3@b_mux
B4@regfile A4@b_mux
B5@regfile A5@b_mux
B6@regfile A6@b_mux
B7@regfile A7@b_mux
B8@regfile A8@b_mux
B9@regfile A9@b_mux
B10@regfile A10@b_mux
B11@regfile A11@b_mux
B12@regfile A12@b_mux
B13@regfile A13@b_mux
B14@regfile A14@b_mux
B15@regfile A15@b_mux
B16@regfile A16@b_mux
B17@regfile A17@b_mux
B18@regfile A18@b_mux
B19@regfile A19@b_mux
B20@regfile A20@b_mux
B21@regfile A21@b_mux
B22@regfile A22@b_mux
B23@regfile A23@b_mux
B24@regfile A24@b_mux
B25@regfile A25@b_mux
B26@regfile A26@b_mux
B27@regfile A27@b_mux
B28@regfile A28@b_mux
B29@regfile A29@b_mux
B30@regfile A30@b_mux
B31@regfile A31@b_mux

A0@regfile IN0@data_out
A1@regfile IN1@data_out
A2@regfile IN2@data_out
A3@regfile IN3@data_out
A4@regfile IN4@data_out
A5@regfile IN5@data_out
A6@regfile IN6@data_out
A7@regfile IN7@data_out
A8@regfile IN8@data_out
A9@regfile IN9@data_out
A10@regfile IN10@data_out
A11@regfile IN11@data_out
A12@regfile IN12@data_out
A13@regfile IN13@data_out
A14@regfile IN14@data_out
A15@regfile IN15@data_out
A16@regfile IN16@data_out
A17@regfile IN17@data_out
A18@regfile IN18@data_out
A19@regfile IN19@data_out
A20@regfile IN20@data_out
A21@regfile IN21@data_out
A22@regfile IN22@data_out
A23@regfile IN23@data_out
A24@regfile IN24@data_out
A25@regfile IN25@data_out
A26@regfile IN26@data_out
A27@regfile IN27@data_out
A28@regfile IN28@data_out
A29@regfile IN29@data_out
A30@regfile IN30@data_out
A31@regfile IN31@data_out
OUT0@data_out OP0@align_out
OUT1@data_out OP1@align_out
OUT2@data_out OP2@align_out
OUT3@data_out OP3@align_out
OUT4@data_out OP4@align_out
OUT5@data_out OP5@align_out
OUT6@data_out OP6@align_out
OUT7@data_out OP7@align_out
OUT8@data_out OP8@align_out
OUT9@data_out OP9@align_out
OUT10@data_out OP10@align_out
OUT11@data_out OP11@align_out
OUT12@data_out OP12@align_out
OUT13@data_out OP13@align_out
OUT14@data_out OP14@align_out
OUT15@data_out OP15@align_out
OUT16@data_out OP16@align_out
OUT17@data_out OP17@align_out
OUT18@data_out OP18@align_out
OUT19@data_out OP19@align_out
OUT20@data_out OP20@align_out
OUT21@data_out OP21@align_out
OUT22@data_out OP22@align_out
OUT23@data_out OP23@align_out
OUT24@data_out OP24@align_out
OUT25@data_out OP25@align_out
OUT26@data_out OP26@align_out
OUT27@data_out OP27@align_out
OUT28@data_out OP28@align_out
OUT29@data_out OP29@align_out
OUT30@data_out OP30@align_out
OUT31@data_out OP31@align_out
OUT0@data_in  OP0@align_in
OUT1@data_in  OP1@align_in
OUT2@data_in  OP2@align_in
OUT3@data_in  OP3@align_in
OUT4@data_in  OP4@align_in
OUT5@data_in  OP5@align_in
OUT6@data_in  OP6@align_in
OUT7@data_in  OP7@align_in
OUT8@data_in  OP8@align_in
OUT9@data_in  OP9@align_in
OUT10@data_in  OP10@align_in
OUT11@data_in  OP11@align_in
OUT12@data_in  OP12@align_in
OUT13@data_in  OP13@align_in
OUT14@data_in  OP14@align_in
OUT15@data_in  OP15@align_in
OUT16@data_in  OP16@align_in
OUT17@data_in  OP17@align_in
OUT18@data_in  OP18@align_in
OUT19@data_in  OP19@align_in
OUT20@data_in  OP20@align_in
OUT21@data_in  OP21@align_in
OUT22@data_in  OP22@align_in
OUT23@data_in  OP23@align_in
OUT24@data_in  OP24@align_in
OUT25@data_in  OP25@align_in
OUT26@data_in  OP26@align_in
OUT27@data_in  OP27@align_in
OUT28@data_in  OP28@align_in
OUT29@data_in  OP29@align_in
OUT30@data_in  OP30@align_in
OUT31@data_in  OP31@align_in
RES0@align_in D0@c_mux
RES1@align_in D1@c_mux
RES2@align_in D2@c_mux
RES3@align_in D3@c_mux
RES4@align_in D4@c_mux
RES5@align_in D5@c_mux
RES6@align_in D6@c_mux
RES7@align_in D7@c_mux
RES8@align_in D8@c_mux
RES9@align_in D9@c_mux
RES10@align_in D10@c_mux
RES11@align_in D11@c_mux
RES12@align_in D12@c_mux
RES13@align_in D13@c_mux
RES14@align_in D14@c_mux
RES15@align_in D15@c_mux
RES16@align_in D16@c_mux
RES17@align_in D17@c_mux
RES18@align_in D18@c_mux
RES19@align_in D19@c_mux
RES20@align_in D20@c_mux
RES21@align_in D21@c_mux
RES22@align_in D22@c_mux
RES23@align_in D23@c_mux
RES24@align_in D24@c_mux
RES25@align_in D25@c_mux
RES26@align_in D26@c_mux
RES27@align_in D27@c_mux
RES28@align_in D28@c_mux
RES29@align_in D29@c_mux
RES30@align_in D30@c_mux
RES31@align_in D31@c_mux
OUT0@c_mux IN0@c_latch
OUT1@c_mux IN1@c_latch
OUT2@c_mux IN2@c_latch
OUT3@c_mux IN3@c_latch
OUT4@c_mux IN4@c_latch
OUT5@c_mux IN5@c_latch
OUT6@c_mux IN6@c_latch
OUT7@c_mux IN7@c_latch
OUT8@c_mux IN8@c_latch
OUT9@c_mux IN9@c_latch
OUT10@c_mux IN10@c_latch
OUT11@c_mux IN11@c_latch
OUT12@c_mux IN12@c_latch
OUT13@c_mux IN13@c_latch
OUT14@c_mux IN14@c_latch
OUT15@c_mux IN15@c_latch
OUT16@c_mux IN16@c_latch
OUT17@c_mux IN17@c_latch
OUT18@c_mux IN18@c_latch
OUT19@c_mux IN19@c_latch
OUT20@c_mux IN20@c_latch
OUT21@c_mux IN21@c_latch
OUT22@c_mux IN22@c_latch
OUT23@c_mux IN23@c_latch
OUT24@c_mux IN24@c_latch
OUT25@c_mux IN25@c_latch
OUT26@c_mux IN26@c_latch
OUT27@c_mux IN27@c_latch
OUT28@c_mux IN28@c_latch
OUT29@c_mux IN29@c_latch
OUT30@c_mux IN30@c_latch
OUT31@c_mux IN31@c_latch
OUT0@c_latch C0@regfile
OUT1@c_latch C1@regfile
OUT2@c_latch C2@regfile
OUT3@c_latch C3@regfile
OUT4@c_latch C4@regfile
OUT5@c_latch C5@regfile
OUT6@c_latch C6@regfile
OUT7@c_latch C7@regfile
OUT8@c_latch C8@regfile
OUT9@c_latch C9@regfile
OUT10@c_latch C10@regfile
OUT11@c_latch C11@regfile
OUT12@c_latch C12@regfile
OUT13@c_latch C13@regfile
OUT14@c_latch C14@regfile
OUT15@c_latch C15@regfile
OUT16@c_latch C16@regfile
OUT17@c_latch C17@regfile
OUT18@c_latch C18@regfile
OUT19@c_latch C19@regfile
OUT20@c_latch C20@regfile
OUT21@c_latch C21@regfile
OUT22@c_latch C22@regfile
OUT23@c_latch C23@regfile
OUT24@c_latch C24@regfile
OUT25@c_latch C25@regfile
OUT26@c_latch C26@regfile
OUT27@c_latch C27@regfile
OUT28@c_latch C28@regfile
OUT29@c_latch C29@regfile
OUT30@c_latch C30@regfile
OUT31@c_latch C31@regfile

Link :
OUT0@ir B0@b_mux
OUT1@ir B1@b_mux
OUT2@ir B2@b_mux
OUT3@ir B3@b_mux
OUT4@ir B4@b_mux
OUT5@ir B5@b_mux
OUT6@ir B6@b_mux
OUT7@ir B7@b_mux
OUT8@ir B8@b_mux
OUT9@ir B9@b_mux
OUT10@ir B10@b_mux
OUT11@ir B11@b_mux
OUT12@ir B12@b_mux
OUT12@ir B13@b_mux
OUT12@ir B14@b_mux
OUT12@ir B15@b_mux
OUT12@ir B16@b_mux
OUT12@ir B17@b_mux
OUT12@ir B18@b_mux
OUT12@ir B19@b_mux
OUT12@ir B20@b_mux
OUT12@ir B21@b_mux
OUT12@ir B22@b_mux
OUT12@ir B23@b_mux
OUT12@ir B24@b_mux
OUT12@ir B25@b_mux
OUT12@ir B26@b_mux
OUT12@ir B27@b_mux
OUT12@ir B28@b_mux
OUT12@ir B29@b_mux
OUT12@ir B30@b_mux
OUT12@ir B31@b_mux

OUT0@ir B2@disp_mux
OUT1@ir B3@disp_mux
OUT2@ir B4@disp_mux
OUT3@ir B5@disp_mux
OUT4@ir B6@disp_mux
OUT5@ir B7@disp_mux
OUT6@ir B8@disp_mux
OUT7@ir B9@disp_mux
OUT8@ir B10@disp_mux
OUT9@ir B11@disp_mux
OUT10@ir B12@disp_mux
OUT11@ir B13@disp_mux
OUT12@ir B14@disp_mux
OUT13@ir B15@disp_mux
OUT14@ir B16@disp_mux
OUT15@ir B17@disp_mux
OUT16@ir B18@disp_mux
OUT17@ir B19@disp_mux
OUT18@ir B20@disp_mux
OUT19@ir B21@disp_mux
OUT20@ir B22@disp_mux
OUT21@ir B23@disp_mux
OUT21@ir B24@disp_mux
OUT21@ir B25@disp_mux
OUT21@ir B26@disp_mux
OUT21@ir B27@disp_mux
OUT21@ir B28@disp_mux
OUT21@ir B29@disp_mux
OUT21@ir B30@disp_mux
OUT21@ir B31@disp_mux
OUT0@ir A2@disp_mux
OUT1@ir A3@disp_mux
OUT2@ir A4@disp_mux
OUT3@ir A5@disp_mux
OUT4@ir A6@disp_mux
OUT5@ir A7@disp_mux
OUT6@ir A8@disp_mux
OUT7@ir A9@disp_mux
OUT8@ir A10@disp_mux
OUT9@ir A11@disp_mux
OUT10@ir A12@disp_mux
OUT11@ir A13@disp_mux
OUT12@ir A14@disp_mux
OUT13@ir A15@disp_mux
OUT14@ir A16@disp_mux
OUT15@ir A17@disp_mux
OUT16@ir A18@disp_mux
OUT17@ir A19@disp_mux
OUT18@ir A20@disp_mux
OUT19@ir A21@disp_mux
OUT20@ir A22@disp_mux
OUT21@ir A23@disp_mux
OUT22@ir A24@disp_mux
OUT23@ir A25@disp_mux
OUT24@ir A26@disp_mux
OUT25@ir A27@disp_mux
OUT26@ir A28@disp_mux
OUT27@ir A29@disp_mux
OUT28@ir A30@disp_mux
OUT29@ir A31@disp_mux

OUT0@disp_mux OPB0@pc_add
OUT1@disp_mux OPB1@pc_add
OUT2@disp_mux OPB2@pc_add
OUT3@disp_mux OPB3@pc_add
OUT4@disp_mux OPB4@pc_add
OUT5@disp_mux OPB5@pc_add
OUT6@disp_mux OPB6@pc_add
OUT7@disp_mux OPB7@pc_add
OUT8@disp_mux OPB8@pc_add
OUT9@disp_mux OPB9@pc_add
OUT10@disp_mux OPB10@pc_add
OUT11@disp_mux OPB11@pc_add
OUT12@disp_mux OPB12@pc_add
OUT13@disp_mux OPB13@pc_add
OUT14@disp_mux OPB14@pc_add
OUT15@disp_mux OPB15@pc_add
OUT16@disp_mux OPB16@pc_add
OUT17@disp_mux OPB17@pc_add
OUT18@disp_mux OPB18@pc_add
OUT19@disp_mux OPB19@pc_add
OUT20@disp_mux OPB20@pc_add
OUT21@disp_mux OPB21@pc_add
OUT22@disp_mux OPB22@pc_add
OUT23@disp_mux OPB23@pc_add
OUT24@disp_mux OPB24@pc_add
OUT25@disp_mux OPB25@pc_add
OUT26@disp_mux OPB26@pc_add
OUT27@disp_mux OPB27@pc_add
OUT28@disp_mux OPB28@pc_add
OUT29@disp_mux OPB29@pc_add
OUT30@disp_mux OPB30@pc_add
OUT31@disp_mux OPB31@pc_add

OUT0@ir B10@c_mux
OUT1@ir B11@c_mux
OUT2@ir B12@c_mux
OUT3@ir B13@c_mux
OUT4@ir B14@c_mux
OUT5@ir B15@c_mux
OUT6@ir B16@c_mux
OUT7@ir B17@c_mux
OUT8@ir B18@c_mux
OUT9@ir B19@c_mux
OUT10@ir B20@c_mux
OUT11@ir B21@c_mux
OUT12@ir B22@c_mux
OUT13@ir B23@c_mux
OUT14@ir B24@c_mux
OUT15@ir B25@c_mux
OUT16@ir B26@c_mux
OUT17@ir B27@c_mux
OUT18@ir B28@c_mux
OUT19@ir B29@c_mux
OUT20@ir B30@c_mux
OUT21@ir B31@c_mux

Link :
OUT0@cc C@cclogic
OUT1@cc V@cclogic
OUT2@cc Z@cclogic
OUT3@cc N@cclogic

OUT25@ir COND0@cclogic
OUT26@ir COND1@cclogic
OUT27@ir COND2@cclogic
OUT28@ir COND3@cclogic


OUT0@alu_res A0@align_in
OUT1@alu_res A1@align_in
OUT0@alu_res A0@align_out
OUT1@alu_res A1@align_out
BSEL0@align_out BSEL0
BSEL1@align_out BSEL1
BSEL2@align_out BSEL2
BSEL3@align_out BSEL3

A_SEL0@uc ASEL0@regfile
A_SEL1@uc ASEL1@regfile
A_SEL2@uc ASEL2@regfile
A_SEL3@uc ASEL3@regfile
A_SEL4@uc ASEL4@regfile
B_SEL0@uc BSEL0@regfile
B_SEL1@uc BSEL1@regfile
B_SEL2@uc BSEL2@regfile
B_SEL3@uc BSEL3@regfile
B_SEL4@uc BSEL4@regfile
C_SEL0@uc CSEL0@regfile
C_SEL1@uc CSEL1@regfile
C_SEL2@uc CSEL2@regfile
C_SEL3@uc CSEL3@regfile
C_SEL4@uc CSEL4@regfile
C_EN@uc CEN@regfile
C_MUX0@uc SELA@c_mux
C_MUX1@uc SELB@c_mux
C_MUX2@uc SELC@c_mux
C_MUX3@uc SELD@c_mux
C_MUX4@uc SELE@c_mux
C_LATCH_EN@uc EIN@c_latch
A_MUX_REG@uc SELA_SELB@a_mux
A_LATCH_EN@uc EIN@a_latch
B_MUX_REG@uc SELA_SELB@b_mux
B_LATCH_EN@uc EIN@b_latch
ENABLE_MUL@uc ENABLE_MUL@aluf
ENABLE_ALU@uc ENABLE_ALU@aluf
ENABLE_SHFT@uc ENABLE_SHFT@aluf
ALU_FCOD0@uc FCOD0@aluf
ALU_FCOD1@uc FCOD1@aluf
ALU_FCOD2@uc FCOD2@aluf
ALU_FCOD3@uc FCOD3@aluf
ALU_RES_EN@uc EIN@alu_res
Y_EN@uc EIN@Y
Y_LATCH_EN@uc EIN@y_latch
PC_MUX0@uc SELA@pc_mux
PC_MUX1@uc SELB@pc_mux
PC_MUX2@uc SELC@pc_mux
PC_MUX3@uc SELD@pc_mux
NPC_LATCH_EN@uc EIN@npc_latch
NPC_EN@uc EIN@npc
PC_LATCH_EN@uc EIN@pc_latch
PC_EN@uc EIN@pc
DISP_MUX@uc SELA_SELB@disp_mux
ADDR_MUX@uc SELA_SELB@addr_mux
IR_LATCH_EN@uc EIN@ir
DATA_IN_EN@uc EIN@data_in
DATA_OUT_EN@uc EIN@data_out
ALIGNL0@uc SIZE0@align_in
ALIGNL1@uc SIZE1@align_in
ALIGNL_SIGN@uc SIGN@align_in
ALIGNS0@uc SIZE0@align_out
ALIGNS1@uc SIZE1@align_out
INCDEC_FCOD@uc FCOD@inc_dec_cwp
CWP_LATCH_EN@uc EIN@cwp_latch
CWP_EN@uc EIN@cwp
CC_LATCH_EN@uc EIN@cc_latch
CC_EN@uc EIN@cc
CC_MUX@uc SELA_SELB@cc_mux
CWP_MUX@uc SELA_SELB@cwp_mux
Y_MUX@uc SELA_SELB@y_mux
TT_MUX@uc SELA_SELB@tt_mux
TBA_EN@uc EIN@tba
TT_EN@uc EIN@tt
WIM_EN@uc EIN@wim
LIM_EN@uc EIN@lim
BASE_EN@uc EIN@base
SP_OUT_MUX0@uc SELA@sp_out_mux
SP_OUT_MUX1@uc SELB@sp_out_mux
SP_OUT_MUX2@uc SELC@sp_out_mux
SP_OUT_MUX3@uc SELD@sp_out_mux
SP_OUT_MUX4@uc SELE@sp_out_mux
SP_OUT_MUX5@uc SELF@sp_out_mux
AS@uc AS
RD_WR@uc RD_WR

Link :
DTACK DTACK@uc
CLCK@clock CLCK@uc 
OUT0@ir IR0@uc
OUT1@ir IR1@uc
OUT2@ir IR2@uc
OUT3@ir IR3@uc
OUT4@ir IR4@uc
OUT5@ir IR5@uc
OUT6@ir IR6@uc
OUT7@ir IR7@uc
OUT8@ir IR8@uc
OUT9@ir IR9@uc
OUT10@ir IR10@uc
OUT11@ir IR11@uc
OUT12@ir IR12@uc
OUT13@ir IR13@uc
OUT14@ir IR14@uc
OUT15@ir IR15@uc
OUT16@ir IR16@uc
OUT17@ir IR17@uc
OUT18@ir IR18@uc
OUT19@ir IR19@uc
OUT20@ir IR20@uc
OUT21@ir IR21@uc
OUT22@ir IR22@uc
OUT23@ir IR23@uc
OUT24@ir IR24@uc
OUT25@ir IR25@uc
OUT26@ir IR26@uc
OUT27@ir IR27@uc
OUT28@ir IR28@uc
OUT29@ir IR29@uc
OUT30@ir IR30@uc
OUT31@ir IR31@uc
RES@cclogic CCLOGIC@uc

OUT20@alu_res A0@cc_mux
OUT21@alu_res A1@cc_mux
OUT22@alu_res A2@cc_mux
OUT23@alu_res A3@cc_mux
OUT0@alu_res A0@cwp_mux
OUT1@alu_res A1@cwp_mux
OUT2@alu_res A2@cwp_mux
OUT3@alu_res A3@cwp_mux
OUT4@alu_res A4@cwp_mux
OUT0@alu_res A0@y_mux
OUT1@alu_res A1@y_mux
OUT2@alu_res A2@y_mux
OUT3@alu_res A3@y_mux
OUT4@alu_res A4@y_mux
OUT5@alu_res A5@y_mux
OUT6@alu_res A6@y_mux
OUT7@alu_res A7@y_mux
OUT8@alu_res A8@y_mux
OUT9@alu_res A9@y_mux
OUT10@alu_res A10@y_mux
OUT11@alu_res A11@y_mux
OUT12@alu_res A12@y_mux
OUT13@alu_res A13@y_mux
OUT14@alu_res A14@y_mux
OUT15@alu_res A15@y_mux
OUT16@alu_res A16@y_mux
OUT17@alu_res A17@y_mux
OUT18@alu_res A18@y_mux
OUT19@alu_res A19@y_mux
OUT20@alu_res A20@y_mux
OUT21@alu_res A21@y_mux
OUT22@alu_res A22@y_mux
OUT23@alu_res A23@y_mux
OUT24@alu_res A24@y_mux
OUT25@alu_res A25@y_mux
OUT26@alu_res A26@y_mux
OUT27@alu_res A27@y_mux
OUT28@alu_res A28@y_mux
OUT29@alu_res A29@y_mux
OUT30@alu_res A30@y_mux
OUT31@alu_res A31@y_mux
OUT12@alu_res IN12@tba
OUT13@alu_res IN13@tba
OUT14@alu_res IN14@tba
OUT15@alu_res IN15@tba
OUT16@alu_res IN16@tba
OUT17@alu_res IN17@tba
OUT18@alu_res IN18@tba
OUT19@alu_res IN19@tba
OUT20@alu_res IN20@tba
OUT21@alu_res IN21@tba
OUT22@alu_res IN22@tba
OUT23@alu_res IN23@tba
OUT24@alu_res IN24@tba
OUT25@alu_res IN25@tba
OUT26@alu_res IN26@tba
OUT27@alu_res IN27@tba
OUT28@alu_res IN28@tba
OUT29@alu_res IN29@tba
OUT30@alu_res IN30@tba
OUT31@alu_res IN31@tba
OUT4@alu_res A0@tt_mux
OUT5@alu_res A1@tt_mux
OUT6@alu_res A2@tt_mux
OUT7@alu_res A3@tt_mux
OUT8@alu_res A4@tt_mux
OUT9@alu_res A5@tt_mux
OUT10@alu_res A6@tt_mux
OUT11@alu_res A7@tt_mux
OUT0@alu_res IN0@wim
OUT1@alu_res IN1@wim
OUT2@alu_res IN2@wim
OUT3@alu_res IN3@wim
OUT4@alu_res IN4@wim
OUT5@alu_res IN5@wim
OUT6@alu_res IN6@wim
OUT7@alu_res IN7@wim
OUT8@alu_res IN8@wim
OUT9@alu_res IN9@wim
OUT10@alu_res IN10@wim
OUT11@alu_res IN11@wim
OUT12@alu_res IN12@wim
OUT13@alu_res IN13@wim
OUT14@alu_res IN14@wim
OUT15@alu_res IN15@wim
OUT16@alu_res IN16@wim
OUT17@alu_res IN17@wim
OUT18@alu_res IN18@wim
OUT19@alu_res IN19@wim
OUT20@alu_res IN20@wim
OUT21@alu_res IN21@wim
OUT22@alu_res IN22@wim
OUT23@alu_res IN23@wim
OUT24@alu_res IN24@wim
OUT25@alu_res IN25@wim
OUT26@alu_res IN26@wim
OUT27@alu_res IN27@wim
OUT28@alu_res IN28@wim
OUT29@alu_res IN29@wim
OUT30@alu_res IN30@wim
OUT31@alu_res IN31@wim
OUT0@alu_res IN0@base
OUT1@alu_res IN1@base
OUT2@alu_res IN2@base
OUT3@alu_res IN3@base
OUT4@alu_res IN4@base
OUT5@alu_res IN5@base
OUT6@alu_res IN6@base
OUT7@alu_res IN7@base
OUT8@alu_res IN8@base
OUT9@alu_res IN9@base
OUT10@alu_res IN10@base
OUT11@alu_res IN11@base
OUT12@alu_res IN12@base
OUT13@alu_res IN13@base
OUT14@alu_res IN14@base
OUT15@alu_res IN15@base
OUT16@alu_res IN16@base
OUT17@alu_res IN17@base
OUT18@alu_res IN18@base
OUT19@alu_res IN19@base
OUT20@alu_res IN20@base
OUT21@alu_res IN21@base
OUT22@alu_res IN22@base
OUT23@alu_res IN23@base
OUT24@alu_res IN24@base
OUT25@alu_res IN25@base
OUT26@alu_res IN26@base
OUT27@alu_res IN27@base
OUT28@alu_res IN28@base
OUT29@alu_res IN29@base
OUT30@alu_res IN30@base
OUT31@alu_res IN31@base
OUT0@alu_res IN0@lim
OUT1@alu_res IN1@lim
OUT2@alu_res IN2@lim
OUT3@alu_res IN3@lim
OUT4@alu_res IN4@lim
OUT5@alu_res IN5@lim
OUT6@alu_res IN6@lim
OUT7@alu_res IN7@lim
OUT8@alu_res IN8@lim
OUT9@alu_res IN9@lim
OUT10@alu_res IN10@lim
OUT11@alu_res IN11@lim
OUT12@alu_res IN12@lim
OUT13@alu_res IN13@lim
OUT14@alu_res IN14@lim
OUT15@alu_res IN15@lim
OUT16@alu_res IN16@lim
OUT17@alu_res IN17@lim
OUT18@alu_res IN18@lim
OUT19@alu_res IN19@lim
OUT20@alu_res IN20@lim
OUT21@alu_res IN21@lim
OUT22@alu_res IN22@lim
OUT23@alu_res IN23@lim
OUT24@alu_res IN24@lim
OUT25@alu_res IN25@lim
OUT26@alu_res IN26@lim
OUT27@alu_res IN27@lim
OUT28@alu_res IN28@lim
OUT29@alu_res IN29@lim
OUT30@alu_res IN30@lim
OUT31@alu_res IN31@lim


C@aluf B0@cc_mux
V@aluf B1@cc_mux
Z@aluf B2@cc_mux
N@aluf B3@cc_mux
RES0@inc_dec_cwp B0@cwp_mux
RES1@inc_dec_cwp B1@cwp_mux
RES2@inc_dec_cwp B2@cwp_mux
RES3@inc_dec_cwp B3@cwp_mux
RES4@inc_dec_cwp B4@cwp_mux
Y_OUT0@aluf B0@y_mux
Y_OUT1@aluf B1@y_mux
Y_OUT2@aluf B2@y_mux
Y_OUT3@aluf B3@y_mux
Y_OUT4@aluf B4@y_mux
Y_OUT5@aluf B5@y_mux
Y_OUT6@aluf B6@y_mux
Y_OUT7@aluf B7@y_mux
Y_OUT8@aluf B8@y_mux
Y_OUT9@aluf B9@y_mux
Y_OUT10@aluf B10@y_mux
Y_OUT11@aluf B11@y_mux
Y_OUT12@aluf B12@y_mux
Y_OUT13@aluf B13@y_mux
Y_OUT14@aluf B14@y_mux
Y_OUT15@aluf B15@y_mux
Y_OUT16@aluf B16@y_mux
Y_OUT17@aluf B17@y_mux
Y_OUT18@aluf B18@y_mux
Y_OUT19@aluf B19@y_mux
Y_OUT20@aluf B20@y_mux
Y_OUT21@aluf B21@y_mux
Y_OUT22@aluf B22@y_mux
Y_OUT23@aluf B23@y_mux
Y_OUT24@aluf B24@y_mux
Y_OUT25@aluf B25@y_mux
Y_OUT26@aluf B26@y_mux
Y_OUT27@aluf B27@y_mux
Y_OUT28@aluf B28@y_mux
Y_OUT29@aluf B29@y_mux
Y_OUT30@aluf B30@y_mux
Y_OUT31@aluf B31@y_mux

OUT0@cc_mux IN0@cc_latch
OUT1@cc_mux IN1@cc_latch
OUT2@cc_mux IN2@cc_latch
OUT3@cc_mux IN3@cc_latch
OUT0@cwp_mux IN0@cwp_latch
OUT1@cwp_mux IN1@cwp_latch
OUT2@cwp_mux IN2@cwp_latch
OUT3@cwp_mux IN3@cwp_latch
OUT4@cwp_mux IN4@cwp_latch
OUT0@y_mux IN0@y_latch
OUT1@y_mux IN1@y_latch
OUT2@y_mux IN2@y_latch
OUT3@y_mux IN3@y_latch
OUT4@y_mux IN4@y_latch
OUT5@y_mux IN5@y_latch
OUT6@y_mux IN6@y_latch
OUT7@y_mux IN7@y_latch
OUT8@y_mux IN8@y_latch
OUT9@y_mux IN9@y_latch
OUT10@y_mux IN10@y_latch
OUT11@y_mux IN11@y_latch
OUT12@y_mux IN12@y_latch
OUT13@y_mux IN13@y_latch
OUT14@y_mux IN14@y_latch
OUT15@y_mux IN15@y_latch
OUT16@y_mux IN16@y_latch
OUT17@y_mux IN17@y_latch
OUT18@y_mux IN18@y_latch
OUT19@y_mux IN19@y_latch
OUT20@y_mux IN20@y_latch
OUT21@y_mux IN21@y_latch
OUT22@y_mux IN22@y_latch
OUT23@y_mux IN23@y_latch
OUT24@y_mux IN24@y_latch
OUT25@y_mux IN25@y_latch
OUT26@y_mux IN26@y_latch
OUT27@y_mux IN27@y_latch
OUT28@y_mux IN28@y_latch
OUT29@y_mux IN29@y_latch
OUT30@y_mux IN30@y_latch
OUT31@y_mux IN31@y_latch
OUT0@tt_mux IN0@tt
OUT1@tt_mux IN1@tt
OUT2@tt_mux IN2@tt
OUT3@tt_mux IN3@tt
OUT4@tt_mux IN4@tt
OUT5@tt_mux IN5@tt
OUT6@tt_mux IN6@tt
OUT7@tt_mux IN7@tt

OUT0@cc_latch IN0@cc
OUT1@cc_latch IN1@cc
OUT2@cc_latch IN2@cc
OUT3@cc_latch IN3@cc
OUT0@cwp_latch IN0@cwp
OUT1@cwp_latch IN1@cwp
OUT2@cwp_latch IN2@cwp
OUT3@cwp_latch IN3@cwp
OUT4@cwp_latch IN4@cwp
OUT0@y_latch IN0@y
OUT1@y_latch IN1@y
OUT2@y_latch IN2@y
OUT3@y_latch IN3@y
OUT4@y_latch IN4@y
OUT5@y_latch IN5@y
OUT6@y_latch IN6@y
OUT7@y_latch IN7@y
OUT8@y_latch IN8@y
OUT9@y_latch IN9@y
OUT10@y_latch IN10@y
OUT11@y_latch IN11@y
OUT12@y_latch IN12@y
OUT13@y_latch IN13@y
OUT14@y_latch IN14@y
OUT15@y_latch IN15@y
OUT16@y_latch IN16@y
OUT17@y_latch IN17@y
OUT18@y_latch IN18@y
OUT19@y_latch IN19@y
OUT20@y_latch IN20@y
OUT21@y_latch IN21@y
OUT22@y_latch IN22@y
OUT23@y_latch IN23@y
OUT24@y_latch IN24@y
OUT25@y_latch IN25@y
OUT26@y_latch IN26@y
OUT27@y_latch IN27@y
OUT28@y_latch IN28@y
OUT29@y_latch IN29@y
OUT30@y_latch IN30@y
OUT31@y_latch IN31@y

OUT0@cc   A20@sp_out_mux
OUT1@cc   A21@sp_out_mux
OUT2@cc   A22@sp_out_mux
OUT3@cc   A23@sp_out_mux
OUT0@cwp  A0@sp_out_mux
OUT1@cwp  A1@sp_out_mux
OUT2@cwp  A2@sp_out_mux
OUT3@cwp  A3@sp_out_mux
OUT4@cwp  A4@sp_out_mux
OUT0@y    B0@sp_out_mux
OUT1@y    B1@sp_out_mux
OUT2@y    B2@sp_out_mux
OUT3@y    B3@sp_out_mux
OUT4@y    B4@sp_out_mux
OUT5@y    B5@sp_out_mux
OUT6@y    B6@sp_out_mux
OUT7@y    B7@sp_out_mux
OUT8@y    B8@sp_out_mux
OUT9@y    B9@sp_out_mux
OUT10@y    B10@sp_out_mux
OUT11@y    B11@sp_out_mux
OUT12@y    B12@sp_out_mux
OUT13@y    B13@sp_out_mux
OUT14@y    B14@sp_out_mux
OUT15@y    B15@sp_out_mux
OUT16@y    B16@sp_out_mux
OUT17@y    B17@sp_out_mux
OUT18@y    B18@sp_out_mux
OUT19@y    B19@sp_out_mux
OUT20@y    B20@sp_out_mux
OUT21@y    B21@sp_out_mux
OUT22@y    B22@sp_out_mux
OUT23@y    B23@sp_out_mux
OUT24@y    B24@sp_out_mux
OUT25@y    B25@sp_out_mux
OUT26@y    B26@sp_out_mux
OUT27@y    B27@sp_out_mux
OUT28@y    B28@sp_out_mux
OUT29@y    B29@sp_out_mux
OUT30@y    B30@sp_out_mux
OUT31@y    B31@sp_out_mux
OUT12@tba  C12@sp_out_mux
OUT13@tba  C13@sp_out_mux
OUT14@tba  C14@sp_out_mux
OUT15@tba  C15@sp_out_mux
OUT16@tba  C16@sp_out_mux
OUT17@tba  C17@sp_out_mux
OUT18@tba  C18@sp_out_mux
OUT19@tba  C19@sp_out_mux
OUT20@tba  C20@sp_out_mux
OUT21@tba  C21@sp_out_mux
OUT22@tba  C22@sp_out_mux
OUT23@tba  C23@sp_out_mux
OUT24@tba  C24@sp_out_mux
OUT25@tba  C25@sp_out_mux
OUT26@tba  C26@sp_out_mux
OUT27@tba  C27@sp_out_mux
OUT28@tba  C28@sp_out_mux
OUT29@tba  C29@sp_out_mux
OUT30@tba  C30@sp_out_mux
OUT31@tba  C31@sp_out_mux
OUT0@tt   C4@sp_out_mux
OUT1@tt   C5@sp_out_mux
OUT2@tt   C6@sp_out_mux
OUT3@tt   C7@sp_out_mux
OUT4@tt   C8@sp_out_mux
OUT5@tt   C9@sp_out_mux
OUT6@tt   C10@sp_out_mux
OUT7@tt   C11@sp_out_mux
OUT0@wim  D0@sp_out_mux
OUT1@wim  D1@sp_out_mux
OUT2@wim  D2@sp_out_mux
OUT3@wim  D3@sp_out_mux
OUT4@wim  D4@sp_out_mux
OUT5@wim  D5@sp_out_mux
OUT6@wim  D6@sp_out_mux
OUT7@wim  D7@sp_out_mux
OUT8@wim  D8@sp_out_mux
OUT9@wim  D9@sp_out_mux
OUT10@wim  D10@sp_out_mux
OUT11@wim  D11@sp_out_mux
OUT12@wim  D12@sp_out_mux
OUT13@wim  D13@sp_out_mux
OUT14@wim  D14@sp_out_mux
OUT15@wim  D15@sp_out_mux
OUT16@wim  D16@sp_out_mux
OUT17@wim  D17@sp_out_mux
OUT18@wim  D18@sp_out_mux
OUT19@wim  D19@sp_out_mux
OUT20@wim  D20@sp_out_mux
OUT21@wim  D21@sp_out_mux
OUT22@wim  D22@sp_out_mux
OUT23@wim  D23@sp_out_mux
OUT24@wim  D24@sp_out_mux
OUT25@wim  D25@sp_out_mux
OUT26@wim  D26@sp_out_mux
OUT27@wim  D27@sp_out_mux
OUT28@wim  D28@sp_out_mux
OUT29@wim  D29@sp_out_mux
OUT30@wim  D30@sp_out_mux
OUT31@wim  D31@sp_out_mux
OUT0@lim  E0@sp_out_mux
OUT1@lim  E1@sp_out_mux
OUT2@lim  E2@sp_out_mux
OUT3@lim  E3@sp_out_mux
OUT4@lim  E4@sp_out_mux
OUT5@lim  E5@sp_out_mux
OUT6@lim  E6@sp_out_mux
OUT7@lim  E7@sp_out_mux
OUT8@lim  E8@sp_out_mux
OUT9@lim  E9@sp_out_mux
OUT10@lim  E10@sp_out_mux
OUT11@lim  E11@sp_out_mux
OUT12@lim  E12@sp_out_mux
OUT13@lim  E13@sp_out_mux
OUT14@lim  E14@sp_out_mux
OUT15@lim  E15@sp_out_mux
OUT16@lim  E16@sp_out_mux
OUT17@lim  E17@sp_out_mux
OUT18@lim  E18@sp_out_mux
OUT19@lim  E19@sp_out_mux
OUT20@lim  E20@sp_out_mux
OUT21@lim  E21@sp_out_mux
OUT22@lim  E22@sp_out_mux
OUT23@lim  E23@sp_out_mux
OUT24@lim  E24@sp_out_mux
OUT25@lim  E25@sp_out_mux
OUT26@lim  E26@sp_out_mux
OUT27@lim  E27@sp_out_mux
OUT28@lim  E28@sp_out_mux
OUT29@lim  E29@sp_out_mux
OUT30@lim  E30@sp_out_mux
OUT31@lim  E31@sp_out_mux
OUT0@base F0@sp_out_mux
OUT1@base F1@sp_out_mux
OUT2@base F2@sp_out_mux
OUT3@base F3@sp_out_mux
OUT4@base F4@sp_out_mux
OUT5@base F5@sp_out_mux
OUT6@base F6@sp_out_mux
OUT7@base F7@sp_out_mux
OUT8@base F8@sp_out_mux
OUT9@base F9@sp_out_mux
OUT10@base F10@sp_out_mux
OUT11@base F11@sp_out_mux
OUT12@base F12@sp_out_mux
OUT13@base F13@sp_out_mux
OUT14@base F14@sp_out_mux
OUT15@base F15@sp_out_mux
OUT16@base F16@sp_out_mux
OUT17@base F17@sp_out_mux
OUT18@base F18@sp_out_mux
OUT19@base F19@sp_out_mux
OUT20@base F20@sp_out_mux
OUT21@base F21@sp_out_mux
OUT22@base F22@sp_out_mux
OUT23@base F23@sp_out_mux
OUT24@base F24@sp_out_mux
OUT25@base F25@sp_out_mux
OUT26@base F26@sp_out_mux
OUT27@base F27@sp_out_mux
OUT28@base F28@sp_out_mux
OUT29@base F29@sp_out_mux
OUT30@base F30@sp_out_mux
OUT31@base F31@sp_out_mux

OUT0@sp_out_mux E0@c_mux
OUT1@sp_out_mux E1@c_mux
OUT2@sp_out_mux E2@c_mux
OUT3@sp_out_mux E3@c_mux
OUT4@sp_out_mux E4@c_mux
OUT5@sp_out_mux E5@c_mux
OUT6@sp_out_mux E6@c_mux
OUT7@sp_out_mux E7@c_mux
OUT8@sp_out_mux E8@c_mux
OUT9@sp_out_mux E9@c_mux
OUT10@sp_out_mux E10@c_mux
OUT11@sp_out_mux E11@c_mux
OUT12@sp_out_mux E12@c_mux
OUT13@sp_out_mux E13@c_mux
OUT14@sp_out_mux E14@c_mux
OUT15@sp_out_mux E15@c_mux
OUT16@sp_out_mux E16@c_mux
OUT17@sp_out_mux E17@c_mux
OUT18@sp_out_mux E18@c_mux
OUT19@sp_out_mux E19@c_mux
OUT20@sp_out_mux E20@c_mux
OUT21@sp_out_mux E21@c_mux
OUT22@sp_out_mux E22@c_mux
OUT23@sp_out_mux E23@c_mux
OUT24@sp_out_mux E24@c_mux
OUT25@sp_out_mux E25@c_mux
OUT26@sp_out_mux E26@c_mux
OUT27@sp_out_mux E27@c_mux
OUT28@sp_out_mux E28@c_mux
OUT29@sp_out_mux E29@c_mux
OUT30@sp_out_mux E30@c_mux
OUT31@sp_out_mux E31@c_mux

OUT0@cwp OP0@inc_dec_cwp
OUT1@cwp OP1@inc_dec_cwp
OUT2@cwp OP2@inc_dec_cwp
OUT3@cwp OP3@inc_dec_cwp
OUT4@cwp OP4@inc_dec_cwp
OUT0@cwp CWP0@regfile
OUT1@cwp CWP1@regfile
OUT2@cwp CWP2@regfile
OUT3@cwp CWP3@regfile
OUT4@cwp CWP4@regfile

OUT0@y Y_IN0@aluf
OUT1@y Y_IN1@aluf
OUT2@y Y_IN2@aluf
OUT3@y Y_IN3@aluf
OUT4@y Y_IN4@aluf
OUT5@y Y_IN5@aluf
OUT6@y Y_IN6@aluf
OUT7@y Y_IN7@aluf
OUT8@y Y_IN8@aluf
OUT9@y Y_IN9@aluf
OUT10@y Y_IN10@aluf
OUT11@y Y_IN11@aluf
OUT12@y Y_IN12@aluf
OUT13@y Y_IN13@aluf
OUT14@y Y_IN14@aluf
OUT15@y Y_IN15@aluf
OUT16@y Y_IN16@aluf
OUT17@y Y_IN17@aluf
OUT18@y Y_IN18@aluf
OUT19@y Y_IN19@aluf
OUT20@y Y_IN20@aluf
OUT21@y Y_IN21@aluf
OUT22@y Y_IN22@aluf
OUT23@y Y_IN23@aluf
OUT24@y Y_IN24@aluf
OUT25@y Y_IN25@aluf
OUT26@y Y_IN26@aluf
OUT27@y Y_IN27@aluf
OUT28@y Y_IN28@aluf
OUT29@y Y_IN29@aluf
OUT30@y Y_IN30@aluf
OUT31@y Y_IN31@aluf


[Mem]
preparation : 0:0:0:50
Memsize : 256
Memfile : call.map
dumpfile : Memory.dmp

[bus]
response : 0:0:0:1

[csMem]
response : 0:0:0:1
bottom : 0
top : 256

[clock]
response : 0:1:0:0
[ir]
response : 0:0:0:10
[pc_add]
[pc_mux]
nbits : 32
nports : 4
[npc_latch]
[npc]
initial : 36
[pc_latch]
[pc]
initial : 32
[pc_inc]
[addr_mux]
[a_mux]
[b_mux]
[c_mux]
nbits : 32
nports : 5
[a_latch]
[b_latch]
[c_latch]
[alu_res]
[data_out]
[align_out]
[data_in]
[align_in]
[uc]
[cclogic]
[cc]
[cc_latch]
[cwp]
[cwp_latch]
[inc_dec_cwp]
[cc_mux]
[cwp_mux]
[y_mux]
[tt_mux]
[tba]
[tt]
[wim]
[lim]
[base]
[sp_out_mux]
nbits : 32
nports : 6

[regfile]
components : regblock@regblock regglob@regglob cwpa@cwplogic cwpb@cwplogic cwpc@cwplogic regmuxa@mux regmuxb@mux blockand@and
globand@and globnot@not

in :
ASEL0
ASEL1
ASEL2
ASEL3
ASEL4
BSEL0
BSEL1
BSEL2
BSEL3
BSEL4
CSEL0
CSEL1
CSEL2
CSEL3
CSEL4
C0
C1
C2
C3
C4
C5
C6
C7
C8
C9
C10
C11
C12
C13
C14
C15
C16
C17
C18
C19
C20
C21
C22
C23
C24
C25
C26
C27
C28
C29
C30
C31
CEN
CWP0
CWP1
CWP2
CWP3
CWP4
out :
A0
A1
A2
A3
A4
A5
A6
A7
A8
A9
A10
A11
A12
A13
A14
A15
A16
A17
A18
A19
A20
A21
A22
A23
A24
A25
A26
A27
A28
A29
A30
A31
B0
B1
B2
B3
B4
B5
B6
B7
B8
B9
B10
B11
B12
B13
B14
B15
B16
B17
B18
B19
B20
B21
B22
B23
B24
B25
B26
B27
B28
B29
B30
B31
Link :
ASEL0 SEL0@cwpa
ASEL1 SEL1@cwpa
ASEL2 SEL2@cwpa
ASEL3 SEL3@cwpa
ASEL4 SEL4@cwpa
BSEL0 SEL0@cwpb
BSEL1 SEL1@cwpb
BSEL2 SEL2@cwpb
BSEL3 SEL3@cwpb
BSEL4 SEL4@cwpb
CSEL0 SEL0@cwpc
CSEL1 SEL1@cwpc
CSEL2 SEL2@cwpc
CSEL3 SEL3@cwpc
CSEL4 SEL4@cwpc
CWP0 CWP0@cwpa
CWP1 CWP1@cwpa
CWP2 CWP2@cwpa
CWP3 CWP3@cwpa
CWP4 CWP4@cwpa
CWP0 CWP0@cwpb
CWP1 CWP1@cwpb
CWP2 CWP2@cwpb
CWP3 CWP3@cwpb
CWP4 CWP4@cwpb
CWP0 CWP0@cwpc
CWP1 CWP1@cwpc
CWP2 CWP2@cwpc
CWP3 CWP3@cwpc
CWP4 CWP4@cwpc

GSEL0@cwpa ASEL0@regglob
GSEL1@cwpa ASEL1@regglob
GSEL2@cwpa ASEL2@regglob
GSEL0@cwpb BSEL0@regglob
GSEL1@cwpb BSEL1@regglob
GSEL2@cwpb BSEL2@regglob
GSEL0@cwpc CSEL0@regglob
GSEL1@cwpc CSEL1@regglob
GSEL2@cwpc CSEL2@regglob

RSEL0@cwpa ASEL0@regblock
RSEL1@cwpa ASEL1@regblock
RSEL2@cwpa ASEL2@regblock
RSEL3@cwpa ASEL3@regblock
RSEL4@cwpa ASEL4@regblock
RSEL5@cwpa ASEL5@regblock
RSEL6@cwpa ASEL6@regblock
RSEL7@cwpa ASEL7@regblock
RSEL8@cwpa ASEL8@regblock
RSEL0@cwpb BSEL0@regblock
RSEL1@cwpb BSEL1@regblock
RSEL2@cwpb BSEL2@regblock
RSEL3@cwpb BSEL3@regblock
RSEL4@cwpb BSEL4@regblock
RSEL5@cwpb BSEL5@regblock
RSEL6@cwpb BSEL6@regblock
RSEL7@cwpb BSEL7@regblock
RSEL8@cwpb BSEL8@regblock
RSEL0@cwpc CSEL0@regblock
RSEL1@cwpc CSEL1@regblock
RSEL2@cwpc CSEL2@regblock
RSEL3@cwpc CSEL3@regblock
RSEL4@cwpc CSEL4@regblock
RSEL5@cwpc CSEL5@regblock
RSEL6@cwpc CSEL6@regblock
RSEL7@cwpc CSEL7@regblock
RSEL8@cwpc CSEL8@regblock

C0 CIN0@regglob
C1 CIN1@regglob
C2 CIN2@regglob
C3 CIN3@regglob
C4 CIN4@regglob
C5 CIN5@regglob
C6 CIN6@regglob
C7 CIN7@regglob
C8 CIN8@regglob
C9 CIN9@regglob
C10 CIN10@regglob
C11 CIN11@regglob
C12 CIN12@regglob
C13 CIN13@regglob
C14 CIN14@regglob
C15 CIN15@regglob
C16 CIN16@regglob
C17 CIN17@regglob
C18 CIN18@regglob
C19 CIN19@regglob
C20 CIN20@regglob
C21 CIN21@regglob
C22 CIN22@regglob
C23 CIN23@regglob
C24 CIN24@regglob
C25 CIN25@regglob
C26 CIN26@regglob
C27 CIN27@regglob
C28 CIN28@regglob
C29 CIN29@regglob
C30 CIN30@regglob
C31 CIN31@regglob
C0 CIN0@regblock
C1 CIN1@regblock
C2 CIN2@regblock
C3 CIN3@regblock
C4 CIN4@regblock
C5 CIN5@regblock
C6 CIN6@regblock
C7 CIN7@regblock
C8 CIN8@regblock
C9 CIN9@regblock
C10 CIN10@regblock
C11 CIN11@regblock
C12 CIN12@regblock
C13 CIN13@regblock
C14 CIN14@regblock
C15 CIN15@regblock
C16 CIN16@regblock
C17 CIN17@regblock
C18 CIN18@regblock
C19 CIN19@regblock
C20 CIN20@regblock
C21 CIN21@regblock
C22 CIN22@regblock
C23 CIN23@regblock
C24 CIN24@regblock
C25 CIN25@regblock
C26 CIN26@regblock
C27 CIN27@regblock
C28 CIN28@regblock
C29 CIN29@regblock
C30 CIN30@regblock
C31 CIN31@regblock

CEN INA@globand
CEN INA@blockand
R_G@cwpc INB@blockand
R_G@cwpc IN@globnot
OUT@globnot INB@globand
OUT@blockand CEN@regblock
OUT@globand CEN@regglob

AOUT0@regblock A0@regmuxa
AOUT1@regblock A1@regmuxa
AOUT2@regblock A2@regmuxa
AOUT3@regblock A3@regmuxa
AOUT4@regblock A4@regmuxa
AOUT5@regblock A5@regmuxa
AOUT6@regblock A6@regmuxa
AOUT7@regblock A7@regmuxa
AOUT8@regblock A8@regmuxa
AOUT9@regblock A9@regmuxa
AOUT10@regblock A10@regmuxa
AOUT11@regblock A11@regmuxa
AOUT12@regblock A12@regmuxa
AOUT13@regblock A13@regmuxa
AOUT14@regblock A14@regmuxa
AOUT15@regblock A15@regmuxa
AOUT16@regblock A16@regmuxa
AOUT17@regblock A17@regmuxa
AOUT18@regblock A18@regmuxa
AOUT19@regblock A19@regmuxa
AOUT20@regblock A20@regmuxa
AOUT21@regblock A21@regmuxa
AOUT22@regblock A22@regmuxa
AOUT23@regblock A23@regmuxa
AOUT24@regblock A24@regmuxa
AOUT25@regblock A25@regmuxa
AOUT26@regblock A26@regmuxa
AOUT27@regblock A27@regmuxa
AOUT28@regblock A28@regmuxa
AOUT29@regblock A29@regmuxa
AOUT30@regblock A30@regmuxa
AOUT31@regblock A31@regmuxa
AOUT0@regglob  B0@regmuxa
AOUT1@regglob  B1@regmuxa
AOUT2@regglob  B2@regmuxa
AOUT3@regglob  B3@regmuxa
AOUT4@regglob  B4@regmuxa
AOUT5@regglob  B5@regmuxa
AOUT6@regglob  B6@regmuxa
AOUT7@regglob  B7@regmuxa
AOUT8@regglob  B8@regmuxa
AOUT9@regglob  B9@regmuxa
AOUT10@regglob  B10@regmuxa
AOUT11@regglob  B11@regmuxa
AOUT12@regglob  B12@regmuxa
AOUT13@regglob  B13@regmuxa
AOUT14@regglob  B14@regmuxa
AOUT15@regglob  B15@regmuxa
AOUT16@regglob  B16@regmuxa
AOUT17@regglob  B17@regmuxa
AOUT18@regglob  B18@regmuxa
AOUT19@regglob  B19@regmuxa
AOUT20@regglob  B20@regmuxa
AOUT21@regglob  B21@regmuxa
AOUT22@regglob  B22@regmuxa
AOUT23@regglob  B23@regmuxa
AOUT24@regglob  B24@regmuxa
AOUT25@regglob  B25@regmuxa
AOUT26@regglob  B26@regmuxa
AOUT27@regglob  B27@regmuxa
AOUT28@regglob  B28@regmuxa
AOUT29@regglob  B29@regmuxa
AOUT30@regglob  B30@regmuxa
AOUT31@regglob  B31@regmuxa

BOUT0@regblock A0@regmuxb
BOUT1@regblock A1@regmuxb
BOUT2@regblock A2@regmuxb
BOUT3@regblock A3@regmuxb
BOUT4@regblock A4@regmuxb
BOUT5@regblock A5@regmuxb
BOUT6@regblock A6@regmuxb
BOUT7@regblock A7@regmuxb
BOUT8@regblock A8@regmuxb
BOUT9@regblock A9@regmuxb
BOUT10@regblock A10@regmuxb
BOUT11@regblock A11@regmuxb
BOUT12@regblock A12@regmuxb
BOUT13@regblock A13@regmuxb
BOUT14@regblock A14@regmuxb
BOUT15@regblock A15@regmuxb
BOUT16@regblock A16@regmuxb
BOUT17@regblock A17@regmuxb
BOUT18@regblock A18@regmuxb
BOUT19@regblock A19@regmuxb
BOUT20@regblock A20@regmuxb
BOUT21@regblock A21@regmuxb
BOUT22@regblock A22@regmuxb
BOUT23@regblock A23@regmuxb
BOUT24@regblock A24@regmuxb
BOUT25@regblock A25@regmuxb
BOUT26@regblock A26@regmuxb
BOUT27@regblock A27@regmuxb
BOUT28@regblock A28@regmuxb
BOUT29@regblock A29@regmuxb
BOUT30@regblock A30@regmuxb
BOUT31@regblock A31@regmuxb
BOUT0@regglob  B0@regmuxb
BOUT1@regglob  B1@regmuxb
BOUT2@regglob  B2@regmuxb
BOUT3@regglob  B3@regmuxb
BOUT4@regglob  B4@regmuxb
BOUT5@regglob  B5@regmuxb
BOUT6@regglob  B6@regmuxb
BOUT7@regglob  B7@regmuxb
BOUT8@regglob  B8@regmuxb
BOUT9@regglob  B9@regmuxb
BOUT10@regglob  B10@regmuxb
BOUT11@regglob  B11@regmuxb
BOUT12@regglob  B12@regmuxb
BOUT13@regglob  B13@regmuxb
BOUT14@regglob  B14@regmuxb
BOUT15@regglob  B15@regmuxb
BOUT16@regglob  B16@regmuxb
BOUT17@regglob  B17@regmuxb
BOUT18@regglob  B18@regmuxb
BOUT19@regglob  B19@regmuxb
BOUT20@regglob  B20@regmuxb
BOUT21@regglob  B21@regmuxb
BOUT22@regglob  B22@regmuxb
BOUT23@regglob  B23@regmuxb
BOUT24@regglob  B24@regmuxb
BOUT25@regglob  B25@regmuxb
BOUT26@regglob  B26@regmuxb
BOUT27@regglob  B27@regmuxb
BOUT28@regglob  B28@regmuxb
BOUT29@regglob  B29@regmuxb
BOUT30@regglob  B30@regmuxb
BOUT31@regglob  B31@regmuxb

R_G@cwpa SELA_SELB@regmuxa
R_G@cwpb SELA_SELB@regmuxb

OUT0@regmuxa A0
OUT1@regmuxa A1
OUT2@regmuxa A2
OUT3@regmuxa A3
OUT4@regmuxa A4
OUT5@regmuxa A5
OUT6@regmuxa A6
OUT7@regmuxa A7
OUT8@regmuxa A8
OUT9@regmuxa A9
OUT10@regmuxa A10
OUT11@regmuxa A11
OUT12@regmuxa A12
OUT13@regmuxa A13
OUT14@regmuxa A14
OUT15@regmuxa A15
OUT16@regmuxa A16
OUT17@regmuxa A17
OUT18@regmuxa A18
OUT19@regmuxa A19
OUT20@regmuxa A20
OUT21@regmuxa A21
OUT22@regmuxa A22
OUT23@regmuxa A23
OUT24@regmuxa A24
OUT25@regmuxa A25
OUT26@regmuxa A26
OUT27@regmuxa A27
OUT28@regmuxa A28
OUT29@regmuxa A29
OUT30@regmuxa A30
OUT31@regmuxa A31
OUT0@regmuxb B0
OUT1@regmuxb B1
OUT2@regmuxb B2
OUT3@regmuxb B3
OUT4@regmuxb B4
OUT5@regmuxb B5
OUT6@regmuxb B6
OUT7@regmuxb B7
OUT8@regmuxb B8
OUT9@regmuxb B9
OUT10@regmuxb B10
OUT11@regmuxb B11
OUT12@regmuxb B12
OUT13@regmuxb B13
OUT14@regmuxb B14
OUT15@regmuxb B15
OUT16@regmuxb B16
OUT17@regmuxb B17
OUT18@regmuxb B18
OUT19@regmuxb B19
OUT20@regmuxb B20
OUT21@regmuxb B21
OUT22@regmuxb B22
OUT23@regmuxb B23
OUT24@regmuxb B24
OUT25@regmuxb B25
OUT26@regmuxb B26
OUT27@regmuxb B27
OUT28@regmuxb B28
OUT29@regmuxb B29
OUT30@regmuxb B30
OUT31@regmuxb B31

[regblock]
[regglob]
[cwpa] [cwpb] [cwpc]
[globand]
preparation : 0:0:0:1
[blockand]
preparation : 0:0:0:1
[globnot]
preparation : 0:0:0:1
[regmuxa] [regmuxb]
[aluf]
components : alu@alu muldiv@muldiv shift@shifter ccmux@mux resmux@muxn
in :
A0 B0
A1 B1
A2 B2
A3 B3
A4 B4
A5 B5
A6 B6
A7 B7
A8 B8
A9 B9
A10 B10
A11 B11
A12 B12
A13 B13
A14 B14
A15 B15
A16 B16
A17 B17
A18 B18
A19 B19
A20 B20
A21 B21
A22 B22
A23 B23
A24 B24
A25 B25
A26 B26
A27 B27
A28 B28
A29 B29
A30 B30
A31 B31
C_IN
FCOD0
FCOD1
FCOD2
FCOD3
Y_IN0
Y_IN1
Y_IN2
Y_IN3
Y_IN4
Y_IN5
Y_IN6
Y_IN7
Y_IN8
Y_IN9
Y_IN10
Y_IN11
Y_IN12
Y_IN13
Y_IN14
Y_IN15
Y_IN16
Y_IN17
Y_IN18
Y_IN19
Y_IN20
Y_IN21
Y_IN22
Y_IN23
Y_IN24
Y_IN25
Y_IN26
Y_IN27
Y_IN28
Y_IN29
Y_IN30
Y_IN31
ENABLE_MUL ENABLE_ALU ENABLE_SHFT

out :
C0 Y_OUT0
C1 Y_OUT1
C2 Y_OUT2
C3 Y_OUT3
C4 Y_OUT4
C5 Y_OUT5
C6 Y_OUT6
C7 Y_OUT7
C8 Y_OUT8
C9 Y_OUT9
C10 Y_OUT10
C11 Y_OUT11
C12 Y_OUT12
C13 Y_OUT13
C14 Y_OUT14
C15 Y_OUT15
C16 Y_OUT16
C17 Y_OUT17
C18 Y_OUT18
C19 Y_OUT19
C20 Y_OUT20
C21 Y_OUT21
C22 Y_OUT22
C23 Y_OUT23
C24 Y_OUT24
C25 Y_OUT25
C26 Y_OUT26
C27 Y_OUT27
C28 Y_OUT28
C29 Y_OUT29
C30 Y_OUT30
C31 Y_OUT31
C N V Z

Link :
A0 OPA0@alu
A1 OPA1@alu
A2 OPA2@alu
A3 OPA3@alu
A4 OPA4@alu
A5 OPA5@alu
A6 OPA6@alu
A7 OPA7@alu
A8 OPA8@alu
A9 OPA9@alu
A10 OPA10@alu
A11 OPA11@alu
A12 OPA12@alu
A13 OPA13@alu
A14 OPA14@alu
A15 OPA15@alu
A16 OPA16@alu
A17 OPA17@alu
A18 OPA18@alu
A19 OPA19@alu
A20 OPA20@alu
A21 OPA21@alu
A22 OPA22@alu
A23 OPA23@alu
A24 OPA24@alu
A25 OPA25@alu
A26 OPA26@alu
A27 OPA27@alu
A28 OPA28@alu
A29 OPA29@alu
A30 OPA30@alu
A31 OPA31@alu
A0 OPA0@muldiv
A1 OPA1@muldiv
A2 OPA2@muldiv
A3 OPA3@muldiv
A4 OPA4@muldiv
A5 OPA5@muldiv
A6 OPA6@muldiv
A7 OPA7@muldiv
A8 OPA8@muldiv
A9 OPA9@muldiv
A10 OPA10@muldiv
A11 OPA11@muldiv
A12 OPA12@muldiv
A13 OPA13@muldiv
A14 OPA14@muldiv
A15 OPA15@muldiv
A16 OPA16@muldiv
A17 OPA17@muldiv
A18 OPA18@muldiv
A19 OPA19@muldiv
A20 OPA20@muldiv
A21 OPA21@muldiv
A22 OPA22@muldiv
A23 OPA23@muldiv
A24 OPA24@muldiv
A25 OPA25@muldiv
A26 OPA26@muldiv
A27 OPA27@muldiv
A28 OPA28@muldiv
A29 OPA29@muldiv
A30 OPA30@muldiv
A31 OPA31@muldiv
A0 OPA0@shift
A1 OPA1@shift
A2 OPA2@shift
A3 OPA3@shift
A4 OPA4@shift
A5 OPA5@shift
A6 OPA6@shift
A7 OPA7@shift
A8 OPA8@shift
A9 OPA9@shift
A10 OPA10@shift
A11 OPA11@shift
A12 OPA12@shift
A13 OPA13@shift
A14 OPA14@shift
A15 OPA15@shift
A16 OPA16@shift
A17 OPA17@shift
A18 OPA18@shift
A19 OPA19@shift
A20 OPA20@shift
A21 OPA21@shift
A22 OPA22@shift
A23 OPA23@shift
A24 OPA24@shift
A25 OPA25@shift
A26 OPA26@shift
A27 OPA27@shift
A28 OPA28@shift
A29 OPA29@shift
A30 OPA30@shift
A31 OPA31@shift
B0 OPB0@alu
B1 OPB1@alu
B2 OPB2@alu
B3 OPB3@alu
B4 OPB4@alu
B5 OPB5@alu
B6 OPB6@alu
B7 OPB7@alu
B8 OPB8@alu
B9 OPB9@alu
B10 OPB10@alu
B11 OPB11@alu
B12 OPB12@alu
B13 OPB13@alu
B14 OPB14@alu
B15 OPB15@alu
B16 OPB16@alu
B17 OPB17@alu
B18 OPB18@alu
B19 OPB19@alu
B20 OPB20@alu
B21 OPB21@alu
B22 OPB22@alu
B23 OPB23@alu
B24 OPB24@alu
B25 OPB25@alu
B26 OPB26@alu
B27 OPB27@alu
B28 OPB28@alu
B29 OPB29@alu
B30 OPB30@alu
B31 OPB31@alu
B0 OPB0@muldiv
B1 OPB1@muldiv
B2 OPB2@muldiv
B3 OPB3@muldiv
B4 OPB4@muldiv
B5 OPB5@muldiv
B6 OPB6@muldiv
B7 OPB7@muldiv
B8 OPB8@muldiv
B9 OPB9@muldiv
B10 OPB10@muldiv
B11 OPB11@muldiv
B12 OPB12@muldiv
B13 OPB13@muldiv
B14 OPB14@muldiv
B15 OPB15@muldiv
B16 OPB16@muldiv
B17 OPB17@muldiv
B18 OPB18@muldiv
B19 OPB19@muldiv
B20 OPB20@muldiv
B21 OPB21@muldiv
B22 OPB22@muldiv
B23 OPB23@muldiv
B24 OPB24@muldiv
B25 OPB25@muldiv
B26 OPB26@muldiv
B27 OPB27@muldiv
B28 OPB28@muldiv
B29 OPB29@muldiv
B30 OPB30@muldiv
B31 OPB31@muldiv
B0 OPB0@shift
B1 OPB1@shift
B2 OPB2@shift
B3 OPB3@shift
B4 OPB4@shift
FCOD0 FCOD0@alu
FCOD1 FCOD1@alu
FCOD2 FCOD2@alu
FCOD3 FCOD3@alu
FCOD0 FCOD0@muldiv
FCOD2 FCOD1@muldiv
FCOD0 FCOD0@shift
FCOD1 FCOD1@shift
C_IN CIN@alu
ENABLE_ALU SELA@resmux
ENABLE_MUL SELB@resmux
ENABLE_SHFT SELC@resmux
ENABLE_MUL SELA_SELB@ccmux
Y_IN0 YIN0@muldiv
Y_IN1 YIN1@muldiv
Y_IN2 YIN2@muldiv
Y_IN3 YIN3@muldiv
Y_IN4 YIN4@muldiv
Y_IN5 YIN5@muldiv
Y_IN6 YIN6@muldiv
Y_IN7 YIN7@muldiv
Y_IN8 YIN8@muldiv
Y_IN9 YIN9@muldiv
Y_IN10 YIN10@muldiv
Y_IN11 YIN11@muldiv
Y_IN12 YIN12@muldiv
Y_IN13 YIN13@muldiv
Y_IN14 YIN14@muldiv
Y_IN15 YIN15@muldiv
Y_IN16 YIN16@muldiv
Y_IN17 YIN17@muldiv
Y_IN18 YIN18@muldiv
Y_IN19 YIN19@muldiv
Y_IN20 YIN20@muldiv
Y_IN21 YIN21@muldiv
Y_IN22 YIN22@muldiv
Y_IN23 YIN23@muldiv
Y_IN24 YIN24@muldiv
Y_IN25 YIN25@muldiv
Y_IN26 YIN26@muldiv
Y_IN27 YIN27@muldiv
Y_IN28 YIN28@muldiv
Y_IN29 YIN29@muldiv
Y_IN30 YIN30@muldiv
Y_IN31 YIN31@muldiv

RES0@alu A0@resmux
RES1@alu A1@resmux
RES2@alu A2@resmux
RES3@alu A3@resmux
RES4@alu A4@resmux
RES5@alu A5@resmux
RES6@alu A6@resmux
RES7@alu A7@resmux
RES8@alu A8@resmux
RES9@alu A9@resmux
RES10@alu A10@resmux
RES11@alu A11@resmux
RES12@alu A12@resmux
RES13@alu A13@resmux
RES14@alu A14@resmux
RES15@alu A15@resmux
RES16@alu A16@resmux
RES17@alu A17@resmux
RES18@alu A18@resmux
RES19@alu A19@resmux
RES20@alu A20@resmux
RES21@alu A21@resmux
RES22@alu A22@resmux
RES23@alu A23@resmux
RES24@alu A24@resmux
RES25@alu A25@resmux
RES26@alu A26@resmux
RES27@alu A27@resmux
RES28@alu A28@resmux
RES29@alu A29@resmux
RES30@alu A30@resmux
RES31@alu A31@resmux
RES0@muldiv B0@resmux
RES1@muldiv B1@resmux
RES2@muldiv B2@resmux
RES3@muldiv B3@resmux
RES4@muldiv B4@resmux
RES5@muldiv B5@resmux
RES6@muldiv B6@resmux
RES7@muldiv B7@resmux
RES8@muldiv B8@resmux
RES9@muldiv B9@resmux
RES10@muldiv B10@resmux
RES11@muldiv B11@resmux
RES12@muldiv B12@resmux
RES13@muldiv B13@resmux
RES14@muldiv B14@resmux
RES15@muldiv B15@resmux
RES16@muldiv B16@resmux
RES17@muldiv B17@resmux
RES18@muldiv B18@resmux
RES19@muldiv B19@resmux
RES20@muldiv B20@resmux
RES21@muldiv B21@resmux
RES22@muldiv B22@resmux
RES23@muldiv B23@resmux
RES24@muldiv B24@resmux
RES25@muldiv B25@resmux
RES26@muldiv B26@resmux
RES27@muldiv B27@resmux
RES28@muldiv B28@resmux
RES29@muldiv B29@resmux
RES30@muldiv B30@resmux
RES31@muldiv B31@resmux
RES0@shift C0@resmux
RES1@shift C1@resmux
RES2@shift C2@resmux
RES3@shift C3@resmux
RES4@shift C4@resmux
RES5@shift C5@resmux
RES6@shift C6@resmux
RES7@shift C7@resmux
RES8@shift C8@resmux
RES9@shift C9@resmux
RES10@shift C10@resmux
RES11@shift C11@resmux
RES12@shift C12@resmux
RES13@shift C13@resmux
RES14@shift C14@resmux
RES15@shift C15@resmux
RES16@shift C16@resmux
RES17@shift C17@resmux
RES18@shift C18@resmux
RES19@shift C19@resmux
RES20@shift C20@resmux
RES21@shift C21@resmux
RES22@shift C22@resmux
RES23@shift C23@resmux
RES24@shift C24@resmux
RES25@shift C25@resmux
RES26@shift C26@resmux
RES27@shift C27@resmux
RES28@shift C28@resmux
RES29@shift C29@resmux
RES30@shift C30@resmux
RES31@shift C31@resmux

C@alu B0@ccmux
V@alu B1@ccmux
Z@alu B2@ccmux
N@alu B3@ccmux

V@muldiv A1@ccmux
Z@muldiv A2@ccmux
N@muldiv A3@ccmux

OUT0@resmux C0
OUT1@resmux C1
OUT2@resmux C2
OUT3@resmux C3
OUT4@resmux C4
OUT5@resmux C5
OUT6@resmux C6
OUT7@resmux C7
OUT8@resmux C8
OUT9@resmux C9
OUT10@resmux C10
OUT11@resmux C11
OUT12@resmux C12
OUT13@resmux C13
OUT14@resmux C14
OUT15@resmux C15
OUT16@resmux C16
OUT17@resmux C17
OUT18@resmux C18
OUT19@resmux C19
OUT20@resmux C20
OUT21@resmux C21
OUT22@resmux C22
OUT23@resmux C23
OUT24@resmux C24
OUT25@resmux C25
OUT26@resmux C26
OUT27@resmux C27
OUT28@resmux C28
OUT29@resmux C29
OUT30@resmux C30
OUT31@resmux C31
YOUT0@muldiv Y_OUT0
YOUT1@muldiv Y_OUT1
YOUT2@muldiv Y_OUT2
YOUT3@muldiv Y_OUT3
YOUT4@muldiv Y_OUT4
YOUT5@muldiv Y_OUT5
YOUT6@muldiv Y_OUT6
YOUT7@muldiv Y_OUT7
YOUT8@muldiv Y_OUT8
YOUT9@muldiv Y_OUT9
YOUT10@muldiv Y_OUT10
YOUT11@muldiv Y_OUT11
YOUT12@muldiv Y_OUT12
YOUT13@muldiv Y_OUT13
YOUT14@muldiv Y_OUT14
YOUT15@muldiv Y_OUT15
YOUT16@muldiv Y_OUT16
YOUT17@muldiv Y_OUT17
YOUT18@muldiv Y_OUT18
YOUT19@muldiv Y_OUT19
YOUT20@muldiv Y_OUT20
YOUT21@muldiv Y_OUT21
YOUT22@muldiv Y_OUT22
YOUT23@muldiv Y_OUT23
YOUT24@muldiv Y_OUT24
YOUT25@muldiv Y_OUT25
YOUT26@muldiv Y_OUT26
YOUT27@muldiv Y_OUT27
YOUT28@muldiv Y_OUT28
YOUT29@muldiv Y_OUT29
YOUT30@muldiv Y_OUT30
YOUT31@muldiv Y_OUT31
OUT0@ccmux C
OUT1@ccmux V
OUT2@ccmux Z
OUT3@ccmux N

[resmux]
nbits : 32
nports : 3

[alu]
[muldiv]
[shift]
[ccmux]

[c1]
initial : 1

[dpc]
nbits : 32
response : 0:0:0:0
