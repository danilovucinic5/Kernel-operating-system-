/*
 * timer.h
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "SCHEDULE.h"
#include "pcb.h"
#include "thread.h"
#include "kerSem.h"

extern unsigned tsp;
extern unsigned tss;
extern unsigned tbp;

extern volatile int lockFlag;
extern volatile int cntr  ;
extern volatile int context_switch_on_demand ;

extern void interrupt timer();


#endif /* TIMER_H_ */
