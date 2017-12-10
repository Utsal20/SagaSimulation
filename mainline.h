#ifndef MAINLINE_H
#define MAINLINE_H

#include <iostream>
#include <string>
#include <queue>

#include "Random.h"
#include "Customer.h"
#include "Line.h"


using std::string;

class Main_Line :public Line {
private:
	int wait_time;
	int num_served;
	int serving_time;
	double arrival_rate;
	string name;
	std::queue <Customer*> line;

public:
	Main_Line():wait_time(0), num_served(0), name("Main"){}

	/*
	void check_new_arrival(int clock)
	{
		if (next_int(60) < arrival_rate)
		{
			line.push(new Customer(clock));
		}
	}
	*/

	void set_serving_time(int serv_time) {
		serving_time = serv_time;
	}

	void add_customer(Customer* &cust) {
		line.push(cust);
	}

	int get_wait_time() {
		return wait_time;
	}

	int get_num_served() {
		return num_served;
	}
	
	double get_arrival_rate() {
		return arrival_rate;
	}

	void update(int clock)
	{
		if (!line.empty()) {
			Customer *cust = line.front();
			if (cust->food_wait_time(clock) > serving_time) {
				wait_time += cust->food_wait_time(clock);
				num_served++;
				line.pop();
				delete cust;
			}
		}
	}

	friend Entrance_Line; // should be fixed by entrance_line

};

#endif