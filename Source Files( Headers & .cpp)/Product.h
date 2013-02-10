#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
using namespace std;
class Product
{
/*	
•	Name
•	Category
•	Barcode number
•	Price
•	Manufacturer
•	Number in Stock
•	Number sold per month


*/
private:
	string name;
	double barcode;
	double price;
	string manufacturer;
	int no_in_stock;
	int no_sold;
	string category;

public:
	Product();
	Product(string, double, double, string, int, int, string);
    string getname();
	double getprice();
	double getbarcode();
	string getmanufacturer();
	int getno_in_stock();
	int getno_sold();
	string get_category();
	void saleof_stock(int number);
	void restock(int number);
	void reset();
	void sell(int);
	virtual char ifperishable();
	
	//methods to be used in perishable class
	 virtual string returnexpiry();
	 virtual double getdisc_percent();
};
#endif