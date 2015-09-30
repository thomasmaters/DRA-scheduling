/*
 * Job.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: Maurice
 */

#include "Job.hpp"
#include <vector>
#include <iostream>

Job::Job() :
		jobID(0), totalTime(0), executionStartTime(-1), executionEndTime(-1)
{
}

Job::Job(vector<pair<long, long>> Job, unsigned long jobID) :
		jobID(jobID), totalTime(0), executionStartTime(-1), executionEndTime(-1)
{
	for (unsigned long i = 0; i < Job.size(); ++i)
	{
		unsigned long machine = Job[i].first;
		unsigned long tijdsduur = Job[i].second;
		tasks.push_back(Task(machine, tijdsduur, jobID));
		totalTime += tijdsduur;
	}
}

Job::Job(const Job& aJob) :
		jobID(aJob.jobID), totalTime(aJob.totalTime), tasks(aJob.tasks), executionStartTime(
				aJob.executionStartTime), executionEndTime(
				aJob.executionEndTime)
{
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

Job& Job::operator=(const Job& aJob)
{
	if (this != &aJob)
	{
		jobID = aJob.jobID;
		totalTime = aJob.totalTime;
		tasks = aJob.tasks;
		executionStartTime = aJob.executionStartTime;
		executionEndTime = aJob.executionEndTime;
	}
	return *this;
}

void Job::reCalculate()
{
	if (executionStartTime == -1)
	{
		executionStartTime = tasks[0].getStartTime();
	}
	totalTime -= tasks[0].getTijdsduur();

	tasks.erase(tasks.begin());
}

bool Job::isEmpty()
{
	return tasks.empty();
}

Task& Job::operator [](int idx)
{
	try
	{
		return tasks.at(idx);
	}

	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	return tasks[0];
}

const Task& Job::operator [](int idx) const
{
	try
	{
		return tasks[idx];
	}

	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	return tasks[0];
}

unsigned long Job::getTotalTime() const
{
	return totalTime;
}

unsigned long Job::getMachine() const
{
	return tasks[0].getMachine();
}

void Job::startTask(unsigned long startTijd)
{
	if (tasks.size() == 1)
	{
		executionEndTime = startTijd + tasks[0].getTijdsduur();
	}
	tasks[0].startTask(startTijd);
}

unsigned long Job::size() const
{
	return tasks.size();
}

unsigned long Job::getJobId() const
{
	return jobID;
}
