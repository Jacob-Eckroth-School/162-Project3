/**********************
 * Program: Prog.cpp
 * Author: Jacob Eckroth
 * Date: 2/16/19
 * Description: Plays a game called zoo tycoon where the user buys animals and has to pay to keep those animals alive which in turn generate them money
 * Inputs: User input in regards to what type of animal they want to buy and how many of each they want
 * Outputs: Prints the game, and the amount of animals, money, etc...
 * *******************/
#include "./Animal.h"
#include "./Sea_Lion.h"
#include "./Black_Bear.h"
#include "./Zoo.h"
#include "./Tiger.h"
#include <iostream>
#include <cstdlib>
using namespace std;
//main function. Plays the game, and seeds the random function.
int main(){
	srand(time(NULL));

	Zoo zoo;
	zoo.play();


	return 0;
}

