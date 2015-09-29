/*
 * JobShop.hpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */

#ifndef JOBSHOP_HPP_
#define JOBSHOP_HPP_
#include <string>
#include <vector>
#include "Job.hpp"

class JobShop
{
public:
	JobShop();
	JobShop(const string &filepath);
	JobShop(const JobShop &JS);

	string readFromConsole() const;
	string readFile(const string fileName);

	virtual ~JobShop();
private:
	void generateOutput();
	bool checkForJobs();
	void calculate();
	void sortJobs();
	void assignTasks(unsigned long minuten);

	unsigned long job_count;
	unsigned long machine_count;
	vector<Job> Jobs;
	vector<bool> machines;
};

#endif /* JOBSHOP_HPP_ */
