/*
 * Task.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: Maurice
 */

#include "Task.hpp"
#include<iostream>
using namespace std;
//Krijgt Jobs binnen en doet er nog niks mee. Doe maar even couten

Task::Task()
{
	machine = 0;
	tijdsduur = 0;
	jobID = 0;
	startTime= 0;
	endTime = 0;
	cout << "Niet de default constructor aanroepen" << endl;
}

Task::Task(unsigned long machine, unsigned long tijdsduur, unsigned long jobID) :
		machine(machine), tijdsduur(tijdsduur), jobID(jobID)
{
	cout << machine << " " << tijdsduur << " " << jobID << endl;
}

Task::Task(const Task& aTask) :
		machine(aTask.machine), tijdsduur(aTask.tijdsduur), jobID(aTask.jobID), startTime(aTask.startTime), endTime(aTask.endTime)
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

unsigned long Task::getTijdsduur() const
{
	return tijdsduur;
}

unsigned long Task::getEndTime() const
{
	return endTime;
}

unsigned long Task::getStartTime() const
{
	return startTime;
}
