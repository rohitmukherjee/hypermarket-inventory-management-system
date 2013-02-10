/*  Additionally, there is a certain type of product called Perishable Foods, which have:
•	Expiry Date
•	Discount Percentage
*/

#include <sstream>
#include "Perishable.h"
Perishable::Perishable(string name1,double barcode1,double price1,string manufacturer1,int no_in_stock1,int no_sold1,string category1,int day1,int month1,int year1,double disc_percent1)
	:Product(name1,barcode1,price1,manufacturer1,no_in_stock1,no_sold1,category1)
{
	expiry.day=day1;
	expiry.year=year1;
	expiry.month=month1;
	disc_percent=disc_percent1;
}

string Perishable::returnexpiry()
{
	ostringstream expire;
	if(expiry.day<10)
		expire<<"0";
	expire<<expiry.day;
	if(expiry.month<10)
		expire<<"0";
	expire<<expiry.month<<expiry.year;
	string s;
	s=expire.str();
	return s;
	//returns date in dd,mm,yyyy format
}
double Perishable::getdisc_percent()
{
	return disc_percent;
}
char Perishable::ifperishable()
{
	return 'y';
}