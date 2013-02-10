#include <iostream>
#include <Windows.h>
#include "UI_Statistics.h"
#include "Product.h"
#include <conio.h>
#include <stdlib.h>
#include "UI.h"
#include "product_manager.h"
#include "Perishable.h"
#include "splash.cpp"
using namespace std;
int main()
{
	string items="";
	int choice=0, last_choice;
	product_manager PM;
	UI ui;
	splash x;
	string username;
	int y=x.homescreen(username);
	if(y==0)
		return 0;
	ui.printoutput("Enter Name of File to Load - ");
	ui.printoutput("[ Example - xyz.txt ]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	items=ui.in_string();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	PM.list_initialize(items);
	system("cls");
	PM.getjobs();
	do
	{   
		ui.header_text();
		ui.print_menu();
		ui.print_menu_footer();
		last_choice=choice;
		cin>>choice;
		switch(choice)
		{
		case 13:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				ui.printoutput("Please Type your Feedback: ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				string s=ui.in_string();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				PM.revieve_feedback(s,username);
				break;
			}
		case 11:
			{
				system( "\"C:\\Program Files\\Internet Explorer\\iexplore.exe\"");
				break;
			}
		case 12:
			{
				system( "\"%windir%\\system32\\notepad.exe\"");
				break;
			}
		case 10: 
			{
				PM.file_update();
				return 0;
			}
		case 1:
			{   ui.confirm_perishable();
				char c=ui.in_char();

				Product* newproduct=NULL;
				switch(c)
				{
				case 'y':
				case 'Y':
					{
					    string name2,manufacturer,category;
						double price,barcode;
						int no_in_stock,no_sold;
						ui.get_product_details();
						name2=ui.in_string();
						category=ui.in_string();
						barcode=ui.in_double();
						manufacturer=ui.in_string();
						price=ui.in_double();
						no_sold=ui.in_int();
						no_in_stock=ui.in_int();
						ui.get_perishable_details();
						int date;double discountpercent;
						discountpercent=ui.in_double();
						date=ui.in_int();
						newproduct=new Perishable(name2,barcode,price,manufacturer,no_in_stock,no_sold,category,(date/1000000),((date/10000)%100),date%10000,discountpercent);
						break;
					}
				case 'n':
				case 'N':
					{
						string name2,manufacturer,category;
						double price,barcode;
						int no_in_stock,no_sold;
						ui.get_product_details();
						name2=ui.in_string();
						category=ui.in_string();
						barcode=ui.in_double();
						manufacturer=ui.in_string();
						price=ui.in_double();
						no_sold=ui.in_int();
						no_in_stock=ui.in_int();
						newproduct=new Product(name2,barcode,price,manufacturer,no_in_stock,no_sold,category);
						break;
					}
				default:
					{
						ui.print_error();
						return 0;
					}
				}
				bool result=PM.add_item_user(newproduct);
				if(result)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
					ui.printoutput("Product Added");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else
				{
					ui.print_error();
				}
				break;
			}
		case 2:
			{
				int index;
				string product_name;
				ui.get_name_string();
				product_name=ui.in_string();
				bool result=PM.delete_item(product_name);
				if(result)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					ui.printoutput("Product Deleted");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else
				{
					ui.print_error();
				}
				break;
			}
		case 3:
			{
				string product_name;
				ui.get_name_string();
				product_name=ui.in_string();
				if (!PM.reset_sales(product_name))
					ui.print_error();
				break;
			}

		case 4:
			{
					string product_name;
					ui.get_name_string();
					product_name=ui.in_string();
					if (!PM.sale(product_name))
						ui.print_error();
					break;
			}		
		case 5:	
			{	string product_name;
					ui.get_name_string();
					product_name=ui.in_string();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					ui.printoutput("Enter the number by which to restock");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					int x=ui.in_int();
					if (x<0)
						ui.print_error();
					else
					if (!PM.restock(product_name,x))
						ui.print_error();
					break;
			}
		case 6:
			{
					int choice2;
					ui.print_stats_menu();
					choice2=ui.in_int();
					string choice3;
					int number;
					switch(choice2)
					{
					case(1):
						{
							ui.printoutput("Enter Number of Products to Display -");
							number=ui.in_int();
							PM.topselling(number);
							break;
						}
					case(2):
						{
							ui.printoutput("Enter Category -");
							choice3=ui.in_string();
							PM.best_incategory(choice3);
							break;
						}
					case(3):
						{
							ui.printoutput("Best Selling Manufacturer -");
							vector<string> result=PM.bestmanufacturer();
							ui.printoutput(result);
							break;
						}
					default:
						ui.print_error();
					}
					break;
			}
		case 7:
			{
				PM.list_items();
				break;
			}
		case 8:
			{
				ui.printoutput("Enter Name of File to Load - ");
				ui.printoutput("[ Example - xyz.txt ]");
				items=ui.in_string();
				PM.list_initialize(items);
				break;
			}
		case 9:
			{
				string product_name;
				ui.get_name_string();
				product_name=ui.in_string();
				PM.checkexpired(product_name);
				break;
			}
		default:
			{ 
				ui.print_error();
			}
		}
	 ui.getcontinue();
	 getch();
     system("cls");
	}while(true);
	return 0;
}
