#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
	public:
		Animal();
		Animal(int,int,bool,bool);
		int get_foodcost();
		int get_age();
		bool get_isbaby();
		bool get_isadult();
		int get_revenue();
		int get_costifsick();
		int get_costifsickbaby();
		int get_revenueifbaby();


		void set_costifsick(int);
		void set_revenue(int);
		void set_foodcost(int);
		void set_age(int);
		void set_isbaby(bool);
		void set_isadult(bool);
		void update_animal_age();
		void update_foodcost();
	protected:
		int foodcost;
		int age;//measured in months
		bool isBaby;
		bool isAdult;
		int costIfSick;
		int revenue;
		int revenueifbaby;
		int costIfSickBaby;

};


#endif
