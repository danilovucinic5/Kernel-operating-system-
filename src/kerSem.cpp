/*
 * kerSem.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: OS1
 */
#include "kerSem.h"

listSem allSem;



void KernelSem::unblock()
{
	if(this->blockedBySem->head!=0)
	{
		this->blockedBySem->unblockAndDeleteFirst();

	}
}

KernelSem::KernelSem ( int init)
{
	value=init;
	this->blockedBySem=new listPCB();
	allSem.add_node(this);
}


KernelSem:: ~KernelSem ()
{
	delete this->blockedBySem;

}
 int KernelSem:: wait (Time maxTimeToWait)
 {


		 lock
		 if(--value<0)
				 {
		 running->blocked=1;
		 this->blockedBySem->add_node((PCB*)running);
		 if(maxTimeToWait>0)
		 running->toWait=maxTimeToWait;
		 unlock
		 dispatch();
		 }
		 unlock

	 if (running->unblockedByTimer==1)
	 {
		 running->unblockedByTimer=0;

		 return 0;

	 }
	 else
	 {

		 return 1;


	 }
 }


 int KernelSem:: signal(int n)
 {
	 int ret=0;
	 if (n<0)
		 return n;

	 lock

	 if (n>0)
	 {
		 for (int i=0;i<n;i++)
	 {
		 if(value++<0)
		 {
		 unblock();
		 ret++;
		 }
	 }

	 }
	 else
	 {
		 if(value++<0)
				 {
				 unblock();

				 }

	 }
	 unlock

	 return ret;

 }
int KernelSem:: val () const
{
	return value;
}
