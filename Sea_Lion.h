#ifndef SEALION_H 
#define SEALION_H
#include "./Animal.h"

class Sea_Lion: public Animal{
	
	public:
		Sea_Lion();
		Sea_Lion(int);

		int get_amount_of_babies();
		int get_food_cost();
	private:
		const static int cost = 700;
		const static int amountofbabies=1;
		

};

#endif
