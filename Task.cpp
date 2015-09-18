/*
 * Task.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */

#include "Task.hpp"
#include<iostream>
using namespace std;
//Krijgt Jobs binnen en doet er nog niks mee. Doe maar even couten

Task::Task()
{
}

Task::Task(unsigned long machine, unsigned long tijdsduur, unsigned long jobID) :
		machine(machine), tijdsduur(tijdsduur), jobID(jobID)
{
	cout << machine << " " << tijdsduur << " " << jobID << endl;
}

Task::Task(const Task& aTask) :
		machine(aTask.machine), tijdsduur(aTask.tijdsduur), jobID(aTask.jobID)
{
}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

Task& Task::operator=(const Task& aTask)
{
	if (this != &aTask)
	{
		machine = aTask.machine;
		tijdsduur = aTask.tijdsduur;
		jobID = aTask.jobID;
	}
	return *this;
}

