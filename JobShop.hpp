/*
 * JobShop.hpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */

#ifndef JOBSHOP_HPP_
#define JOBSHOP_HPP_
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <regex>
#include "Job.hpp"

class JobShop
{
public:
	JobShop();
	JobShop(const std::string& filepath);
	JobShop(const JobShop& aJobShop);
	virtual ~JobShop();

	std::string readFromConsole() const;
	std::string readFile(const std::string& fileName);

private:
	void generateOutput();
	void calculate();
	void sortJobs();
	void assignTasks(unsigned long minuten);

	bool checkForJobs();
	unsigned long findNextMatch(std::smatch match);

	unsigned long job_count;
	unsigned long machine_count;
	std::vector<Job> Jobs;
	std::vector<bool> machines;
};

#endif /* JOBSHOP_HPP_ */
