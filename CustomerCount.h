#ifndef CUSTOMER_COUNT_H
#define CUSTOMER_COUNT_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Customer.h"
using std::string;
using std::cout;
using std::endl;
using std::map;

class Customer_count
{
private:
	int student_count;
	int professor_count;
	int visitor_count;
	map<string, string> Customers;
	Random *ID_generator;

public:
	Customer_count()
	{}

	//counts the number of students and professors and visitors based on a set probability
	//stores the customer into a map

	void make_statistics(int num_served)
	{
		for (int i = 0; i < num_served; i++)
		{
			std::vector <int> ID;  
			for (int i = 0; i < 7; i++)
			{
				ID[i] = ID_generator->next_int(9);
			}
			string str(ID.begin(), ID.end());
		
			int random = ID_generator->next_int(10);
			string type;
			if (random >= 0 && random <= 5)
			{
				type = "student";
				student_count++;
			}
			else if (random > 5 && random <= 8)
			{
				type = "professor";
				professor_count++;
			}
			else
			{
				type = "visitor";
				visitor_count++;
			}
			Customers.insert(str, type);
		}
	}

	//displays the number of professors and students and visitors
	void show_statistics()
	{
		cout << "The number of students served: " << student_count << endl;
		cout << "The number of professors served: " << professor_count << endl;
		cout << "The number of visitors served: " << visitor_count << endl;
	}
};
#endif