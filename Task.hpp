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
	void startTask(unsigned long startTijd);
	unsigned long getTijdsduur() const;
	unsigned long getEndTime() const;
	unsigned long getStartTime() const;
	unsigned long getMachine() const;

private:
	unsigned long machine;
	unsigned long tijdsduur;
	unsigned long jobID;
	unsigned long startTime;
	unsigned long endTime;
};

#endif /* TASK_HPP_ */
