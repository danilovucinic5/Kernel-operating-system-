/*
 * listPCB.h
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */

#ifndef LISTPCB_H_
#define LISTPCB_H_
#include "pcb.h"
#include "SCHEDULE.h"

class listPCB
{

	struct node
	{
		PCB* data;
		node* next;

	};


public:

	node* head;
	node* tail;

	listPCB()

	{
		head=0;
		tail=0;
	}


~listPCB();

void add_node(PCB* n);

PCB* findID(int ID);

void unblockAndDelete();			//za waittocomplete brisanje svih blokiranih
void unblockAndDeleteFirst();   //za signal semafora samo prvi
int reduceTime();				//za timer kad smanjuje toWait
};




#endif /* LISTPCB_H_ */
