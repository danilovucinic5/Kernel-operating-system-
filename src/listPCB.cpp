/*
 * listPCB.cpp
 *
 *  Created on: Aug 16, 2020
 *      Author: OS1
 */
#include "listPCB.h"





int listPCB:: reduceTime()
{
	int ret=0;
	node* tmp;
	node* tmp1;

	tmp=head;
	tmp1=0;

	int toIncrease=1;


	while (tmp!=0)
	{
		toIncrease=1;
		if (tmp->data->toWait>0)
		{

			if (--(tmp->data->toWait)==0)
			{


				tmp->data->blocked=0;
				tmp->data->toWait=-1;
				tmp->data->unblockedByTimer=1;
				Scheduler::put(tmp->data);
				ret++;

			//funkcija vraca broj odblokiranih da bi u funkciji iznad povecao value za toliko i tako za svaku listu semafora

				if (tmp==head)
				{
					if (tmp->next==0)
					{
						head=0;
						tail=0;
						delete tmp;
						tmp=0;
						toIncrease=0;
					}
					else
					{
						head=head->next;
						delete tmp;
						tmp=head;
						toIncrease=0;
					}
				}
				else if(tmp->next==0)
				{
					tmp1->next=0;
					tail=tmp1;
					delete tmp;
					tmp=0;
					toIncrease=0;
				}
				else
				{
					tmp1->next=tmp->next;
					delete tmp;
					tmp=tmp1->next;
					toIncrease=0;
				}



			}
		}
		if (toIncrease==1)
		{
			tmp1=tmp;
			tmp=tmp->next;
		}

	}
return ret;
}


listPCB::~listPCB()
{
	node* tmp=head;
	node* tmp1=0;

	while (tmp!=0)
	{
		tmp1=tmp;
		tmp=tmp->next;
		delete tmp1;
	}
}




void listPCB::unblockAndDeleteFirst()
{
	node* tmp=head;

	if (head->next!=0)
		head=head->next;
	else
	{
		head=0;
		tail=0;
	}
	tmp->data->blocked=0;
	tmp->data->toWait=-1;
	tmp->data->unblockedByTimer=0;

	Scheduler::put(tmp->data);

	delete tmp;
}

 void listPCB::add_node(PCB* n)
 {
 	        node *tmp = new node;
 	        tmp->data = n;
 	        tmp->next = 0;

 	        if(head == 0)
 	        {
 	            head = tmp;
 	            tail = tmp;
 	        }
 	        else
 	        {
 	            tail->next = tmp;
 	            tail = tail->next;
 	        }
 	    }


 PCB* listPCB::findID(int ID)
 {
	 node* tmp=head;

	 while(tmp!=0)
	 {
		 if (tmp->data->id==ID)
			 return tmp->data;

		 tmp=tmp->next;
	 }
	 return 0;
 }
 void listPCB::unblockAndDelete()
 {
	 node* tmp=head;
	 node* tmp1=head;

	 while (tmp!=0)
	 {
		 tmp1=tmp;
		 tmp=tmp->next;

		 tmp1->data->blocked=0;

		 Scheduler::put(tmp1->data);

		 delete tmp1;

	 }

	 head=0;
	 tail=0;

 }
