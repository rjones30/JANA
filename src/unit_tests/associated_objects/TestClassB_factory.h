// $Id$
//
//    File: TestClassB_factory.h
// Created: Thu May 21 13:30:12 EDT 2015
// Creator: davidl (on Linux gluon47.jlab.org 2.6.32-358.23.2.el6.x86_64 x86_64)
//

#ifndef _TestClassB_factory_
#define _TestClassB_factory_

#include <JANA/JFactory.h>
#include "TestClassB.h"
#include "TestClassB.h"

class TestClassB_factory:public jana::JFactory<TestClassB>{
	public:
		TestClassB_factory(){};
		~TestClassB_factory(){};


	private:
		jerror_t init(void){}
		jerror_t brun(jana::JEventLoop *eventLoop, int runnumber){}
		jerror_t erun(void){}
		jerror_t fini(void){}

		jerror_t evnt(jana::JEventLoop *loop, int eventnumber){
		
			vector<const TestClassA*> objsA;
			loop->Get(objsA);

			// Create objects of type TestClassB for the first half of the
			// TestClassA objects and associate them. 
			for(uint32_t i=0; i<objsA.size()/2; i++){
				
				TestClassB *objB = new TestClassB;
				objB->AddAssociatedObject(objsA[i]);

				_data.push_back(objB);
			}
			
			// Also add one more TestClassA as an associated object
			// to the last TestClassB object
			_data[_data.size()-1]->AddAssociatedObject(objsA[_data.size()]);
		}
};

#endif // _TestClassB_factory_

