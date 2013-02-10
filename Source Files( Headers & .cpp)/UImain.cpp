#include "UImain.h"
void UImain::header_text()
	{

		for(int i=0;i<80;i++)
			cout<<"*";
			cout<<endl;
		for(int i=0;i<10;i++)
			cout<<" ";
			cout<<" CEG Hypermarket Inventory Control and Monitoring System"<<endl;
		for(int i=0;i<80;i++)
			cout<<"*";
			cout<<endl;

	 }
	 void UImain::print_menu()
	 {
		 cout<<endl<<endl<<"1."<<"Add new Product"<<endl;
		 cout<<"2."<<"Delete Product"<<endl;
		 cout<<"3."<<"Reset Product Sales"<<endl;
		 cout<<"4."<<"Sell Product"<<endl;
		 cout<<"5."<<"Restock Product"<<endl;
		 cout<<"6."<<"Generate Statistics"<<endl;
		 cout<<"7."<<"List all Products"<<endl;
		 cout<<"8."<<"Load Data"<<endl;
		 cout<<"9."<<"Quit"<<endl;
	 }