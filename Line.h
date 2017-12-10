#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <string>
#include <queue>
#include "Customer.h"
using std::string;
using std::queue;

class Line
{
public:
	string name;
	queue <Customer> line;

	virtual void update(int clock) = 0;
};

#endif