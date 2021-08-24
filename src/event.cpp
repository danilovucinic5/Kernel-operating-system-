/*
 * event.cpp
 *
 *  Created on: Aug 20, 2020
 *      Author: OS1
 */
#include "event.h"



Event::Event (IVTNo ivtNo)
{
	myImpl=new KernelEv(ivtNo,(PCB*)running);
}
 Event::~Event ()
 {
	 delete myImpl;
 }

 void Event:: wait ()
 {
	 myImpl->wait();
 }

 void Event ::signal()
 {
	 myImpl->signal();
 }
