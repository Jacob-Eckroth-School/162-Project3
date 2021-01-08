#ifndef AMOUNTS_H
#define AMOUNTS_H


class Amounts{
	private:
		int babyAmount;
		int adolescentAmount;
		int adultAmount;
		int totalAmount;
	public:
		Amounts();
		void update_baby_amount(int);
		void update_adolescent_amount(int);
		void update_adult_amount(int);
		void update_total_amount(int);
		int get_baby_amount();
		int get_adolescent_amount();
		int get_adult_amount();
		int get_total_amount();

};




#endif
