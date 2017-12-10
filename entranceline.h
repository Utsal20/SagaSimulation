#ifndef ENTRANCELINE_H
#define ENTRANCELINE_H

#include <iostream>
#include <queue>

#include "Customer.h"
#include "Line.h"
#include "mainline.h"
#include "Global_Line.h"

using std::string;

class Entrance_Line :public Line {
private:
	string name;
	std::queue <Customer*> line;
	double customer_rate;
	int odds = 4;
	int service_time = 4; //4 seconds to scan the card and go in
	Random rando;
	Main_Line* main_line;
	Global_Line* global_line;

public:
	Entrance_Line(Main_Line* main_line, Global_Line* global_line) {
		name = "Entrance";
		this->main_line = main_line;
		this->global_line = global_line;
	}

	void set_customer_rate(int cust_rate) {
		customer_rate = cust_rate;
	}

	void set_odds(int odds) {
		if (odds == 1)
			this->odds = 6;
		else if (odds == 2)
			this->odds = 2;
	}

	void update(int clock) {
		//adding a new customer in entrance line
		if ((rando.next_int(1000000) / 1000000.0) < customer_rate) {
			Customer* cust = new Customer;
			cust->set_entrance_time(clock);
			line.push(cust);
		}
		if (!line.empty()) {
			Customer* cust = line.front();
			//if the customer scans the card, send them to either global or main
			if (cust->entrance_wait_time(clock) > service_time) {
				cust->set_start_service_time(clock);
				if (rando.next_int(10) < odds)
					main_line->add_customer(cust);
				else
					global_line->add_customer(cust);
				//removing customer from entrance line once they move to either main or global
				line.pop();
			}
		}
	}
};

#endif // !ENTRANCELINE_H
