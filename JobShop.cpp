/*
 * JobShop.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */

#include "JobShop.hpp"
#include "Job.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <regex>

JobShop::JobShop() :
		job_count(0), machine_count(0), Jobs(std::vector<Job>())
{
	readFile(readFromConsole());
}

JobShop::JobShop(const std::string& filepath) :
		job_count(0), machine_count(0), Jobs(std::vector<Job>())
{
	readFile(filepath);
}

JobShop::JobShop(const JobShop& aJobShop) :
		job_count(aJobShop.job_count), machine_count(aJobShop.machine_count)
{
}

JobShop::~JobShop()
{
}

std::string JobShop::readFromConsole() const
{
	std::string input_string;
	std::cin >> input_string;
	return input_string;
}

std::string JobShop::readFile(const std::string& fileName)
{
	std::string line;
	std::string output;
	std::ifstream myfile(fileName);

	if (myfile.is_open())
	{
		std::smatch match;
		std::regex reg("([0-9]*[0-9])");

		getline(myfile, line);

		regex_search(line, match, reg);
		job_count = findNextMatch(match);

		line = match.suffix().str();
		regex_search(line, match, reg);
		machine_count = findNextMatch(match);

		unsigned char i = 0;
		while (getline(myfile, line))
		{
			std::vector<std::pair<long, long>> tasks;

			while (regex_search(line, match, reg))
			{
				long int a = findNextMatch(match);
				line = match.suffix().str();

				regex_search(line, match, reg);
				long int b = findNextMatch(match);
				line = match.suffix().str();

				tasks.push_back(std::make_pair(a, b));
			}
			Job j(tasks, i);
			Jobs.push_back(j);
			++i;
		}
		myfile.close();
	}
	else
	{
		std::cout << "No file found, check your path and type it below again..." << std::endl;
		readFile(readFromConsole());
		exit(0);
	}

	for (unsigned char i = 0; i < machine_count; ++i)
	{
		machines.push_back(false);
	}
	calculate();

	return fileName;
}

unsigned long JobShop::findNextMatch(std::smatch match){
	std::string match1(match[1]);
	return std::atoi(match1.c_str());
}


void JobShop::calculate()
{
	unsigned long minuten = 0;

	while (checkForJobs())
	{
		//loop through machines
		for (unsigned long i = 0; i < machine_count; ++i)
		{
			//Check for the machines, if they are busy or not
			if (machines[i])
			{
				for (auto & job : Jobs)
				{
					//Check endTime to decide if task needs to be quite
					if (job.size() != 0 && job[0].getEndTime() == minuten)
					{
						//If Task had to be quite, remove task from machine.
						machines[job[0].getMachine()] = false;
						//Delete task from job
						job.reCalculate();
					}
				}
			}
		}

		assignTasks(minuten);

		++minuten;
		if(minuten > 50000){
			break;
		}
	}
	generateOutput();
}

bool JobShop::checkForJobs()
{
	unsigned long size = 0;
	for (Job& job : Jobs)
	{
		size += job.size();
	}
	return size != 0;
}

void JobShop::sortJobs()
{
	std::sort(Jobs.begin(), Jobs.end(), [](const Job& a, const Job& b) -> bool
	{
		return a.getTotalTime() > b.getTotalTime();
	});
}

void JobShop::generateOutput()
{
	std::sort(Jobs.begin(), Jobs.end(), [](const Job & a, const Job & b) -> bool
	{
		return a.getJobId() < b.getJobId();
	});
	for (Job& job : Jobs)
	{
		std::cout << job.getJobId() << "  " << job.getExecutionStartTime() << "  " << job.getExecutionEndTime() << std::endl;
	}
	exit(0);
}

void JobShop::assignTasks(unsigned long minuten)
{
	sortJobs();
	// loop through machines
	for (unsigned char i = 0; i < machine_count; ++i)
	{
		if (!machines[i])
		{
			for (auto & job : Jobs)
			{
				// loop through jobs
				if (job.size() > 0 && job.getMachine() == i)
				{
					machines[job[0].getMachine()] = true;
					job.startTask(minuten);
					assignTasks(minuten);
					break;
				}
			}
		}
	}
}
