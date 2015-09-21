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
using namespace std;

class Job
{
public:
	Job();
	Job(vector<pair<long, long>> Job);
	Job(const Job& aJob);
	virtual ~Job();
	Job& operator=(const Job& aJob);

private:
	unsigned long machine;
	unsigned long tijdsduur;
	unsigned long jobID;
};

#endif /* JOB_HPP_ */
