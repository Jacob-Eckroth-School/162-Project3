#ifndef BLACKBEAR_H
#define BLACKBEAR_H
#include "./Animal.h"

class Black_Bear: public Animal{
	
	public:
		Black_Bear();
		Black_Bear(int);

	
		int get_food_cost();
		int get_amount_of_babies();
	private:
		const static int cost = 5000;
		const static int amountofbabies=2;
		

};

#endif
