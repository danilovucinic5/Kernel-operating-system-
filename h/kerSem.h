/*
 * kerSem.h
 *
 *  Created on: Aug 18, 2020
 *      Author: OS1
 */

#include "listPCB.h"
#include "listSem.h"

// zabranjuje prekide
#define lock lockFlag=0;
// dozvoljava prekide
#define unlock lockFlag=1;

#ifndef KERSEM_H_
#define KERSEM_H_
typedef unsigned int Time;
class listPCB;

class listSem;

 extern listSem allSem;


class KernelSem
{
public:
	volatile int value;
	listPCB* blockedBySem;			//ove dve liste ne zaboravi da obrises u destuktotru kernel sema
	KernelSem (int init=1);
virtual ~KernelSem ();
void  unblock();
virtual int wait (Time maxTimeToWait);
virtual int signal(int n=0);
int val () const; // Returns the current value of the semaphore
private:
 };



#endif /* KERSEM_H_ */
