/*
 * JobShop.hpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */

#ifndef JOBSHOP_HPP_
#define JOBSHOP_HPP_
#include <string>
using namespace std;

class JobShop
{
public:
	JobShop();

	string readFromConsole() const;
	string readFile(const string fileName) const;

	virtual ~JobShop();
};

#endif /* JOBSHOP_HPP_ */
