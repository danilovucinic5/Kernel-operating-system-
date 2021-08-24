/*
 * timer.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */
#include "timer.h"




 unsigned tsp=0;
 unsigned tss=0;
 unsigned tbp=0;

 volatile int lockFlag=0;
 volatile int cntr =2 ;
 volatile int context_switch_on_demand=0 ;

 extern void tick();
 void interrupt timer(){




	if (!context_switch_on_demand)
	{

		tick();
		cntr--;
		lock
		allSem.reduceTimeinAllSems();
		unlock
	}

	if (cntr == 0 || context_switch_on_demand) {
	if (lockFlag)
		{





			context_switch_on_demand = 0;

		asm {
			// cuva sp
			mov tsp, sp
			mov tss, ss
			mov tbp, bp
		}

		running->sp = tsp;
		running->ss = tss;
		running->bp = tbp;

		// scheduler
	//	running = getNextPCBToExecute();

	//	 tmp=running;



		if (running->finished==0 && running->blocked==0)
			Scheduler::put((PCB*)running);



		running=Scheduler::get();



		if (running==0)
			running=allPCB.findID(0);





		tsp = running->sp;
		tss = running->ss;
		tbp=	running->bp;
		cntr = running->quantum;

		asm {
			// restaurira sp
			mov sp, tsp
			mov ss, tss
			mov bp, tbp
		}
	}
	else
			context_switch_on_demand = 1;

	// poziv stare prekidne rutine
	// koja se nalazila na 08h, a sad je na 60h;
	// poziva se samo kada nije zahtevana promena konteksta
	// tako da se stara rutina poziva
	// samo kada je stvarno doslo do prekida
	}


		if(!context_switch_on_demand) asm int 60h;


}



