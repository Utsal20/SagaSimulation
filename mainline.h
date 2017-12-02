#ifndef MAINLINE_H
#define MAINLINE_H

#include <iostream>
#include <string>
#include <queue>

#include "Customer.h"

using std::string;

class Main_Line {
private:
	int wait_time;
	int num_served;
	double arrival_rate;
	string name;
	std::queue <Customer> line;

public:
	Main_Line(double arrival_rate) {
		name = "Main";
		this->arrival_rate = arrival_rate;
	}

	int get_wait_time() {
		return wait_time;
	}

	int get_num_served() {
		return num_served;
	}

	void update(int clock) {
		//fixme
	}

	friend Entrance_Line; // should be fixed by entrance_line

};

#endif