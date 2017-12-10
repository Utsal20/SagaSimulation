#ifndef GLOBAL_LINE_H_
#define GLOBAL_LINE_H_

#include <queue>
#include <string>

#include "Random.h"
#include "Line.h"
#include "Customer.h"


class Global_Line : public Line
{
private: 
     int wait_time;
	 int serving_time;
     int num_served; 
     double arrival_rate;
     string name;
     std::queue<Customer*>line;

public: 
     Global_Line(): wait_time(0) , num_served(0), name("Global") {}

	 void add_customer(Customer* &cust) {
		 line.push(cust);
	 }

	 void set_serving_time(int serv_time) {
		 serving_time = serv_time;
	 }

     int get_wait_time()
     {
		 /*Customer *customer = line.front();
		 wait_time = serving_time - customer->entrance_time;
         return wait_time;
		 */
		 return wait_time;
     }

     int get_num_served()
     {
          return num_served;
     }

     double get_arrival_rate()
     {
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
     friend class Entrance_Line; 



};


#endif