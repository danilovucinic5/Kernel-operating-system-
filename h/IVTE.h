/*
 * IVTE.h
 *
 *  Created on: Aug 20, 2020
 *      Author: OS1
 */



#ifndef IVTE_H_
#define IVTE_H_
#include "KerEv.h"
#include <dos.h>
// zabranjuje prekide
#define lock lockFlag=0;
// dozvoljava prekide
#define unlock lockFlag=1;




typedef void interrupt (*pInterrupt)(...);
typedef unsigned char IVTNo;

class KernelEv;

class IVTEntry
{


public:


IVTEntry(IVTNo ivtNo,pInterrupt intr);

~IVTEntry();
	IVTNo no;
	pInterrupt oldR;
	pInterrupt newR;
	void signal();
	KernelEv* KerEv;
	void callOldd();

};



extern IVTEntry* IVTarray[256];


#define PREPAREENTRY(numEntry, callOld)\
void interrupt inter##numEntry(...); \
IVTEntry newEntry##numEntry(numEntry, inter##numEntry); \
void interrupt inter##numEntry(...) {\
newEntry##numEntry.signal();\
if (callOld == 1)\
newEntry##numEntry.callOldd();\
}


#endif /* IVTE_H_ */
