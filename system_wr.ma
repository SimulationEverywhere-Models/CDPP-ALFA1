[top]
components : Mem1@Mem1 Bus1@Bus1 BIU@BIU

in : START
Link : START START@BIU
Link : BusReq@BIU Bus_Req@Bus1
Link : Bus_Grant@Bus1 BusGrant@BIU
Link : RDWR@BIU RD_WR@Mem1
Link : Address0@BIU A0@Mem1
Link : Address1@BIU A1@Mem1
Link : Address2@BIU A2@Mem1
Link : Address3@BIU A3@Mem1
Link : Address4@BIU A4@Mem1
Link : Address5@BIU A5@Mem1
Link : Address6@BIU A6@Mem1
Link : Address7@BIU A7@Mem1
Link : Address8@BIU A8@Mem1
Link : Address9@BIU A9@Mem1
Link : Address10@BIU A10@Mem1
Link : Address11@BIU A11@Mem1
Link : Address12@BIU A12@Mem1
Link : Address13@BIU A13@Mem1
Link : Address14@BIU A14@Mem1
Link : Address15@BIU A15@Mem1
Link : Address16@BIU A16@Mem1
Link : Address17@BIU A17@Mem1
Link : Address18@BIU A18@Mem1
Link : Address19@BIU A19@Mem1
Link : Address20@BIU A20@Mem1
Link : Address21@BIU A21@Mem1
Link : Address22@BIU A22@Mem1
Link : Address23@BIU A23@Mem1
Link : Address24@BIU A24@Mem1
Link : Address25@BIU A25@Mem1
Link : Address26@BIU A26@Mem1
Link : Address27@BIU A27@Mem1
Link : Address28@BIU A28@Mem1
Link : Address29@BIU A29@Mem1
Link : Address30@BIU A30@Mem1
Link : Address31@BIU A31@Mem1

Link : OutData0@BIU IN_DATA0@Mem1
Link : OutData1@BIU IN_DATA1@Mem1
Link : OutData2@BIU IN_DATA2@Mem1
Link : OutData3@BIU IN_DATA3@Mem1
Link : OutData4@BIU IN_DATA4@Mem1
Link : OutData5@BIU IN_DATA5@Mem1
Link : OutData6@BIU IN_DATA6@Mem1
Link : OutData7@BIU IN_DATA7@Mem1
Link : OutData8@BIU IN_DATA8@Mem1
Link : OutData9@BIU IN_DATA9@Mem1
Link : OutData10@BIU IN_DATA10@Mem1
Link : OutData11@BIU IN_DATA11@Mem1
Link : OutData12@BIU IN_DATA12@Mem1
Link : OutData13@BIU IN_DATA13@Mem1
Link : OutData14@BIU IN_DATA14@Mem1
Link : OutData15@BIU IN_DATA15@Mem1
Link : OutData16@BIU IN_DATA16@Mem1
Link : OutData17@BIU IN_DATA17@Mem1
Link : OutData18@BIU IN_DATA18@Mem1
Link : OutData19@BIU IN_DATA19@Mem1
Link : OutData20@BIU IN_DATA20@Mem1
Link : OutData21@BIU IN_DATA21@Mem1
Link : OutData22@BIU IN_DATA22@Mem1
Link : OutData23@BIU IN_DATA23@Mem1
Link : OutData24@BIU IN_DATA24@Mem1
Link : OutData25@BIU IN_DATA25@Mem1
Link : OutData26@BIU IN_DATA26@Mem1
Link : OutData27@BIU IN_DATA27@Mem1
Link : OutData28@BIU IN_DATA28@Mem1
Link : OutData29@BIU IN_DATA29@Mem1
Link : OutData30@BIU IN_DATA30@Mem1
Link : OutData31@BIU IN_DATA31@Mem1
Link : OutData32@BIU IN_DATA32@Mem1

Link : OUT_DATA0@Mem1 InData0@BIU
Link : OUT_DATA1@Mem1 InData1@BIU
Link : OUT_DATA2@Mem1 InData2@BIU
Link : OUT_DATA3@Mem1 InData3@BIU
Link : OUT_DATA4@Mem1 InData4@BIU
Link : OUT_DATA5@Mem1 InData5@BIU
Link : OUT_DATA6@Mem1 InData6@BIU
Link : OUT_DATA7@Mem1 InData7@BIU
Link : OUT_DATA8@Mem1 InData8@BIU
Link : OUT_DATA9@Mem1 InData9@BIU
Link : OUT_DATA10@Mem1 InData10@BIU
Link : OUT_DATA11@Mem1 InData11@BIU
Link : OUT_DATA12@Mem1 InData12@BIU
Link : OUT_DATA13@Mem1 InData13@BIU
Link : OUT_DATA14@Mem1 InData14@BIU
Link : OUT_DATA15@Mem1 InData15@BIU
Link : OUT_DATA16@Mem1 InData16@BIU
Link : OUT_DATA17@Mem1 InData17@BIU
Link : OUT_DATA18@Mem1 InData18@BIU
Link : OUT_DATA19@Mem1 InData19@BIU
Link : OUT_DATA20@Mem1 InData20@BIU
Link : OUT_DATA21@Mem1 InData21@BIU
Link : OUT_DATA22@Mem1 InData22@BIU
Link : OUT_DATA23@Mem1 InData23@BIU
Link : OUT_DATA24@Mem1 InData24@BIU
Link : OUT_DATA25@Mem1 InData25@BIU
Link : OUT_DATA26@Mem1 InData26@BIU
Link : OUT_DATA27@Mem1 InData27@BIU
Link : OUT_DATA28@Mem1 InData28@BIU
Link : OUT_DATA29@Mem1 InData29@BIU
Link : OUT_DATA30@Mem1 InData30@BIU
Link : OUT_DATA31@Mem1 InData31@BIU

[BIU]
preparation : 00:00:05:000

[Mem1]
response : 00:00:10:000
% memsize : 256
% memfile : call.map
% dumpfile : memory.dmp

[Bus1]
response : 00:00:00:001