#include "UI.h"
#include <Windows.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128
	int UI::in_int()
	{
		int a;
		cin>>a;
		return a;
	}
	double UI::in_double()
	{
		double a;
		cin>>a;
		return a;
	}
	string UI::in_string()
	{
		char b=getchar();
		string a;
		getline(cin,a);
		if(b!=10)
		{
			a=b+a;
		}
		return a;
	}
	char UI::in_char()
	{
		char a;
		cin>>a;
		return a;
	}
	long UI::in_long()
	{
		long a;
		cin>>a;
		return a;
	}
	void UI::print_menu_footer()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"What would you like to do?[Please enter number]"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void UI::get_name_string()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"Enter Product Name OR Category OR Manufacturer"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout<<"[Press Enter if You want to Sarch by Barcode]"<<endl;
	}
	void UI::get_product_details()
	{
		cout<<endl<<"Enter Product Details :"<<endl;
		cout<<"Enter Product Name, Category, Barcode, Manufacturer, Price, Number Sold, Number in Stock -"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"[ Press enter after each input ]"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void UI::print_error()
	{
		cout<<"Incorrect input, Please try again"<<endl;
	}
	void UI::printoutput(string a)
    {
	cout<<a<<endl;
    }
	void UI::print_stats_menu()
	{   
		
		cout<<endl<<"Display top selling by:"<<endl;
		cout<<"1."<<"Number(To be entered by you)"<<endl;
		cout<<"2."<<"Category"<<endl;
		cout<<"3."<<"Manufacturer"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"Enter your Choice : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void UI::header_text()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		for(int i=0;i<80;i++)
			cout<<"*";
			cout<<endl;
		for(int i=0;i<10;i++)
			cout<<" ";
			cout<<" CEG Hypermarket Inventory Control and Monitoring System"<<endl;
		for(int i=0;i<80;i++)
			cout<<"*";
			cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 }
	 void UI::print_menu()
	 {
		 cout<<endl<<endl<<"1."<<"Add new Product"<<endl;
		 cout<<"2."<<"Delete Product"<<endl;
		 cout<<"3."<<"Reset Product Sales"<<endl;
		 cout<<"4."<<"Sell Product"<<endl;
		 cout<<"5."<<"Restock Product"<<endl;
		 cout<<"6."<<"Generate Statistics"<<endl;
		 cout<<"7."<<"List all Products"<<endl;
		 cout<<"8."<<"Load Data from Another File"<<endl;
		 cout<<"9."<<"Check if a Product has Expired"<<endl;
		 cout<<"10."<<"Quit"<<endl;
		 cout<<"11."<<"Browse the web"<<endl;
		 cout<<"12."<<"Make Notes"<<endl;
		 cout<<"13."<<"Feedback"<<endl<<endl<<endl;;
		 
	 }
	 void UI::confirm_perishable()
	 {
		 cout<<"Is the Product Perishable ? " <<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		 cout<<"[ Enter Y for yes and N for no ]"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	 }
	 void UI::get_perishable_details()
	 {
		 cout<<"Also enter discount percentage and date of expiry ( in the format ddmmyyyy )"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		 cout<<"[ Press enter after each input ]"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 }
	 void UI::getcontinue()
	 {
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		 cout<<"Press Any Key to Return to Main Screen"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 }
	 void UI::printoutput(vector<string> a)
	 {
		 for (int i=0;i<a.size();i++)
			 cout<<a[i]<<endl;
	 }