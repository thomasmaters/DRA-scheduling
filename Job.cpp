/*
 * Job.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: Maurice
 */

#include "Job.hpp"
#include <vector>
#include <iostream>
using namespace std;

//Hier komt een vector binnen met <2>,<1> vector[0].first, vector[0].second.
//Voor elke pair een task aanmaken
//Geef elke Job een ID.

Job::Job()
{
	jobID = 0;
	totalTime = 0;
	cout << "Niet de default constructor aanroepen" << endl;
}

Job::Job(vector<pair<long, long>> Job)
{
	for (unsigned long i = 0; i < Job.size(); ++i)
	{
		unsigned long machine = Job[i].first;
		unsigned long tijdsduur = Job[i].second;
		jobID = i;
		tasks.push_back(Task(machine, tijdsduur, jobID));
		totalTime += tijdsduur;
	}
}

Job::Job(const Job& aJob) :
		jobID(aJob.jobID), totalTime(aJob.totalTime), tasks(aJob.tasks)
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
	}
	return *this;
}


void Job::reCalculate()
{
	cout << tasks[0].getMachine() << " " << tasks[0].getTijdsduur() << endl;
	totalTime -= tasks[0].getTijdsduur();

	tasks.erase(tasks.begin());
}

bool Job::isEmpty()
{
	return tasks.empty();
}

Task& Job::operator [](int idx)
{
	if (tasks.size() > 0){
		return tasks[idx];
	}
	return std::cout << "out of bound" << std::endl;
}

const Task& Job::operator [](int idx) const
{
	if (tasks.size() > 0){
		return tasks[idx];
	}
	return std::cout << "out of bound" << std::endl;
}

unsigned long Job::getTotalTime() const
{
	return totalTime;
}

unsigned long Job::getMachine() const
{
	return tasks[0].getMachine();
}
