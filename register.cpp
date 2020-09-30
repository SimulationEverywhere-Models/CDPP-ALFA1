#include "ALU.h"
#include "AND.h"
#include "Adder.h"
#include "AlignL.h"
#include "AlignS.h"
#include "Bus.h"
#include "CCLogic.h"
#include "CS.h"
#include "CWPlogic.h"
#include "Clock.h"
#include "Cmp.h"
#include "FromDeci.h"
#include "IRQLogic.h"
#include "Inc4.h"
#include "IncDec.h"
#include "Latch.h"
#include "Mem.h"
#include "MulDiv.h"
#include "Mux.h"
#include "MuxN.h"
#include "NOT.h"
#include "RegBlock.h"
#include "RegGlob.h"
#include "Shifter.h"
#include "SignExtN.h"
#include "TestIn.h"
#include "TestOut.h"
#include "ToDeci.h"
#include "TrapLogic.h"
#include "UC.h"
#include "UCTest.h"
#include "WIMCheck.h"

#include <modeladm.h>
#include <mainsimu.h>

void MainSimulator::registerNewAtomics()
{

  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ALU>()     , "ALU" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AND>()     , "AND" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Adder>()     , "Adder" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AlignL>()     , "AlignL" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AlignS>()     , "AlignS" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Bus>()     , "Bus" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CCLogic>()     , "CCLogic" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CS>()     , "CS" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CWPlogic>()     , "CWPlogic" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Clock>()     , "Clock" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Cmp>()     , "Cmp" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<FromDeci>()     , "FromDeci" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<IRQLogic>()     , "IRQLogic" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Inc4>()     , "Inc4" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<IncDec>()     , "IncDec" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Latch>()     , "Latch" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Mem>()     , "Mem" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MulDiv>()     , "MulDiv" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Mux>()     , "Mux" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MuxN>()     , "MuxN" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<NOT>()     , "NOT" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<RegBlock>()     , "RegBlock" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<RegGlob>()     , "RegGlob" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Shifter>()     , "Shifter" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<SignExtN>()     , "SignExtN" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TestIn>()     , "TestIn" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TestOut>()     , "TestOut" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ToDeci>()     , "ToDeci" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TrapLogic>()     , "TrapLogic" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UC>()     , "UC" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<UCTest>()     , "UCTest" ) ;
  SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<WIMCheck>()     , "WIMCheck" ) ;
}
