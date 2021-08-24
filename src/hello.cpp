//  v2_zad4.cpp
//  prevodjenje iz komandne linije: bcc -mh -Ic:\bc31\include -Lc:\bc31\lib v2_zad4.cpp

//pretpostavljeni memorijski model: huge
#include <iostream.h>
#include <dos.h>
#include "SCHEDULE.h"
#include "pcb.h"
#include "timer.h"
#include "thread.h"
#include "system.h"
#include "kerSem.h"
#include "semaphor.h"
#include "listSem.h"
#include "KerEv.h"
#include "event.h"
#include "IVTE.h"




// zabranjuje prekide
#define lock lockFlag=0;
// dozvoljava prekide
#define unlock lockFlag=1;

class Thread;



void exitThread(){
	running->finished = 1;
	dispatch();
}

extern int userMain (int argc, char* argv[]);

class Idle:public Thread
{

void run()
{
	while (1)
		{



		}


}
public:
~Idle()
{

}

};
class A:public Thread
{

void run()
{
	while (1)
		{

			lock
			cout<<"nit A";
			unlock

		}


}
public:
~A()
{

}

};


void doSomething(int argc, char* argv[]){


	//asm sti
		lock



		Idle idle;


		PCB* main=new PCB();
		main->id=idCounter++;
		running = main;
		running->finished = 0;
		running->blocked = 0;
		running->quantum = 5;
		running->toWait=-1;
		allPCB.add_node(main);




	unlock

	// A a;
	// a.start();





	userMain(argc,argv);



	//exitThread();
}



int main(int argc, char* argv[]){

	inic();

	doSomething(argc,argv);

	restore();

	return 0;

}
