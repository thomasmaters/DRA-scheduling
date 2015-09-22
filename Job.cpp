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
		jobID(aJob.jobID), totalTime(aJob.totalTime)
{
	cout << "copy job" << endl;
}

Job::~Job()
{
	cout << "job is weg" << endl;
	// TODO Auto-generated destructor stub
}

Job& Job::operator=(const Job& aJob)
{
	if (this != &aJob)
	{
		jobID = aJob.jobID;
		totalTime = aJob.totalTime;
	}
	return *this;
}


void Job::reCalculate()
{
	totalTime -= tasks[0].getTijdsduur();
	tasks.erase(tasks.begin());
}

bool Job::isEmpty()
{
	return tasks.empty();
}

Task& Job::operator [](int idx)
{
	return tasks.at(idx);
}

const Task& Job::operator [](int idx) const
{
	return tasks[idx];
}

unsigned long Job::getTotalTime() const
{
	return totalTime;
}

unsigned long Job::getMachine() const
{
	cout << "machine is in job :" << tasks[0].getMachine();
	return tasks[0].getMachine();
}
