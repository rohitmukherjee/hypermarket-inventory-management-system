/*  Additionally, there is a certain type of product called Perishable Foods, which have:
•	Expiry Date
•	Discount Percentage
*/
#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Product.h"
#include <sstream>
class Perishable:public Product
{
private:
	double disc_percent;
	struct date{
		int day;
		int month;
		int year;
	};
	date expiry;
public:
	 Perishable::Perishable(string name1,double barcode1,double price1,string manufacturer1,int no_in_stock1,int no_sold1,string category1,int day1,int month1,int year1,double disc_percent);
	 string returnexpiry();
	 double getdisc_percent();
	 char ifperishable();
};
#endif
