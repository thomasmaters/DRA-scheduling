/*
 * main.cpp
 *
 *  Created on: 17 sep. 2015
 *      Author: thomas
 */
#include<iostream>

#include "JobShop.hpp"
#include "Task.hpp"
#include "Job.hpp"

int main(int argc, char **argv)
{
	if (argv[1])
	{
		JobShop j(argv[1]);
	}
	else
	{
		JobShop j;
	}
	return 0;
}

