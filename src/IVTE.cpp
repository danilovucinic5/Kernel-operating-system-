/*
 * IVTE.cpp
 *
 *  Created on: Aug 20, 2020
 *      Author: OS1
 */
#include "IVTE.h"

IVTEntry::IVTEntry(IVTNo ivtNo,pInterrupt intr){

	no=ivtNo;
	lock
	oldR=getvect(ivtNo);
	setvect(ivtNo,intr);
	IVTarray[ivtNo]=this;
	unlock



}

IVTEntry* IVTarray[256];


void IVTEntry::signal()
{
	KerEv->signal();
}


void IVTEntry::callOldd()
{
	oldR();
}


IVTEntry::~IVTEntry()
{
	setvect(no,oldR);

}
