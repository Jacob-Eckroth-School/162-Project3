#include "./Sea_Lion.h"
#include "./Animal.h"
#include <iostream>
using namespace std;

/*******************
 * Function: Sea_Lion::Sea_Lion()
 * Purpose: Sea Lion default constructor that makes an animal that is 48 months old. 
 * ****************/
Sea_Lion::Sea_Lion() :Animal(48,cost,false,true) {

}
/*******************
 * Function: Sea_Lion::Sea_Lion(int)
 * Purpose: Sea Lion constructor that makes an animal that is age months old. 
 * ****************/
Sea_Lion::Sea_Lion(int age):Animal(age,cost,true,false){

		
}
/*******************
 * Function: Sea_Lion::get_food_cost()
 * Purpose: Returns the foodcost of a sea lion, which is just the default food cost.
 * ****************/
int Sea_Lion::get_food_cost(){
	return get_foodcost();
}
/*******************
 * Function: Sea_Lion::get_amount_of_babies()
 * Purpose: returns the amount of babies a sea lion can have.
 * ****************/
int Sea_Lion::get_amount_of_babies(){
	return amountofbabies;
}


