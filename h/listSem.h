/*
 * listPCB.h
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */

#ifndef LISTSEM_H_
#define LISTSEM_H_
#include "kerSem.h"
#include "SCHEDULE.h"

class listSem
{

	struct node
	{
		KernelSem* data;
		node* next;

	};


public:

	node* head;
	node* tail;

	listSem()

	{
		head=0;
		tail=0;
	}


~listSem();

void add_node(KernelSem* n);

void reduceTimeinAllSems();

};




#endif /* LISTPCB_H_ */
