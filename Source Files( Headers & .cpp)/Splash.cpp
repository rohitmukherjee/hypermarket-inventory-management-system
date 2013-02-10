#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<Windows.h>
#include<stdlib.h>
#define YELLOW 14
using namespace std;
class splash{
public:	
int homescreen(string &username)
{  char ch;string name,pass;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW); 
	cout<<" .                                     ....  .       .....    ......"<<endl;         
   cout<<". .                     ..   ......    ..........  . ......   ,,,...."<<endl;         
   cout<<" .OOOOOOOOOOOOOOOOO$Z8OOOO...OOOO.... .,O,..OOO..  ..:OO:..DOOO$78OO,.."<<endl;       
   cout<<" .OOO.8O,.O8$7OO8I7OO:88OO...OO8OO... .,8,..8OO.     :OO:.IOO........."<<endl  ;      
    cout<<".OOO,,:.,.:.7OO$:?,+?~8OO...OO,OOO. ..,8,..8OO.     :OO,.?OO8...  . "<<endl   ;      
    cout<<".OOO,=,=,I,?7OO:O7I,OO~OO...OO.:OOO+,.,O,..8OO.     :OO,..8OOOOO~,...."<<endl;      
    cout<<".OO8777I777I$OO+$8,I8:ZOO...OO..,OOO?,,O,..8OO.     :OO,....OOOOO88..."<<endl;      
    cout<<".8OO888OOOOOO88OO88O88OO8...OO....OOO$,O,. 8OO.   ..:OO,..   ...8OOO.."<<endl;      
    cout<<" O.....:I.I:,...........8...OO.....OOO8O,..$OO..  ..OO8...    ...OOO..."<<endl;     
     cout<<"O.I$.D777I7O.I~,,8O+.,.8...OO..  .,8OOO,...OOO=...ZOOO..OO.....OO8O.."<<endl;      
    cout<<" O.~7.Z8777OO..I7IIO..=.8...OO..   ,.$OO,....,8O8OOO8.....8OOO8OOZ.,."<<endl;       
    cout<<" $..,7ZO8$8O8$777777IO,.8.. .     ... ...   ........ ..  .........."<<endl;         
    cout<<" ....877OOOZ7777$777....$.......................,.,.................."<<endl;       
    cout<<"..8...~..OI7$OIZ7O77...:....8~O~I,$..ZO.?$I?...D.8I?,8O..+=8==..Z=.?."<<endl;       
    cout<<" ..:.....O7?I...7?,77..O.  .8.OO$.O,.$O.,88?,..:??7.ZD.O.?=D.+..O.Z..."<<endl;      
     cout<<"..=.....7$...,7O..7I.O.   .........................................."<<endl;       
     cout<<" ..8.~I7I...OI$II77.8..   ....8..,.,..................           .."<<endl;        
      cout<<" ..8............,.8,..   .I.:8...Z$8..,..?88.:....O+=.."<<endl;                   
       cout<<" ...Z..... ....=7..     ...,....,....~O...O.,.,...,.."<<endl;                    
        cout<<"....,O.....,$?...      ............................"<<endl;                     
        cout<<" .. ...,8OZ,..                       .   ..         "<<endl;                    
         cout<<"  . ........                                       "<<endl;  

		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12); 
		 cout<<"Welcome to the CEG HyperMarket Inventory"<<endl<<endl;
		 cout<<endl<<"Are You a New User?[Y/N]"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
		 cin>>ch;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12); 

		 if(ch=='Y'||ch=='y')
		 {   
			 cout<<endl<<"Please Enter New User-name ( No Spaces )"<<endl;
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
			 cin>>name;
			 username=name;
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12); 
			 cout<<endl<<"Please Enter Password ( No Spaces )"<<endl;cout.flush();
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
			 cin>>pass;
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12); 
			 system("cls");

			 cout<<"User Account Created, Thank You! "<<endl;
			 cout<<name<<pass<<endl;
			  string filename=name+".txt";
			 ofstream write(filename);
			
			cout<<filename;cout<<name;cout<<pass;
		
			 write<<pass; write.close();system("cls");
			 return 1;
		 }
		 
		 else if(ch=='N'||ch=='n')
		 {
			  cout<<endl<<"Please Enter User-name"<<endl;
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
			  getline(cin,name);getline(cin,name);
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12); 
			  string filename=name+".txt";
			  cout<<endl<<"Please Enter Password"<<endl;
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); 
			  getline(cin,pass);
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12); 
			  ifstream in;
			  in.open(filename);
			  if(!in)
			  {		cout<<"Database Error, Please go to the Main Menu"<<endl;
					return 0;
			  }
			  else
			  {   string x;
				  in>>x;
				  if(x==pass)
				  {
					  cout<<"Hello!  "<<name<<"  Welcome to CICMS"<<endl<<endl;
					  cout<<"Press To Continue"<<endl;
					  getch();
					  system("cls");
				  }
				  else
				  { cout<<"Authentication Failure"<<endl;
						return 0;
				  }
			  }
		
		 in.close();
		 }
		 else
		 {
			 cout<<"Authentication Failure"<<endl;
			 return 0;
		 }
}
};