#include "./Zoo.h"
#include <iostream>
#include <ctime>
using namespace std;

/******************************
 * Function: Zoo::Zoo()
 * Purpose: Default Zoo constructor that sets up the starting variables.
 * ***************************/
Zoo::Zoo(){

	revenue = 100000;
	tigers = NULL;
	black_bears = NULL;
	sea_lions = NULL;
	lion_cost = 700;
	tiger_cost = 12000;
	bear_cost = 5000;
	game_playing = true;
	now = time(0);
	ltm = localtime(&now);
	year = 1900 + ltm->tm_year;
	month = 1 + ltm->tm_mon;
}
/******************************
 * Function: Zoo::~Zoo()
 * Purpose: Default zoo deconstructor that frees memory from the animal arrays.
 * ***************************/
Zoo::~Zoo(){

	if(tigers != NULL){
		delete[] tigers;
	}
	if(black_bears != NULL){
		delete[] black_bears;
	}
	if(sea_lions != NULL){
		delete[] sea_lions;
	}
}
/******************************
 * Function: Zoo::get_revenue()
 * Purpose: Returns the revenue that you have.
 * ***************************/
int Zoo::get_revenue(){
	return revenue;
}
/******************************
 * Function: Zoo::get_amount_of_tigers()
 * Purpose: Default Zoo constructor that sets up the starting variables.
 * ***************************/
int Zoo::get_amount_of_tigers(){
	return tigerAmount.get_total_amount(); 
}
/******************************
 * Function: Zoo::get_amount_of_bears()
 * Purpose: Returns the total amount of bears
 * ***************************/
int Zoo::get_amount_of_bears(){
	return bearAmount.get_total_amount();
}
/******************************
 * Function: Zoo::get_amount_of_sea_lions()
 * Purpose: Returns the amount of sea lions.
 * ***************************/
int Zoo::get_amount_of_sea_lions(){
	return lionAmount.get_total_amount();
}
/******************************
 * Function: Zoo::get_tigers()
 * Purpose: Returns the tiger array
 * ***************************/
Tiger* Zoo::get_tigers(){
	return tigers;
}
/******************************
 * Function: Zoo::get_black_bears()
 * Purpose: returns the black_bear array
 * ***************************/
Black_Bear* Zoo::get_black_bears(){
	return black_bears;
}
/******************************
 * Function: Zoo::get_sea_lions()
 * Purpose: Returns the sea lion array
 * ***************************/
Sea_Lion* Zoo::get_sea_lions(){
	return sea_lions;
}
/******************************
 * Function: Zoo::set_tigers(Tiger*)
 * Purpose: Updates the tiger array
 * ***************************/

void Zoo::set_tigers(Tiger* newtigers){
	if(tigers!= NULL){
		delete[] tigers;
	}
	tigers = newtigers;
}
/******************************
 * Function: Zoo::set_black_bears(Black_Bear*)
 * Purpose: Updates the bear array
 * ***************************/
void Zoo::set_black_bears(Black_Bear* newbears){
	if(black_bears != NULL){
		delete[] black_bears;
	}
	black_bears = newbears;
}
/******************************
 * Function: Zoo::set_sea_lions(Sea_Lion*)
 * Purpose: Updates the sea lions array
 * ***************************/
void Zoo::set_sea_lions(Sea_Lion* newlions){
	if(sea_lions != NULL){

		delete[] sea_lions;
	}
	sea_lions = newlions;
}
/******************************
 * Function: Zoo::get_money(bool)
 * Purpose: Updates the revenue in the zoo based on how many animals the user has, and whether they get an attendance boom or not
 * ***************************/
void Zoo::get_money(bool attendanceBoom){
	for(int i = 0; i < tigerAmount.get_total_amount(); i++){
		revenue += (tigers[i].get_isbaby())? tigers[i].get_revenueifbaby() : tigers[i].get_revenue();
	}
	for(int i = 0; i < bearAmount.get_total_amount(); i++){
		revenue += (black_bears[i].get_isbaby())? black_bears[i].get_revenueifbaby() : black_bears[i].get_revenue();
	}
	for(int i = 0; i < lionAmount.get_total_amount(); i++){
		revenue += 2*((sea_lions[i].get_isbaby())? sea_lions[i].get_revenueifbaby() : sea_lions[i].get_revenue());//*2 because sea lions get 20% in revenue instead of 10%
	}
	if(attendanceBoom){
		for(int i = 0; i < lionAmount.get_total_amount(); i++){
			revenue += (rand() % 250)+150;
		}
	}
}
/******************************
 * Function: Zoo::print_info()
 * Purpose: Prints the amount of animals that the user has as well as their money.
 * ***************************/
void Zoo::print_info(){
	cout<<"\033[1;36mYour Zoo!\033[0m"<<endl;
	cout<<"You have "<<tigerAmount.get_total_amount()<<" Tigers, and "<<tigerAmount.get_baby_amount()<<" of them are babies."<<endl;
	cout<<"You have "<<bearAmount.get_total_amount()<<" Bears, and "<<bearAmount.get_baby_amount()<<" of them are babies."<<endl;
	cout<<"You have "<<lionAmount.get_total_amount()<<" Sea Lions, and "<<lionAmount.get_baby_amount()<<" of them are babies."<<endl;
	cout<<"You have $"<<revenue<<" in the bank."<<endl;
}


/******************************
 * Function: Zoo::print_date()
 * Purpose: Prints whatever date it currently is and updates the date.
 * ***************************/
void Zoo::print_date(){
	string monthstring = "";
	switch(month){
		case 1:
			monthstring = "January";
			break;
		case 2:
			monthstring = "February";
			break;
		case 3:
			monthstring = "March";
			break;
		case 4:
			monthstring = "April";
			break;
		case 5:
			monthstring = "May";
			break;
		case 6:
			monthstring = "June";
			break;
		case 7:
			monthstring = "July";
			break;
		case 8:
			monthstring = "August";
			break;
		case 9:
			monthstring = "September";
			break;
		case 10:
			monthstring = "October";
			break;
		case 11:
			monthstring = "November";
			break;
		case 12:
			monthstring = "December";
			break;
		default:
			cout<<"switch in month messed up"<<endl;
			break;
	}
	cout<<"\033[1;33m"<<monthstring<<", "<<year<<"\033[0m\n";
	month++;
	if(month>12){
		month = 1;
		year++;
	}
}





/******************************
 * Function: Zoo::buy_animals()
 * Purpose: Gets user input on what animals they want to buy or not buy.
 * ***************************/
void Zoo::buy_animals(){
	string teststring = "12345678";
	cout<<"\033[1;34mChoose what you want to do: buy 1 sea lion for $"<<lion_cost<<" (1), buy 2 sea lions for $"<<lion_cost * 2<<"(2), buy 1 tiger for $"<<tiger_cost<<"(3), buy 2 tigers for $"<<tiger_cost*2<<"(4), buy 1 black bear for $"<<bear_cost<<"(5), buy 2 black bears for $"<<bear_cost*2<<"(6), not buy any animals(7), or quit the game(8):\033[0m";
	bool validinput = true;
	string userinput = "";
	do{
		getline(cin,userinput);
		if(userinput.length()>1){
			validinput = false;
		}else{
			for(int i =0; i < teststring.length(); i++){
				if(userinput[0] == teststring[i]){
					validinput = true;
					break;
				}
				validinput = false;
			}
		}
		if(!validinput){
			cout<<"\033[1;31mPlease enter a single digit between 1 and 8:\033[0m";
		}
	}while(!validinput);
	dealwithinput(stoi(userinput));
}
/******************************
 * Function: Zoo::dealwithinput(int)
 * Purpose: Deals with the user input for what they choose for their animals.
 * ***************************/
void Zoo::dealwithinput(int userinput){
	switch(userinput){
		case 1://buy 1 sea lion
			buy_lions(1); 
			break;

		case 2://buy 2 sea lions
			buy_lions(2); 
			break;

		case 3://buy 1 tiger
			buy_tigers(1);
			break;

		case 4://buy 2 tigers
			buy_tigers(2);
			break;

		case 5://buy 1 black bear
			buy_bears(1); 
			break;
		case 6://buy 2 black bears
			buy_bears(2);
			break;
		case 7://not buy any animals
			break;
		case 8://quit the game
			game_playing = false;
			break;
	}
}
/******************************
 * Function: Zoo::buy_bears(int)
 * Purpose: Buys amount of bears, and adds them to our zoo.
 * ***************************/
void Zoo::buy_bears(int amount){
	if(revenue <bear_cost*amount ){
		cout<<"\033[1;31mYou don't have enough money to buy "<<amount<<" bear(s)!\033[0m"<<endl;
		buy_animals();
		return;	
	}
	revenue -= bear_cost*amount;
	Black_Bear* newarray = new Black_Bear[bearAmount.get_total_amount()+amount];
	for(int i = 0; i < bearAmount.get_total_amount(); i++){
		newarray[i] = black_bears[i];
	}
	for(int i = bearAmount.get_total_amount(); i <bearAmount.get_total_amount() + amount; i++){
		newarray[i] =Black_Bear(48);
	}

	set_black_bears(newarray);
	bearAmount.update_total_amount(bearAmount.get_total_amount() + amount);

}
/******************************
 * Function: Zoo::buy_lions(int)
 * Purpose: Buys amount of sea lions and adds them to our zoo.
 * ***************************/
void Zoo::buy_lions(int amount){
	if(revenue < lion_cost){
		cout<<"\033[1;31mYou don't have enough money to buy "<<amount<<" sea lion(s)!\033[0m"<<endl;
		buy_animals();
		return;
	}
	revenue -= lion_cost * amount;
	Sea_Lion* newarray = new Sea_Lion[lionAmount.get_total_amount() + amount];
	for(int i = 0; i < lionAmount.get_total_amount(); i++){
		newarray[i] = sea_lions[i];
	}
	for(int i = lionAmount.get_total_amount(); i < lionAmount.get_total_amount() + amount; i++){
		newarray[i] = Sea_Lion(48);
	}
	set_sea_lions(newarray);
	lionAmount.update_total_amount(lionAmount.get_total_amount() + amount);
}
/******************************
 * Function: Zoo::buy_tigers(int)
 * Purpose: Buys amount of tigers and adds them to our zoo.
 * ***************************/
void Zoo::buy_tigers(int amount){
	if(revenue <tiger_cost*amount ){
		cout<<"\033[1;31mYou don't have enough money to buy "<<amount<<" tiger(s)!\033[0m"<<endl;
		buy_animals();
		return;	
	}
	revenue -= tiger_cost*amount;
	Tiger* newarray = new Tiger[tigerAmount.get_total_amount() +amount];
	for(int i = 0; i < tigerAmount.get_total_amount(); i++){
		newarray[i] = tigers[i];
	}
	for(int i = tigerAmount.get_total_amount(); i < tigerAmount.get_total_amount() + amount; i++){
		newarray[i] = Tiger(48);
	}

	set_tigers(newarray);
	tigerAmount.update_total_amount(tigerAmount.get_total_amount() + amount);
}

/******************************
 * Function: Zoo::play()
 * Purpose: Contains the game loop for the game, plays until the user doesn't want to play anymore.
 * ***************************/
void Zoo::play(){

	bool attendanceBoom = false;
	do{


		special_event(attendanceBoom);
		update_ages();
		update_amounts();
		get_money(attendanceBoom);
		print_date();
		print_info();
		buy_animals();
		pay_for_food();


		cout<<"\e[2J";//clear screen command
		if(revenue < 0){
			cout<<"\033[1;31mYou're bankrupt!!\033[0m"<<endl;
			game_playing = false;
		}
	}while(game_playing);

}
/******************************
 * Function: Zoo::update_ages()
 * Purpose: Updates the ages of all of the animals by adding one month.
 * ***************************/
void Zoo::update_ages(){
	for(int i = 0; i < bearAmount.get_total_amount(); i++){
		black_bears[i].update_animal_age();
	}
	for(int i = 0; i < lionAmount.get_total_amount(); i++){
		sea_lions[i].update_animal_age();
	}
	for(int i = 0; i < tigerAmount.get_total_amount(); i++){
		tigers[i].update_animal_age();
	}
}

/******************************
 * Function: Zoo::special_event(bool&)
 * Purpose: generates a random event to occur in the zoo. Updates attendance boom if there is an attendance boom.
 * ***************************/
void Zoo::special_event(bool& attendanceBoom ){
	int choice = rand() % 4;

	switch(choice){
		case(0):
			animal_sick();
			break;
		case(1):
			animal_birth();
			break;
		case(2):
			cout<<"\033[1;32mThere is a boom in attendance at the zoo! Sea lions make more money!\033[0m"<<endl;
			attendanceBoom = true;
			break;
		case(3):
			//nothing happens
			break;
		default:
			cout<<"switch statement in special event failed"<<endl;
			break;
	}
}
/******************************
 * Function: Zoo::animal_sick()
 * Purpose: Generates a random animal to get sick, and maybe even die.
 * ***************************/
void Zoo::animal_sick(){
	int animalchoice;
	bool valid= false;
	if(tigerAmount.get_total_amount() + bearAmount.get_total_amount() + lionAmount.get_total_amount() == 0){
		return;
	}else{
		do{
			animalchoice = rand()%3;
			switch(animalchoice){
				case 0:
					if(tigerAmount.get_total_amount() > 0){
						valid = true;
					}

					break;
				case 1:
					if(bearAmount.get_total_amount()> 0){
						valid = true;
					}
					break;
				case 2:
					if(lionAmount.get_total_amount() > 0){
						valid = true;
					}
					break;
				default:

					cout<<"Switch in animal sick broke"<<endl;
					break;
			}
		}while(!valid);
	}
	kill_or_save(animalchoice);
}
/******************************
 * Function: Zoo::kill_or_save(int)
 * Purpose: Decides whether the sick animal at animalchoice will be killed or saved.
 * ***************************/
void Zoo::kill_or_save(int animalchoice){
	switch(animalchoice){
		case 0:{
			       if(revenue >= tigers[0].get_costifsick()){
				       cout<<"\033[1;31mA tiger got sick, but you saved it for: $"<<tigers[0].get_costifsick()<<"\033[0m"<<endl;
				       revenue -= tigers[0].get_costifsick();
			       }else{
				       kill_animal(animalchoice);	
			       }
			       break;}
		case 1:{
			       if(revenue >= black_bears[0].get_costifsick()){
				       cout<<"\033[1;31mA black bear got sick, but you saved it for: $"<<black_bears[0].get_costifsick()<<"\033[0m"<<endl;
				       revenue -= black_bears[0].get_costifsick();
			       }else{
				       kill_animal(animalchoice);
			       }
			       break;}
		case 2:{
			       if(revenue >= sea_lions[0].get_costifsick()){
				       cout<<"\033[1;31mA sea lion got sick, but you saved it for: $"<<sea_lions[0].get_costifsick()<<"\033[0m"<<endl;
				       revenue -= sea_lions[0].get_costifsick();
			       }else{
				       kill_animal(animalchoice);
			       }
			       break;}
		default:
		       cout<<"switch in kill or save messed up"<<endl;
		       break;
	}
}
/******************************
 * Function: Zoo::kill_tiger(int)
 * Purpose: Removes a tiger from your zoo
 * ***************************/
void Zoo::kill_tiger(int animalchoice){
	int whichanimal = 0;
	int arrpos = 0;

	cout<<"\033[1;31mA tiger got sick, and you didn't have enough money to save it, so it died.\033[0m"<<endl;
	whichanimal = rand()%tigerAmount.get_total_amount();
	Tiger* tigerarray = new Tiger[tigerAmount.get_total_amount() -1];
	for(int i = 0; i < tigerAmount.get_total_amount(); i++){
		if(i!= whichanimal){
			tigerarray[arrpos] = tigers[arrpos];
			arrpos++;
		}
	}
	set_tigers(tigerarray);
	tigerAmount.update_total_amount(tigerAmount.get_total_amount() - 1);
}
/******************************
 * Function: Zoo::kill_lion(int)
 * Purpose: Removes a sea lion from your zoo.
 * ***************************/
void Zoo::kill_lion(int animalchoice){
	int whichanimal = 0;
	int arrpos = 0;
	cout<<"\033[1;31mA sea lion got sick, and you dind't have enough money to save it, so it died.\033[0m"<<endl;
	whichanimal = rand() % lionAmount.get_total_amount();
	Sea_Lion* lionarray = new Sea_Lion[lionAmount.get_total_amount() - 1];
	for(int i = 0; i < lionAmount.get_total_amount(); i++){
		if(i!=whichanimal){
			lionarray[arrpos] = sea_lions[arrpos];
			arrpos++;
		}
	}
	set_sea_lions(lionarray);
	lionAmount.update_total_amount(lionAmount.get_total_amount() - 1);

}
/******************************
 * Function: Zoo::kill_bear(int)
 * Purpose: Removes a bear from your zoo
 * ***************************/
void Zoo::kill_bear(int animalchoice){
	int whichanimal = 0;
	int arrpos = 0;
	cout<<"\033[1;31mA bear got sick, and you didn't have enough money to save it, so it died.\033[0m"<<endl;
	whichanimal = rand()% bearAmount.get_total_amount();
	Black_Bear* beararray = new Black_Bear[bearAmount.get_total_amount() - 1];
	for(int i = 0; i < bearAmount.get_total_amount(); i++){
		if(i!=whichanimal){
			beararray[arrpos] = black_bears[arrpos];
			arrpos++;
		}
	}
	set_black_bears(beararray);
	bearAmount.update_total_amount(bearAmount.get_total_amount() -1);

}
/******************************
 * Function: Zoo::kill_animal(int)
 * Purpose: Kills an animal, based on the animal chosen.
 * ***************************/
void Zoo::kill_animal(int animalchoice){
	switch(animalchoice){
		case 0:
			kill_tiger(animalchoice); 
			break;
		case 1:
			kill_bear(animalchoice);
			break;
		case 2:
			kill_lion(animalchoice);
			break;
		default:
			cout<<"switch in kill animal failed"<<endl;
	}
}



/******************************
 * Function: Zoo::lion_baby()
 * Purpose: Causes sea lions to create their amount of babies which are 0 months old.
 * ***************************/
void Zoo::lion_baby(){
	int amount_of_sea_lions = lionAmount.get_total_amount();
	Sea_Lion* newarray = new Sea_Lion[amount_of_sea_lions + sea_lions[0].get_amount_of_babies()];
	for(int i = 0; i < amount_of_sea_lions; i++){
		newarray[i] = sea_lions[i];
	}
	for(int i = amount_of_sea_lions; i < amount_of_sea_lions + sea_lions[0].get_amount_of_babies(); i++){
		newarray[i] = Sea_Lion(0);
	}
	amount_of_sea_lions = amount_of_sea_lions + sea_lions[0].get_amount_of_babies();
	lionAmount.update_total_amount(amount_of_sea_lions);
	set_sea_lions(newarray);
}
/******************************
 * Function: Zoo::bear_baby()
 * Purpose: Adds bear babies to your zoo, based on how many babies bears have.
 * ***************************/
void Zoo::bear_baby(){
	int amount_of_bears = bearAmount.get_total_amount();
	Black_Bear* newarray = new Black_Bear[amount_of_bears +black_bears[0].get_amount_of_babies()];
	for(int i = 0; i < amount_of_bears; i++){
		newarray[i] = black_bears[i];
	}
	for(int i = amount_of_bears; i < amount_of_bears + black_bears[0].get_amount_of_babies(); i++){
		newarray[i] = Black_Bear(0);
	}
	amount_of_bears = amount_of_bears + black_bears[0].get_amount_of_babies();
	bearAmount.update_total_amount(amount_of_bears);
	set_black_bears(newarray);
}
/******************************
 * Function: Zoo::tiger_baby()
 * Purpose: Adds tiger babies to your zoo, based on how many babies tigers have
 * ***************************/
void Zoo::tiger_baby(){
	int amount_of_tigers = tigerAmount.get_total_amount();
	Tiger* newarray = new Tiger[amount_of_tigers +tigers[0].get_amount_of_babies()];
	for(int i = 0; i < amount_of_tigers; i++){
		newarray[i] = tigers[i];
	}
	for(int i = amount_of_tigers; i < amount_of_tigers + tigers[0].get_amount_of_babies(); i++){
		newarray[i] = Tiger(0);
	}
	amount_of_tigers = amount_of_tigers + tigers[0].get_amount_of_babies();
	tigerAmount.update_total_amount(amount_of_tigers);
	set_tigers(newarray);
}

/******************************
 * Function: Zoo::animal_birth()
 * Purpose: Chooses a random animal to give birth.
 * ***************************/
void Zoo::animal_birth(){
	int animalchoice = 0;
	int tiger_adults = tigerAmount.get_adult_amount();
	int bear_adults = bearAmount.get_adult_amount();
	int lion_adults = lionAmount.get_adult_amount();
	if(tiger_adults < 2 && bear_adults < 2 && lion_adults < 2){
		return;
	}
	bool valid = false;
	do{
		animalchoice = rand()%3;
		switch(animalchoice){
			case 0:
				if(tiger_adults >= 2){
					cout<<"\033[1;32mYour tigers had "<<tigers[0].get_amount_of_babies()<<" babies this month!\033[0m"<<endl;
					tiger_baby();
					valid = true;
				}
				break;
			case 1:
				if(bear_adults >= 2){
					cout<<"\033[1;32mYour bears had "<<black_bears[0].get_amount_of_babies()<<" babies this month!\033[0m"<<endl;

					bear_baby();
					valid = true;
				}
				break;
			case 2:
				if(lion_adults >= 2){
					cout<<"\033[1;32mYour sea lions had "<<sea_lions[0].get_amount_of_babies()<<" babies this month!\033[0m"<<endl;

					lion_baby();
					valid = true;
				}
				break;
			default:
				cout<<"switch in animalbirth fucked up"<<endl;
				break;
		}
	}while(!valid);	
}
/******************************
 * Function: Zoo::update_amount()
 * Purpose: Updates the amount of each type of animal in the zoo.
 * ***************************/
void Zoo::update_amounts(){
	int tiger_adults = 0;
	int tiger_adolescents = 0;
	int tiger_babies = 0;
	int bear_adults = 0;
	int bear_adolescents = 0;
	int bear_babies = 0;
	int lion_adults = 0;
	int lion_adolescents = 0;
	int lion_babies = 0;
	for(int i = 0; i < lionAmount.get_total_amount(); i++){
		if (sea_lions[i].get_isadult()){
			lion_adults++;	
		}else if(sea_lions[i].get_isbaby()){
			lion_babies++;
		}else{
			lion_adolescents++;
		}
	}
	lionAmount.update_adult_amount(lion_adults);
	lionAmount.update_baby_amount(lion_babies);
	lionAmount.update_adolescent_amount(lion_adolescents);
	for(int i = 0; i < bearAmount.get_total_amount(); i++){
		if(black_bears[i].get_isadult()){
			bear_adults++;
		}else if(black_bears[i].get_isbaby()){
			bear_babies++;
		}else{
			bear_adolescents++;
		}
	}
	bearAmount.update_adult_amount(bear_adults);
	bearAmount.update_adolescent_amount(bear_adolescents);
	bearAmount.update_baby_amount(bear_babies);
	for(int i = 0; i < tigerAmount.get_total_amount(); i++){
		if(tigers[i].get_isadult()){
			tiger_adults++;
		}else if(tigers[i].get_isbaby()){
			tiger_babies ++;
		}else{
			tiger_adolescents++;
		}
	}
	tigerAmount.update_adult_amount(tiger_adults);
	tigerAmount.update_adolescent_amount(tiger_adolescents);
	tigerAmount.update_baby_amount(tiger_babies);

}
/******************************
 * Function: Zoo::pay_for_food()
 * Purpose: Pays for food for each animal, based on their foodcost.
 * ***************************/
void Zoo::pay_for_food(){
	for(int i = 0; i < lionAmount.get_total_amount(); i++){
		revenue -= sea_lions[i].get_foodcost();
		sea_lions[i].update_foodcost();
	}
	for(int i = 0; i < tigerAmount.get_total_amount(); i++){
		revenue -= tigers[i].get_foodcost();
		tigers[i].update_foodcost();
	}
	for(int i = 0; i < bearAmount.get_total_amount(); i++){
		revenue -= black_bears[i].get_foodcost();
		black_bears[i].update_foodcost();
	}

}



