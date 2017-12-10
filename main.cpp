#include <iostream>
#include "Simulator.h"

Simulator saga;

int main()
{
	saga.show_menu();
	saga.run_simulation();
	saga.show_statistics();
	return 0;
}