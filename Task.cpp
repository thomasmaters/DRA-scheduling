/*
 * Task.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: Maurice
 */

#include "Task.hpp"
#include<iostream>

Task::Task() :
		machine(0), tijdsduur(0), jobID(0), startTime(0), endTime(0)
{
}

Task::Task(unsigned long machine, unsigned long tijdsduur, unsigned long jobID) :
		machine(machine), tijdsduur(tijdsduur), jobID(jobID), startTime(0), endTime(
				0)
{
}

Task::Task(const Task& aTask) :
		machine(aTask.machine), tijdsduur(aTask.tijdsduur), jobID(aTask.jobID), startTime(
				aTask.startTime), endTime(aTask.endTime)
{
}

Task::~Task()
{
}

Task& Task::operator=(const Task& aTask)
{
	if (this != &aTask)
	{
		machine = aTask.machine;
		tijdsduur = aTask.tijdsduur;
		jobID = aTask.jobID;
		startTime = aTask.startTime;
		endTime = aTask.endTime;
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

unsigned long Task::getMachine() const
{
	return machine;
}

void Task::startTask(unsigned long startTijd)
{
	startTime = startTijd;
	endTime = startTime + tijdsduur;
}
