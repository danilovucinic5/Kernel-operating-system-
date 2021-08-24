#include "KerEv.h"





KernelEv::KernelEv (IVTNo ivtNo,PCB* running)
{
	myPCB=running;
	val=0;
	blocked=0;

	IVTarray[ivtNo]->KerEv=this;
}






 void KernelEv::wait ()
 {
	 if (running!=this->myPCB)
		 return;

	 if (val==1)
		 val=0;
	 else
	 {
		 blocked=1;
		 running->blocked=1;
		 dispatch();
	 }


 }
 void KernelEv:: signal()
 {
	 if (blocked==1)
	 {
		 lock
		 myPCB->blocked=0;
		 Scheduler::put((PCB*)myPCB);
		 unlock

		 blocked=0;
	 }
	 else

		 val=1;


 }
