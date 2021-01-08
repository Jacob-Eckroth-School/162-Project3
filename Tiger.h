#ifndef TIGER_H
#define TIGER_H
#include "./Animal.h"
#include <iostream>
using namespace std;

class Tiger: public Animal{
	public:
		Tiger();
		Tiger(int);
		int get_food_cost();
		int get_amount_of_babies();
	private:

		const static int cost = 12000;
		const static int amountOfBabies = 3;
};

#endif
