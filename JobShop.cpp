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
using namespace std;

vector<Job> Jobs;

JobShop::JobShop()
{
	cout << "Input jobs file path." << endl;
	readFile(readFromConsole());
}

JobShop::JobShop(const JobShop &JS)
{
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
		getline(myfile, line);

		while (getline(myfile, line))
		{
			vector<pair<long, long>> v;
			regex reg("([0-9]*[0-9])");

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
			Job j(v);
			Jobs.push_back(j);
			cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		cout << "No file found, check your path and try again.." << endl;
		readFile(readFromConsole());
	}
	cout << Jobs.size() << endl;
	calculate();

	//readFile(readFromConsole());
	return fileName;
}

void JobShop::calculate()
{
	cout << "start berekening" << endl;
	unsigned long minuten = 0;
	vector<bool> machines(6);

	while (checkForJobs())
	{
		cout<< "found job" << endl;
		for (auto i = 0; i < 6; ++i)
		{
			if (machines[i])
			{ //machine is bezig
				for (auto & job : Jobs)
				{
					if (job[0].getEndTime() == minuten && minuten != 0)
					{
						cout << "recalculating" << endl;
						job.reCalculate();
						machines[i] = false;
					}
				}
			}
		}
		//cout << "start sorteren jobs lijst" << endl;
		sort(Jobs.begin(), Jobs.end(), [](const Job & a, const Job & b) -> bool
		{
			return a.getTotalTime() > b.getTotalTime();
		});
		//cout << "einde sorteren jobs lijst" << endl;

		for (unsigned long i = 0; i < 6; ++i)
		{
			//cout << "machine loop" << endl;
			if (!machines[i])
			{
				//cout << "machine check" << endl;
				for (auto & job : Jobs)
				{
					//cout << "Jobs loop" << endl;
					//cout << "i = " << i << endl;
					cout << job.getMachine() << endl;

					if (job.getMachine() == i)
					{
						cout << "Jobs machine check" << endl;
						cout<< "total  time:" <<job.getTotalTime() << endl;
						job[0].startTask(minuten);
						machines[i] = true;
						break;
					}
				}
			}
		}
			++minuten;
		}
	}

	bool JobShop::checkForJobs()
	{
		for (auto & job : Jobs)
		{
			cout << job.isEmpty() ;
			if(job.isEmpty() == false)
			{
				return true;
			}
		}
		return false;
	}

	JobShop::~JobShop()
	{
		// TODO Auto-generated destructor stub
	}
