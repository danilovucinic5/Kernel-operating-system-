/*
 * thread.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */
#include "thread.h"





 listPCB allPCB;




 volatile PCB* running=0;
int idCounter=0;


 void dispatch(){



	 asm cli
 	context_switch_on_demand = 1;

 	timer();
 	asm sti

 }

 Thread::~Thread()
 {
	 	 delete myPCB;
	 	 delete blockedPCB;

 }


 Thread::Thread(StackSize stackSize , Time timeSlice
 		 )
 {




	 blockedPCB=new listPCB();
 	PCB *pcb=new PCB();
 	if(idCounter==0)
 		pcb->quantum=1;				//posto je idle ID 0 pa za nju quantum 1
 	else
 	pcb->quantum=timeSlice;
 	pcb->unblockedByTimer=0;
 	if(idCounter==0)
 	{
 		pcb->finished=1;				//opet za idle
 		 	pcb->blocked=1;
 	}
 	else
 	{
 	pcb->finished=0;
 	pcb->blocked=0;
 	}
 	pcb->ready=0;
 	pcb->toWait=-1;
 	pcb->stack=new unsigned[stackSize/sizeof(unsigned)];
 	pcb->myThread=this;
 	this->myPCB=pcb;

 	this->id=idCounter;
 	pcb->id=idCounter++;
 	//za sad sam stavio oba da imaju to polje pa cemo videti gde

 	pcb->stack[stackSize/sizeof(unsigned)-1]=0x200;


 	pcb->stack[stackSize/sizeof(unsigned)-2]=FP_SEG(PCB::wrapper);
 	pcb->stack[stackSize/sizeof(unsigned)-3]=FP_OFF(PCB::wrapper);

 	pcb->sp=FP_OFF(pcb->stack+(stackSize/sizeof(unsigned))-12);
 	pcb->ss=FP_SEG(pcb->stack+(stackSize/sizeof(unsigned))-12);
 	//i base pointer treba staviti mislim kao fp seg iznad


 	allPCB.add_node(pcb);

 }


 void Thread::start()
 {


	 if (this->myPCB->blocked==1||this->myPCB->finished==1||this->myPCB->ready==1)

		 return ;
		 else
		 {
			 this->myPCB->ready=1;

 		Scheduler::put(this->myPCB);

		 	 }

 }

 ID Thread:: getRunningId()
 {
	 return running->id;
 }
  Thread* Thread:: getThreadById(ID id)
  {
	  return allPCB.findID(id)->myThread;
  }

  ID Thread:: getId()
  {
	  return this->id;
  }


  void Thread:: waitToComplete()
  {



	 if(running==this->myPCB||this->myPCB->finished==1||this->id==0) //poslednji uslov provera jel Idle
	 {
		// cout<<"ne seri  da si ovde uso"<<endl;


		 return;
	 }


	 lock

	 running->blocked=1;

	  this->blockedPCB->add_node((PCB*)running);

	  unlock
	  dispatch();



  }

