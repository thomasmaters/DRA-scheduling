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
using namespace std;

class JobShop
{
public:
	JobShop();
	JobShop(const JobShop &JS);

	string readFromConsole() const;
	string readFile(const string fileName) const;

	virtual ~JobShop();
private:
	static long int job_count;
	static long int machine_count;
	vector<vector<pair<long,long>>> Jobs;
};

#endif /* JOBSHOP_HPP_ */
