/*
 * listSem.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: OS1
 */




#include "listSem.h"


 void listSem::add_node(KernelSem* n)
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


 listSem::~listSem()
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





 void listSem::reduceTimeinAllSems()
 {

		node* tmp=head;
		int toIncrease;
										//ovde gledam koliko da uvecam sem tj koliko sam niti odblokirao
	 	 while(tmp!=0)
	 	 {




	 		toIncrease= tmp->data->blockedBySem->reduceTime();
	 		tmp->data->value=tmp->data->value+toIncrease;
	 		 tmp=tmp->next;
	 	 }



 }
