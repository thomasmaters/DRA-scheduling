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
	machine = 0;
	tijdsduur = 0;
	jobID = 0;
	cout << "Niet de default constructor aanroepen" << endl;
}

Job::Job(vector<pair<long, long>> Job)
{
	for (unsigned long i = 0; i < Job.size(); ++i)
	{
		machine = Job[i].first;
		tijdsduur = Job[i].second;
		jobID = i;
		tasks.push_back(Task(machine, tijdsduur, jobID));
	}
}

Job::Job(const Job& aJob) :
		machine(aJob.machine), tijdsduur(aJob.tijdsduur), jobID(aJob.jobID)
{
}

Job& Job::operator=(const Job& aJob)
{
	if (this != &aJob)
	{
		machine = aJob.machine;
		tijdsduur = aJob.tijdsduur;
		jobID = aJob.jobID;
	}
	return *this;
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}
