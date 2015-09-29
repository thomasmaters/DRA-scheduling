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
		job_count(0), machine_count(0), Jobs(vector<Job>())
{
	std::cout << "Input jobs file path." << endl;
	readFile(readFromConsole());
}

JobShop::JobShop(const string& filepath) :
		job_count(0), machine_count(0), Jobs(vector<Job>())
{
	readFile(filepath);
}

JobShop::JobShop(const JobShop &JS) :
		job_count(JS.job_count), machine_count(JS.machine_count)
{
}

string JobShop::readFromConsole() const
{
	string input_string;
	cin >> input_string;
	return input_string;
}

string JobShop::readFile(const string fileName)
{
	string line;
	string output;
	ifstream myfile(fileName);

	if (myfile.is_open())
	{
		std::smatch match;
		std::regex reg("([0-9]*[0-9])");

		getline(myfile, line);

		regex_search(line, match, reg);
		job_count = findNextMatch(match);

		regex_search(line, match, reg);
		machine_count = findNextMatch(match);

		unsigned long i = 0;
		while (getline(myfile, line))
		{
			vector<pair<long, long>> v;

			while (regex_search(line, match, reg))
			{
				long int a = findNextMatch(match);
				line = match.suffix().str();

				regex_search(line, match, reg);
				long int b = findNextMatch(match);
				line = match.suffix().str();

				v.push_back(make_pair(a, b));
			}
			Job j(v, i);
			Jobs.push_back(j);
			++i;
		}
		myfile.close();
	}
	else
	{
		std::cout << "No file found, check your path and try again.." << endl;
		readFile(readFromConsole());
		exit(0);
	}

	for (unsigned long i = 0; i < machine_count; ++i)
	{
		machines.push_back(false);
	}
	calculate();

	return fileName;
}

unsigned long JobShop::findNextMatch(smatch match){
	std::string match1(match[1]);
	return std::atoi(match1.c_str());
}


void JobShop::calculate()
{
	unsigned long minuten = 0;

	while (checkForJobs())
	{
		for (unsigned long i = 0; i < machine_count; ++i)
		{ //loop door machines
			if (machines[i])
			{ //is machine bezig?
				for (auto & job : Jobs)
				{ // ga alle jobs langs
					if (job.size() != 0 && job[0].getEndTime() == minuten)
					{ //controlleer eind tijd of task gestopt moet worden
						machines[job[0].getMachine()] = false; //zet machine beschikbaar
						job.reCalculate();   //verwijder task uit job
					}
				}
			}
		}

		assignTasks(minuten);

		++minuten;
		if (minuten > 100)
		{
			break;
		}
	}
	generateOutput();
}

bool JobShop::checkForJobs()
{
	unsigned long size = 0;
	for (auto & job : Jobs)
	{
		size += job.size();
	}
	return size != 0;
}

void JobShop::sortJobs()
{
	sort(Jobs.begin(), Jobs.end(), [](const Job & a, const Job & b) -> bool
	{
		return a.getTotalTime() > b.getTotalTime();
	});
}

void JobShop::generateOutput()
{
	sort(Jobs.begin(), Jobs.end(), [](const Job & a, const Job & b) -> bool
	{
		return a.getJobId() < b.getJobId();
	});
	for (auto & job : Jobs)
	{
		cout << job.getJobId() << "  " << job.getExecutionStartTime() << "  "
				<< job.getExecutionEndTime() << endl;
	}
	system("pause");
	exit(0);
}

void JobShop::assignTasks(unsigned long minuten)
{
	sortJobs();
	for (unsigned long i = 0; i < machine_count; ++i)
	{   // loop throug machines
		if (!machines[i])
		{   // machine not occupied
			for (auto & job : Jobs)
			{   // loop through jobs
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

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}
