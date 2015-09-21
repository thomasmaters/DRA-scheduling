/*
 * Job.hpp
 *
 *  Created on: 17 sep. 2015
 *      Author: Maurice
 */

#ifndef JOB_HPP_
#define JOB_HPP_
#include <iostream>
#include <vector>
#include "Task.hpp"
using namespace std;

class Job
{
public:
	Job();
	Job(vector<pair<long, long>> Job);
	Job(const Job& aJob);
	virtual ~Job();
	Job& operator=(const Job& aJob);
	void reCalculate();
	bool isEmpty();

private:
	unsigned long machine;
	unsigned long tijdsduur;
	unsigned long jobID;
	unsigned long totalTime;
	vector<Task> tasks;
};

#endif /* JOB_HPP_ */
