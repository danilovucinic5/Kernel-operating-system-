/*
 * thread.h
 *
 *  Created on: Aug 12, 2020
 *      Author: OS1
 */
#include <iostream.h>
#include "timer.h"
#include "SCHEDULE.h"
#include <dos.h>
#include "pcb.h"
#include "listPCB.h"
#ifndef THREAD_H_
#define THREAD_H_



// zabranjuje prekide
#define lock lockFlag=0;
// dozvoljava prekide
#define unlock lockFlag=1;


extern volatile PCB* running;
extern int idCounter;

class listPCB;
extern listPCB allPCB;			//ne zaboravi ovu listu pre restorea da dealociras


typedef unsigned long StackSize;
const StackSize defaultStackSize = 4096;
typedef unsigned int Time; // time, x 55ms
const Time defaultTimeSlice = 2; // default = 2*55ms
typedef int ID;
class PCB; // Kernel's implementation of a user's thread




class Thread {
public:


ID id;
listPCB* blockedPCB;
 void start();
 void waitToComplete();
 virtual ~Thread();
 ID getId();
 static ID getRunningId();
 static Thread * getThreadById(ID id);
protected:
 friend class PCB;
 Thread (StackSize stackSize = defaultStackSize, Time timeSlice =
defaultTimeSlice);
 virtual void run() {}
private:
 PCB* myPCB;
};





extern void dispatch();



#endif /* THREAD_H_ */
