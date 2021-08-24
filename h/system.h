/*
 * system.h
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "timer.h"


extern unsigned oldTimerOFF;
extern unsigned oldTimerSEG;
extern void inic();

extern void restore();
#endif /* SYSTEM_H_ */
