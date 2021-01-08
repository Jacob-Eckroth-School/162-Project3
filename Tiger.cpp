#include "./Tiger.h"
#include "./Animal.h"
#include <iostream>
using namespace std;

/******************
 * Function: Tiger::Tiger()
 * Purpose: Default Tiger constructor that creates a tiger from the animal class that is 48 months old.
 * ***************/
Tiger::Tiger() :Animal(48,12000,false,true) {

}
/******************
 * Function: Tiger::Tiger(int)
 * Purpose: Alternate tiger constructor that creates a tiger from the animal class that is 0 months old.
 * ***************/
Tiger::Tiger(int age):Animal(age,12000,true,false){
		
}
/******************
 * Function: Tiger::get_food_cost()
 * Purpose: Returns the foodcost for a tiger, which is 5x the base cost of food.
 * ***************/
int Tiger::get_food_cost(){
	return 5 * get_foodcost(); 
}
/******************
 * Function: Tiger::get_amount_of_babies()
 * Purpose: returns the amount of babies that a tiger can have.
 * ***************/
int Tiger::get_amount_of_babies(){
	return amountOfBabies;
}

