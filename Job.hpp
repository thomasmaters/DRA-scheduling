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

class Job
{
public:
	Job();
	Job(std::vector<std::pair<long, long> > Job, unsigned long jobID);
	Job(const Job& aJob);
	virtual ~Job();

	Job& operator=(const Job& aJob);
	const Task& operator[](unsigned char idx) const;

	void reCalculate();
	void startTask(unsigned long startTijd);
	bool isEmpty();

	unsigned long getTotalTime() const;
	unsigned long getMachine() const;
	unsigned long size() const;

	unsigned long getJobId() const;

	signed long getExecutionEndTime() const;
	signed long getExecutionStartTime() const;

private:
	unsigned long jobID;
	unsigned long totalTime;
	std::vector<Task> tasks;
	signed long executionStartTime;
	signed long executionEndTime;

};

#endif /* JOB_HPP_ */
