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

JobShop::JobShop()
{
	vector<vector<pair<long,long>>> Jobs;
	cout << "Input jobs file path." << endl;
	readFile(readFromConsole());
}

JobShop::JobShop(const JobShop &JS)
{
	*this = JS;
}


string JobShop::readFromConsole() const
{
	string input_string;
	cin>>input_string;
	return input_string;
}
//C:\Users\thomas\Desktop\test.txt
string JobShop::readFile(const string fileName) const
{
	string line;
	string output;
	ifstream myfile (fileName);

	if (myfile.is_open())
	{
		getline (myfile,line);


	   // string test = "test replacing \"these characters\"";
	   // regex reg("[^\\w]+");
	    //test = regex_replace(test, reg, "_");
	   // cout << test << endl;
		while ( getline (myfile,line) )
		{
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

		    	vector<pair<long,long>> v;
		    	v.push_back(make_pair(a,b));
		    	Job j(v);
		    	//cout << line << endl;
		    }
			cout << line << '\n';
		}
		myfile.close();
	}else{
		cout << "No file found, check your path and try again.." << endl;
		readFile(readFromConsole());
	}
	return fileName;
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}
