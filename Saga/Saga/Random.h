#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>

/*
Generate random integers needed for some portions of the simulation
*/
class Random {
public:
	//Initializes random number generator using time as seed
	Random() {
		srand((unsigned int)std::time(0));
	}

	//Return random integer between 0 and n
	int next_int(int n) {
		return int(rand()) % n;
	}
};

#endif // !RANDOM_H

