#include "./Black_Bear.h"
#include "./Animal.h"
#include <iostream>
using namespace std;

/**********************
 * Function: Black_Bear::Black_Bear()
 * Purpose: Black_Bear constructor that calls the animal constructor for a 4 year old adult.
 * *******************/
Black_Bear::Black_Bear() :Animal(48,cost,false,true) {

}
/**********************
 * Function: Black_Bear::Black_Bear()
 * Purpose: Black_Bear constructor that takes in the age of an animal and sets the black bear to be an animal that is that old.
 * *******************/
Black_Bear::Black_Bear(int age):Animal(age,cost,true,false){

		
}
/**********************
 * Function: Black_Bear::get_food_cost()
 * Purpose: Returns 3* the foodcost of the foodcost because the bear food costs 3x as much as the base food cost.
 * *******************/
int Black_Bear::get_food_cost(){
	return 3 * get_foodcost();
}
/**********************
 * Function: Black_Bear::get_amount_of_babies()
 * Purpose: returns the amount of babies a blackbear can have.
 * *******************/
int Black_Bear::get_amount_of_babies(){
	return amountofbabies;
}



