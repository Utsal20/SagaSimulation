#ifndef ENTRANCELINE_H
#define ENTRANCELINE_H

#include <iostream>
#include <queue>

#include "Customer.h"

using std::string;

class Entrance_Line {
private:
	string name;
	std::queue <Customer> line;

public:
	Entrance_Line() {
		name = "Entrance";
	}
};

#endif // !ENTRANCELINE_H
