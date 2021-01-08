#include "./Animal.h"
#include <iostream>
using namespace std;
#include <cstdlib>

/**********************
 * Function: Animal::Animal()
 * Purpose: Default animal constructor that sets the defaults of the animal class
 * *******************/
Animal::Animal(){
	age = 0;
	revenue = 0;
	costIfSick = 0;
	isBaby = true;
	isAdult = false;
	foodcost = 80;


}
/**********************
 * Function: Animal::Animal(int,int,bool,bool)
 * Purpose: Animal constructor that takes in an age, cost, baby status, and adult status.
 * *******************/
Animal::Animal(int inputAge,int inputCost, bool inputIsBaby, bool inputIsAdult){
	age = inputAge;	
	revenue = inputCost/10;
	revenueifbaby = inputCost/5;
	costIfSick = inputCost/2;
	costIfSickBaby = inputCost;
	isBaby = inputIsBaby;
	isAdult = inputIsAdult;
	foodcost = 80;
}

/**********************
 * Function: Animal::get_costifsickbaby()
 * Purpose: getter function that returns the cost of the animal if they're sick and a baby.
 * *******************/
int Animal::get_costifsickbaby(){
	return costIfSickBaby;
}
/**********************
 * Function: Animal::get_revenueifbaby()
 * Purpose: getter function that returns the revenue of the animal if they're a baby.
 * *******************/
int Animal::get_revenueifbaby(){
	return revenueifbaby;
}
/**********************
 * Function: Animal::get_foodcost()
 * Purpose: getter function that returns the cost of the food for the animal.
 * *******************/
int Animal::get_foodcost(){
	return foodcost;
}
/**********************
 * Function: Animal::get_age()
 * Purpose: getter function that returns the age of an animal.
 * *******************/
int Animal::get_age(){
	return age;
}
/**********************
 * Function: Animal::get_revenue()
 * Purpose: getter function that returns the revenue that the animal generates.
 * *******************/
int Animal::get_revenue(){
	return revenue;
}
/**********************
 * Function: Animal::get_costifsick()
 * Purpose: getter function that returns the cost of an animal if they're sick.
 * *******************/
int Animal::get_costifsick(){
	return costIfSick;
}
/**********************
 * Function: Animal::get_isbaby()
 * Purpose: getter function that returns whether an animal is a baby or not
 * *******************/
bool Animal::get_isbaby(){
	return isBaby;
}
/**********************
 * Function: Animal::get_isadult()
 * Purpose: getter function that returns whether an animal is an adult or not
 * *******************/
bool Animal::get_isadult(){
	return isAdult;
}

/**********************
 * Function: Animal::set_foodcost()
 * Purpose: setter funtion that updates the cost of the food for an animal.
 * *******************/
void Animal::set_foodcost(int newcost){
	foodcost = newcost;
}
/**********************
 * Function: Animal::set_age()
 * Purpose: setter funtion that updates the age for an animal.
 * *******************/
void Animal::set_age(int newage){
	age = newage;
}
/**********************
 * Function: Animal::set_revenue()
 * Purpose: setter funtion that updates the revenue for an animal.
 * *******************/
void Animal::set_revenue(int newrev){
	revenue = newrev;
}
/**********************
 * Function: Animal::set_costifsick()
 * Purpose: setter funtion that updates the cost of an animal if sick. 
 * *******************/
void Animal::set_costifsick(int newcost){
	costIfSick = newcost;
}
/**********************
 * Function: Animal::set_isbaby()
 * Purpose: setter funtion that updates the status of whether an animal is a baby. 
 * *******************/
void Animal::set_isbaby(bool newstatus){
	isBaby = newstatus;
}
/**********************
 * Function: Animal::set_isadult()
 * Purpose: setter funtion that updates the status of whether an animal is an adult.
 * *******************/
void Animal::set_isadult(bool newstatus){
	isAdult = newstatus;
}
/**********************
 * Function: Animal::update_animal_age()
 * Purpose: Updates the age of an animal, and changes whether it is a baby/adult or not.
 * *******************/
void Animal::update_animal_age(){
	age++;
	if(age < 6){
		isBaby = true;
		isAdult = false;
	}else if(age >= 48){
		isAdult = true;
		isBaby = false;
	}else{
		isBaby = false;
		isAdult = false;
	}
}
/**********************
 * Function: Animal::update_foodcost()
 * Purpose: Updates the food cost of an animal to a random number between 80%-120% of the last food cost.
 * *******************/
void Animal::update_foodcost(){
	float randnumber = ((rand() % 41)+80.0)/100.0;
	foodcost = foodcost * randnumber;
}

