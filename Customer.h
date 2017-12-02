#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
	int arrival_time;
	int entrance_time;
	int service_time;
public:
	Customer(int clock);
	friend class Simulator;
};

#endif // !CUSTOMER_H
