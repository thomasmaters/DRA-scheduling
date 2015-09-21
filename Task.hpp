/*
 * Task.hpp
 *
 *  Created on: 17 sep. 2015
 *      Author: Maurice
 */

#ifndef TASK_HPP_
#define TASK_HPP_

class Task
{
public:
	Task();
	Task(unsigned long machine, unsigned long tijdsduur, unsigned long jobID);
	Task(const Task& aTask);
	virtual ~Task();
	Task& operator=(const Task& aTask);
	unsigned long getTijdsduur() const;

private:
	unsigned long machine;
	unsigned long tijdsduur;
	unsigned long jobID;
};

#endif /* TASK_HPP_ */
