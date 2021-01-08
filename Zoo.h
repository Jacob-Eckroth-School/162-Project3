#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <iostream>
using namespace std;
#include "./Animal.h"
#include "./Tiger.h"
#include "./Black_Bear.h"
#include "./Sea_Lion.h"
#include "./Amounts.h"
class Zoo{
	private:
		int revenue;
		Amounts tigerAmount;
		Amounts bearAmount;
		Amounts lionAmount;
				
		int lion_cost;
		int tiger_cost;
		int bear_cost;

		bool game_playing;
		

		Tiger* tigers;
		Black_Bear* black_bears;
		Sea_Lion* sea_lions;

		//stuff with date
		time_t now;
		tm *ltm;
		int year;
		int month;


	public:
		~Zoo();
		Zoo();
		void kill_animal(int);
		void kill_tiger(int);
		void kill_bear(int);
		void kill_lion(int);
		void kill_or_save(int);
		void animal_sick();
		void animal_birth();
		void special_event(bool&);
		
		void play();
		void update_ages();
		int get_revenue();
		int get_amount_of_tigers();
		int get_amount_of_bears();
		int get_amount_of_sea_lions();
		Tiger* get_tigers();
		Black_Bear* get_black_bears();
		Sea_Lion* get_sea_lions();
		void update_amounts();	



		void lion_baby();
		void bear_baby();
		void tiger_baby();

		void set_revenue(int);
		void set_amount_of_tigers(int);
		void set_amount_of_black_bears(int);
		void set_amount_of_sea_lions(int);
		void set_tigers(Tiger*);
		void set_black_bears(Black_Bear*);
		void set_sea_lions(Sea_Lion*);
		void get_money(bool);
		void buy_animals();
		
		void dealwithinput(int);	
		void print_info();

		void pay_for_food();
		void print_date();

		
		void buy_bears(int amount);
		void buy_lions(int amount);
		void buy_tigers(int amount);
		


};








#endif
