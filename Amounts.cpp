#include "./Amounts.h"
/***************************
 * Function:Amounts::update_baby_amount(int);
 * Purpose: updates the amount of babies that the amount class has.
 * ************************/
void Amounts::update_baby_amount(int newamount){
	babyAmount = newamount;
}
/***************************
 * Function:Amounts::update_adolescent_amount(int)
 * Purpose:updates the amount of adolescents.
 * ************************/
void Amounts::update_adolescent_amount(int newamount){
	adolescentAmount = newamount;
}
/***************************
 * Function:Amounts::update_adult_amount(int)
 * Purpose:updates the amount of adults
 * ************************/
void Amounts::update_adult_amount(int newamount){
	adultAmount = newamount;
}
/***************************
 * Function:Amounts::update_total_amount(int)
 * Purpose: Updates the total amount.
 * ************************/
void Amounts::update_total_amount(int newamount){
	totalAmount = newamount;
}
/***************************
 * Function:Amounts::get_baby_amount()
 * Purpose:Returns the amount of babies
 * ************************/
int Amounts::get_baby_amount(){
	return babyAmount;
}
/***************************
 * Function:Amounts::get_adolescent_amount()
 * Purpose:Returns the amount of adolescents.
 * ************************/
int Amounts::get_adolescent_amount(){
	return adolescentAmount;
}
/***************************
 * Function:Amounts::get_adult_amount()
 * Purpose: Returns the amount of adults
 * ************************/
int Amounts::get_adult_amount(){
	return adultAmount;
}
/***************************
 * Function:Amounts::get_total_amount()
 * Purpose:returns the total amount of animals
 * ************************/
int Amounts::get_total_amount(){
	return totalAmount;
}
/***************************
 * Function:Amounts::Amounts()
 * Purpose: Default animal constructor that sets the beginning amounts to zero.
 * ************************/
Amounts::Amounts(){
	babyAmount = 0;
	adultAmount = 0;
	totalAmount = 0;
	adolescentAmount = 0;
}
