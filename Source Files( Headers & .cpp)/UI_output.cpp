#include "UI_output.h"
UI_output::UI_output()
	{
	}
	void UI_output::print_menu_footer()
	{
		cout<<"What would you like to do?[Please enter number]"<<endl;
	}
	void UI_output::get_name_string()
	{
		cout<<"Enter Product name"<<endl;
	}
	void UI_output::get_product_details()
	{
		cout<<endl<<"Enter Product Details :"<<endl;
		cout<<"Enter Product Name, Category, Barcode, Manufacturer, Price, Number Sold, Number in Stock -"<<endl;
	}
	void UI_output::print_error()
	{
		cout<<"Incorrect input, Please try again"<<endl;
	}
	void UI_output::printoutput(string a)
    {
	cout<<a<<endl;
    }
