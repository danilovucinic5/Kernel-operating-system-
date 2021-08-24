/*
 * pcb.h
 *
 *  Created on: Aug 15, 2020
 *      Author: OS1
 */

#ifndef PCB_H_
#define PCB_H_
#include "thread.h"



// zabranjuje prekide
#define lock lockFlag=0;
// dozvoljava prekide
#define unlock lockFlag=1;

class PCB{
public:
volatile unsigned sp;
volatile unsigned bp;
volatile unsigned ss;
volatile unsigned finished;
volatile unsigned blocked;
volatile int toWait;
volatile int unblockedByTimer;
unsigned ready;
volatile int quantum;
	Thread* myThread;
	unsigned *stack;
int id;

~PCB();


	static void wrapper();
};



#endif /* PCB_H_ */
