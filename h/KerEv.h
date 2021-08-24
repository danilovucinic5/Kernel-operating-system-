/*
 * KerEv.h
 *
 *  Created on: Aug 20, 2020
 *      Author: OS1
 */


#ifndef KEREV_H_
#define KEREV_H_

#include "IVTE.h"
#include "thread.h"

// zabranjuje prekide
#define lock lockFlag=0;
// dozvoljava prekide
#define unlock lockFlag=1;
typedef unsigned char IVTNo;

class KernelEv
{

public:
 KernelEv (IVTNo ivtNo,PCB* running);
 PCB* myPCB;
 void wait ();
 void signal();
int val;
int blocked;    //dal je blokirana

};



#endif /* KEREV_H_ */
