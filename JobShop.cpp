/*
 * JobShop.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */

#include "JobShop.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <regex>
using namespace std;

JobShop::JobShop()
{
	vector<pair<long,long> > Jobs;
	cout << "Input jobs file path." << endl;
	cout << readFile(readFromConsole());
}

string JobShop::readFromConsole() const
{
	string input_string;
	cin>>input_string;
	return input_string;
}

string JobShop::readFile(const string fileName) const
{
	string line;
	ifstream myfile (fileName);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << line << '\n';
		}
		myfile.close();
	}else{
		cout << "No file found, check your path and try again.." << endl;
	}
	return fileName;
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}
