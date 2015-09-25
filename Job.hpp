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
	Task& operator[](int idx);
	const Task& operator[](int idx) const;

	void reCalculate();
	void startTask(unsigned long startTijd);
	bool isEmpty();

	unsigned long getTotalTime() const;
	unsigned long getMachine() const;
	unsigned long size() const;

private:
	unsigned long jobID;
	unsigned long totalTime;
	vector<Task> tasks;
	signed long executionStartTime;
	signed long executionEndTime;


};

#endif /* JOB_HPP_ */
