#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Customer.h"
#include "Global_Line.h"
#include "entranceline.h"
#include "mainline.h"

class Simulator {

private:

	int total_time; 
	int clock; 
	Entrance_Line* entrance_line;
	Global_Line* global_line;
	Main_Line* main_line; 

public:
	Simulator()
	{
		global_line = new Global_Line(); 
		main_line = new Main_Line(); 
		entrance_line = new Entrance_Line(main_line, global_line);
	}
	void show_menu()
	{
		//prompts user to enter in data for simulation
		std::cout << "Welcome to the SAGA simulation! " << std::endl;
		std::cout << "Please enter in the desired average customer rate: " << std::endl;
		int rate;
		std::cin >> rate;

		std::cout << "Please enter in the average serving rate: " << std::endl;
		int service_rate;
		std::cin >> service_rate;

		std::cout << "How long would you like this simulation to last? " << std::endl;
		int time;
		std::cin >> time;

		std::cout << "There are 3 simulation cases. Please pick a number: " << std::endl;
		std::cout << "0: 50% global and 50% main" << std::endl;
		std::cout << "1: 25% global and 75% main" << std::endl;
		std::cout << "2: 75% global and 25% main" << std::endl;
		int odds = 0;
		std::cin >> odds;

		entrance_line->set_customer_rate(rate);
		entrance_line->set_odds(odds);

		global_line->set_serving_time(service_rate);
		main_line->set_serving_time(service_rate);

		total_time = time;
	}
	void run_simulation()
	{
		for (clock = 0; clock < total_time; ++clock)
		{
			entrance_line->update(clock);
			global_line->update(clock); 
			main_line->update(clock); 
		}
	}
	void show_statistics()
	{
		//fixme
		std::cout << "At least this is done!\n";
	}

};

#endif // !SIMULATOR_H
