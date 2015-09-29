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

vector<Job> Jobs;

JobShop::JobShop()
{
	job_count = 0;
	machine_count = 0;
	std::cout << "Input jobs file path." << endl;
	readFile("C:\\Users\\thomas\\Desktop\\test2.txt");
}

JobShop::JobShop(const JobShop &JS)
{
	job_count = JS.job_count;
	machine_count = JS.machine_count;
}

string JobShop::readFromConsole() const
{
	string input_string;
	cin >> input_string;
	return input_string;
}
//C:\Users\thomas\Desktop\test2.txt
string JobShop::readFile(const string fileName)
{
	string line;
	string output;
	ifstream myfile(fileName);

	if (myfile.is_open())
	{
		std::smatch match;
		regex reg("([0-9]*[0-9])");

		getline(myfile, line);

		regex_search(line, match, reg);
		string match1(match[1]);
		job_count = atoi(match1.c_str());

		regex_search(line, match, reg);
		string match2(match[1]);
		machine_count = atoi(match2.c_str());

		unsigned long i = 0;
		while (getline(myfile, line))
		{
			vector<pair<long, long>> v;

			std::smatch match;
			while (regex_search(line, match, reg))
			{
				string match1(match[1]);
				long int a = atoi(match1.c_str());
				line = match.suffix().str();

				regex_search(line, match, reg);
				string match2(match[1]);
				long int b = atoi(match2.c_str());
				line = match.suffix().str();

				v.push_back(make_pair(a, b));
			}
			Job j(v, i);
			Jobs.push_back(j);
			++i;
			//cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		cout << "No file found, check your path and try again.." << endl;
		readFile(readFromConsole());
	}

	for (unsigned long i = 0; i < machine_count; ++i)
	{
		machines.push_back(false);
	}

	//cout << "jobsize :" << Jobs.size() << endl;
	calculate();

	return fileName;
}

void JobShop::calculate()
{
	unsigned long minuten = 0;
	cout << "start berekening" << endl;
	cout << "Aantal Jobs: " << Jobs.size() << endl;
	cout << "Aantal Machines: " << machines.size() << endl;
	while (checkForJobs())
	{
		for (unsigned long i = 0; i < machine_count; ++i)
		{ //loop door machines
			if (machines[i])
			{ //is machine bezig?
				for (auto & job : Jobs)
				{ // ga alle jobs langs
					if (job.size() > 0 && job[0].getEndTime() == minuten)
					{ //controlleer eind tijd of task gestopt moet worden
						machines[job[0].getMachine()] = false; //zet machine beschikbaar
						cout << job[0].getMachine() << " " << machines[job[0].getMachine()] << " beschikbaar" << endl;
						job.reCalculate();   //verwijder task uit job
						break;
					}
				}
			}
		}
		sortJobs();
		assignTasks(minuten);
		++minuten;
		if (minuten > 500)
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
				//cout << job.getMachine() << " " << i << endl;
				if (job.size() > 0 && job.getMachine() == i)
				{
					job.startTask(minuten);
					machines[job[0].getMachine()] = true;
					cout << job[0].getMachine() << " " << machines[job[0].getMachine()] << " onbeschikbaar" << endl;
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
