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
vector<bool> machines(6);

JobShop::JobShop()
{
	cout << "Input jobs file path." << endl;
	readFile("C:\\Users\\thomas\\Desktop\\test2.txt");
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
	cout << "jobsize :" << Jobs.size() << endl;
	calculate();

	//readFile(readFromConsole());
	return fileName;
}

void JobShop::calculate()
{
	cout << "start berekening" << endl;
	unsigned long minuten = 0;

	while (checkForJobs())
	{
		for (auto i = 0; i < 6; ++i)
		{//loop door machines
			if (machines[i] == 1)
			{ //is machine bezig?
				for (auto & job : Jobs)
				{ // ga alle jobs langs
					if (job[0].getEndTime() == minuten && job[0].getEndTime() != 0)
					{ //controlleer eind tijd of task gestopt moet worden
						cout << "task verwijd op:" << minuten << "     " << i << "   ";
						machines[job[0].getMachine()] = false; //zet machine beschikbaar
						job.reCalculate();   //verwijder task uit job
						break;
					}
				}
			}
		}
		sortJobs();
		assignTasks(minuten);
		for (unsigned long i = 0; i < 6; ++i){
			cout << machines[i];
		}
		cout << endl;
			++minuten;
			if(minuten > 100){
				break;
			}
		}
	}

	bool JobShop::checkForJobs()
	{
		for (auto & job : Jobs)
		{
			if(!job.isEmpty())
			{
				return true;
			}
		}
		return false;
	}

	void JobShop::sortJobs(){
		sort(Jobs.begin(), Jobs.end(), [](const Job & a, const Job & b) -> bool
		{
			return a.getTotalTime() < b.getTotalTime();
		});
	}

	void JobShop::assignTasks(unsigned long minuten){
		sortJobs();
		for (unsigned long i = 0; i < 6; ++i)
			{
				if (machines[i] == false)
				{
					for (auto & job : Jobs)
					{
						if (job.getMachine() == i && job[0].getEndTime() == 0)
						{
							cout << "task gestart op:" << minuten << "     ";
							job[0].startTask(minuten);
							machines[i] = true;
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
