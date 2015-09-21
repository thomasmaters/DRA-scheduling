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

vector< Job > Jobs;

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
	cin>>input_string;
	return input_string;
}
//C:\Users\thomas\Desktop\test.txt
string JobShop::readFile(const string fileName)
{
	string line;
	string output;
	ifstream myfile (fileName);

	if (myfile.is_open())
	{
		getline (myfile,line);

		while ( getline (myfile,line) )
		{
			vector<pair<long,long>> v;
			regex reg("([0-9]*[0-9])");

		    std::smatch match;
		    while (regex_search (line,match,reg)) {
		    	string match1(match[1]);
		    	long int a = atoi(match1.c_str());
		    	line = match.suffix().str();

		    	regex_search (line,match,reg);
		    	string match2(match[1]);
		    	long int b = atoi(match2.c_str());
		    	line = match.suffix().str();

		    	v.push_back(make_pair(a,b));
		    }
		    Job j(v);
		    Jobs.push_back(j);
			cout << line << '\n';
		}
		myfile.close();
	}else{
		cout << "No file found, check your path and try again.." << endl;
		readFile(readFromConsole());
	}
	cout << "File has been read successfully!" << endl;
	readFile(readFromConsole());
	return fileName;
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}
