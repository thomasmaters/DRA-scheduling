/*
 * Job.hpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
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
	Job(Job& aJob);
	virtual ~Job();

private:
	unsigned long jobID;
};

#endif /* JOB_HPP_ */
