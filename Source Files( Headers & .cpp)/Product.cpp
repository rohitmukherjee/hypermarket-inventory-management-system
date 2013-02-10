#include "Product.h"
using namespace std;

	Product::Product()
	{
		name="";
		barcode=0;
		price=0;
		manufacturer="";
		no_in_stock=0;
		no_sold=0;
		category="";
	}
	Product::Product(string name1, double barcode1, double price1, string manufacturer1, int no_in_stock1, int no_sold1, string category1)
	{
		name=name1;
		barcode=barcode1;
		price=price1;
		manufacturer=manufacturer1;
		no_in_stock=no_in_stock1;
		no_sold=no_sold1;
		category=category1;
	}
	string Product::getname()
	{
		return name;
	}
	double Product::getprice()
	{
		return price;
	}
	double Product::getbarcode()
	{
		return barcode;
	}
	string Product::getmanufacturer()
	{
		return manufacturer;
	}
	int Product::getno_in_stock()
	{
		return no_in_stock;
	}
	int Product::getno_sold()
	{
		return no_sold;
	}
	string Product::get_category()
	{
		return category;
	}
	void Product::saleof_stock(int number)
	{
		no_in_stock=no_in_stock-number;
	}
	void Product::restock(int number)
	{
		no_in_stock=no_in_stock + number;
	}
	void Product::reset()
	{
		no_sold=0;
	}
	void Product::sell(int number)
	{
		no_sold+=number;
	}
	string Product::returnexpiry()
	{
		return (" ");
	}
	double Product::getdisc_percent()
	{
		return 0;
	}
	char Product::ifperishable()
	{
		return 'n';
	}