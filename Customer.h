#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Random.h"

struct Customer
{
	int arrival_time;
	int start_service_time;
	int entrance_time; //time the person gets in a food line
	int end_service_time;

	Customer()
	{
		//generates an ID number
		entrance_time = -1;
		start_service_time = -1;
		end_service_time = -1;
	}

	//set the entrance_time
	void set_entrance_time(int time)
	{
		entrance_time = time;
	}

	//calculates how long customer had to wait in line (the entrance line)
	int entrance_wait_time(int clock)
	{
		return clock - entrance_time;
	}

	//sets the start_service_time
	void set_start_service_time(int time)
	{
		start_service_time = time;
	}

	//calculates how long it took for the customer to wait in a food line
	int food_wait_time(int clock)
	{
		return clock - start_service_time;
	}

	//calculates how long it took for the customer to get food
	int total_service_time(int time)
	{
		return time - start_service_time;
	}
};

#endif 