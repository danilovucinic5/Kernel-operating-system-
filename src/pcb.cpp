/*
 * pcb.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */

#include "pcb.h"

void PCB:: wrapper()
{
	running->myThread->run();
	lock
	running->finished=1;
	running->myThread->blockedPCB->unblockAndDelete();
	unlock
	dispatch();
									//videcemo jos koji flegovi su potrebni

}


PCB::~PCB()
{
	delete stack;
}
