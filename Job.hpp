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
#include <stdexcept>
#include "Task.hpp"
using namespace std;

class Job
{
public:
	Job();
	Job(vector<pair<long, long> > Job, unsigned long jobID);
	Job(const Job& aJob);

	virtual ~Job();

	Job& operator=(const Job& aJob);
	Task& operator[](int idx);
	const Task& operator[](int idx) const;

	void reCalculate();
	void startTask(unsigned long startTijd);
	bool isEmpty();

	unsigned long getTotalTime() const;
	unsigned long getMachine() const;
	unsigned long size() const;

	unsigned long getJobId() const;

	signed long getExecutionEndTime() const
	{
		return executionEndTime;
	}

	signed long getExecutionStartTime() const
	{
		return executionStartTime;
	}

private:
	unsigned long jobID;
	unsigned long totalTime;
	vector<Task> tasks;
	signed long executionStartTime;
	signed long executionEndTime;

};

#endif /* JOB_HPP_ */
