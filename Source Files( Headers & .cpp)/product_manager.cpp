#include "product_manager.h"
#include "Product.h"
#include "Perishable.h"
#include "circularDoubleList.h"
#include "dynamicArray.h"
#include "vector_version.h"
#include "sorted_list.h"
#include<fstream>
#include<fstream>
#include<iostream>
#include "UI.h"
#include <ctime>
#include <stack>
#include<queue>
using namespace std;

product_manager::product_manager()
{
	database=new circular_double_list;
}

bool product_manager::add_item_user(Product* x)
{
	if (search_barcode(x->getbarcode())==NULL)
	{
			database->add(x);
			return true;
	}
	else
		return false;
}
bool product_manager::add_item(Product* x)
{
			database->add(x);
			return true;
}
bool product_manager::delete_item(string ncm)
{
	if(ncm!="")
	{
	vector <Product*> search_results;
	search_results=search_name(ncm);
	if(search_results.empty()==true)
		search_results=search_category(ncm);
	if(search_results.empty()==true)
		search_results=search_manufacturer(ncm);
	if(search_results.size()==1)
	{
		database->scrap(search_results[0]);
		return true;
	}
	else if(search_results.size()>1)
	{
		for(int i=0;i<search_results.size();i++)
		{
			database->scrap(search_results[i]);
		}
		return true;
	}
	else
		return false;
	}
	else 
	{   
		UI ui;
		ui.printoutput("Enter barcode");
		double x=ui.in_double();
		bool result=delete_item(x);
		return result;
}
}
bool product_manager::delete_item(double barcode)
{
	Product* ans=search_barcode(barcode);
	if(ans!=NULL)
	{
		database->scrap(ans);
		return true;
	}
	else
		return false;
}

vector<Product*> product_manager::search_name(string name)
{
	vector<Product*> ans;
	int size=database->getsize();
	for (int i=0;i<size;i++)
	{
		Product* p=database->retrieve(i);
		if (p->getname()==name)
			ans.push_back(p);
	}
	return ans;
}

vector<Product*> product_manager::search_manufacturer(string m)
{
	vector<Product*> ans;
	int size=database->getsize();
	for (int i=0;i<size;i++)
	{
		Product* p=database->retrieve(i);
		if (p->getmanufacturer()==m)
			ans.push_back(p);
	}
	return ans;
}

vector<Product*> product_manager::search_category(string c)
{
	vector<Product*> ans;
	int size=database->getsize();
	for (int i=0;i<size;i++)
	{
		Product* p=database->retrieve(i);
		if (p->get_category()==c)
			ans.push_back(p);
	}
	return ans;
}

Product* product_manager::search_barcode(double b)
{
	int size=database->getsize();
	for (int i=0;i<size;i++)
	{
		Product* p=database->retrieve(i);
		if (p->getbarcode()==b)
			return p;
	}
	return NULL;
}

/*
	void sale(string ncm);
	void sale(double barcode);
	void restock(string ncm);
	void restock(double barcode);
	void reset_sales(string ncm);
	void reset_sales(double barcode);

	*/
bool product_manager::sale(string ncm)
{
	double x;
	vector<Product*> search_result=search_name(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=search_category(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=search_manufacturer(ncm);
	if(search_result.size()==1)
	{
		if (search_result[0]->getno_in_stock()<=0)
			return false;
		search_result[0]->saleof_stock(1);
		search_result[0]->sell(1);
		return true;
	}
	else if(search_result.size()>=1)
	{
		bool re=false;
		for(int i=0;i<search_result.size();i++)
		{
			if (search_result[i]->getno_in_stock()>0)
			{
				re=true;
				search_result[i]->saleof_stock(1);
				search_result[i]->sell(1);
			}
		}
		return re;
	}
	else
	{
		UI ui;
		ui.printoutput("Enter barcode");
		x=ui.in_double();
		if (sale(x))
			return true;
		return false;
	}
}

bool product_manager::sale(double barcode)
{
	Product* ans=search_barcode(barcode);
	if(ans!=NULL)
	{
		if (ans->getno_in_stock()<=0)
			return false;
		ans->saleof_stock(1);
		ans->sell(1);
		return true;
	}
	return false;
}

bool product_manager::restock(string ncm,int number)
{
	double x;
	vector<Product*> search_result=search_name(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=search_category(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=search_manufacturer(ncm);
	if(search_result.size()==1)
	{
		search_result[0]->restock(number);
		return true;
	}
	else if(search_result.size()>=1)
	{
		for(int i=0;i<search_result.size();i++)
		{
			search_result[i]->restock(number);
		}
		return true;
	}
	else
	{
		UI ui;
		ui.printoutput("Enter barcode");
		x=ui.in_double();
		if (restock(x,number))
			return true;
		return false;
	}
}

bool product_manager::restock(double barcode,int number)
{
	
	Product* ans=search_barcode(barcode);
	if(ans!=NULL)
	{
		ans->restock(number);
		return true;
	}
	return false;
}
bool product_manager::reset_sales(string ncm)
{
	double x;
	vector<Product*> search_result=search_name(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=search_category(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=search_manufacturer(ncm);
	if(search_result.size()==1)
	{
		search_result[0]->reset();
		return true;
	}
	else if(search_result.size()>=1)
	{
		for(int i=0;i<search_result.size();i++)
		{
			search_result[i]->reset();
		}
		return true;
	}
	else
	{
		UI ui;
		ui.printoutput("Enter barcode");
		x=ui.in_double();
		if (reset_sales(x))
			return true;
		return false;
	}
}
bool product_manager::reset_sales(double barcode)
{
	
	Product* ans=search_barcode(barcode);
	if(ans!=NULL)
	{
		ans->reset();
		return true;
	}
	return false;
}
/*//file operations
	void list_initialize();
	void file_update();*/

void product_manager::list_initialize(string a)
{
	if(a=="")
	{
		a="batchdata.txt";
	}
	ifstream readFile(a);
	int x=0,i=0;//x contains the number of products to be inputted
	readFile>>x;
	char type;
	while(i<x)
	{
		readFile>>type;
		if(type=='y')
		{
			string name,manufacturer,category;
			int barcode;double price,disc_percent;
			int no_in_stock,no_sold,date;
			getline(readFile,name);getline(readFile,name);//>>name>>category>>barcode>>price>>manufacturer>>no_in_stock>>no_sold;
			getline(readFile,category);
			readFile>>barcode;
			readFile>>price;
			getline(readFile,manufacturer);getline(readFile,manufacturer);
			readFile>>no_in_stock;
			readFile>>no_sold;
			readFile>>date;
			readFile>>disc_percent;
			//string name1,double barcode1,double price1,string manufacturer1,int no_in_stock1,int no_sold1,string category1,int day1,int month1,int year1
			Product* newprod=new Perishable(name,barcode,price,manufacturer,no_in_stock,no_sold,category,date/1000000,(date/10000)%100,date%10000,disc_percent);
			add_item(newprod);

		}
		else
		{
			string name,manufacturer,category;
			int barcode;double price,disc_percent;
			int no_in_stock,no_sold,date;
			getline(readFile,name);getline(readFile,name);//>>name>>category>>barcode>>price>>manufacturer>>no_in_stock>>no_sold;
			getline(readFile,category);
			readFile>>barcode;
			readFile>>price;
			getline(readFile,manufacturer);getline(readFile,manufacturer);
			readFile>>no_in_stock;
			readFile>>no_sold;
			//string name1,double barcode1,double price1,string manufacturer1,int no_in_stock1,int no_sold1,string category1,int day1,int month1,int year1
			Product* newprod=new Product(name,barcode,price,manufacturer,no_in_stock,no_sold,category);
			add_item(newprod);
		}
	i++;
	}
readFile.close();
}

			
void product_manager::file_update()
{
	ofstream writeFile("batchdata.txt");
	int a=0;
	Product* retrieveprod;
	writeFile<<database->getsize()<<endl;
	while(a<(database->getsize()))
	{
		retrieveprod=database->retrieve(a);
		char test=retrieveprod->ifperishable();
		if(test==('y'))
		{
			writeFile<<"y"<<endl<<retrieveprod->getname()<<endl<<retrieveprod->get_category()<<endl<<retrieveprod->getbarcode()<<endl<<retrieveprod->getprice()<<endl<<retrieveprod->getmanufacturer()<<endl<<retrieveprod->getno_in_stock()<<endl<<retrieveprod->getno_sold()<<endl<<retrieveprod->returnexpiry()<<endl<<retrieveprod->getdisc_percent()<<endl;

		}
		else
		{
			writeFile<<"n"<<endl<<retrieveprod->getname()<<endl<<retrieveprod->get_category()<<endl<<retrieveprod->getbarcode()<<endl<<retrieveprod->getprice()<<endl<<retrieveprod->getmanufacturer()<<endl<<retrieveprod->getno_in_stock()<<endl<<retrieveprod->getno_sold()<<endl;			
		}
		a++;
	}
	writeFile.close();
}

void product_manager::revieve_feedback(string s, string t)
{
	ofstream writeFile("Feedback -"+t+".txt");
	writeFile<<s<<endl;
	writeFile.close();
}
			

	int	product_manager::findNextMax(Base* database, int max)
	{
		int nextmax=0;
		for (int i=0;i<database->getsize();i++)
		{
			Product* cur=database->retrieve(i);
			if (cur->getno_sold()>nextmax && cur->getno_sold()<max)
				nextmax=cur->getno_sold();
		}
		return nextmax;
	}
	void product_manager::topselling(int number)
	{
		int count=0, max=32767;
		UI ui;
		while (count<number)
		{
			max=findNextMax(database,max);
			for (int i=0;i<database->getsize();i++)
			{
				Product* cur=database->retrieve(i);
				if (cur->getno_sold()==max)
				{
					ui.printoutput(cur->getname());
					count++;
				}
			}
		}
	}
	double product_manager::highestselling()
	{
		double max=0;
		for (int i=0;i<database->getsize();i++)
		{
			double total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if (total>max)
				max=total;
		}
		return max;
	}
    void product_manager::bestselling()
	{
		UI ui;
		for (int i=0;i<database->getsize();i++)
		{
			double total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if (total==highestselling())
				ui.printoutput(database->retrieve(i)->getname());
		}
	}
	product_manager::~product_manager()
	{
		delete database;
	}
/*
  void bestmanufacturer(Base*); //print the manufacturer(s) whose products are highest-selling.
       int highest_incategory(Base*, string); //get the highest selling among products in a particular category
       void best_incategory(Base*, string); //print the product(s) with highest selling in a particular category
};
*/
	bool product_manager::is_in_vector(vector<string> v, string s)
	{
		for (int i=0;i<v.size();i++)
			if (v[i]==s) return true;
		return false;
	}

	vector<string> product_manager::bestmanufacturer()
	{
		double max=highestselling();
		vector<string> ans;
		for(int i=0;i<database->getsize();i++)
		{
			double total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if(max==total)
			{
				string temp=(database->retrieve(i))->getmanufacturer();
				if (!is_in_vector(ans,temp))
					ans.push_back(temp);
			}
		}
		return ans;
	}
	double product_manager::highest_incategory(string x)
	{
		
		double max=0,total=0;
		
		for (int i=0;i<database->getsize();i++)
		{
			if(database->retrieve(i)->get_category()==x)
			total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if (total>max && database->retrieve(i)->get_category()==x)
				max=total;
		}
		return max;
	}
	void product_manager::best_incategory(string x)
	{
		UI ui;
		double highest=highest_incategory(x);
		double total=0;
		for(int i=0;i<database->getsize();i++)
		{
			if(database->retrieve(i)->get_category()==x)
			total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if(database->retrieve(i)->get_category()==x && highest==total)
				ui.printoutput(database->retrieve(i)->getname());
		}
	}


	void product_manager::list_items()
	{
		int i;
		for(i=0;i<database->getsize();i++)
		{
			if(database->retrieve(i)->returnexpiry()==" ")
			{
				cout<<"Item name:"<<database->retrieve(i)->getname()<<endl;
				cout<<"Item price:"<<database->retrieve(i)->getprice()<<endl;
				cout<<"Item barcode:"<<(int)database->retrieve(i)->getbarcode()<<endl;
				cout<<"Item category:"<<database->retrieve(i)->get_category()<<endl;
				cout<<"Item manufacturer:"<<database->retrieve(i)->getmanufacturer()<<endl;
				cout<<"No. in stock:"<<database->retrieve(i)->getno_in_stock()<<endl;
				cout<<"No. sold this month:"<<database->retrieve(i)->getno_sold()<<endl;
				cout<<"*************************"<<endl;
			}
			else
			{
				cout<<"Item name:"<<database->retrieve(i)->getname()<<endl;
				cout<<"Item price:"<<database->retrieve(i)->getprice()<<endl;
				cout<<"Item barcode:"<<(int)database->retrieve(i)->getbarcode()<<endl;
				cout<<"Item category:"<<database->retrieve(i)->get_category()<<endl;
				cout<<"Item manufacturer:"<<database->retrieve(i)->getmanufacturer()<<endl;
				cout<<"No. in stock:"<<database->retrieve(i)->getno_in_stock()<<endl;
				cout<<"No. sold this month:"<<database->retrieve(i)->getno_sold()<<endl;
				cout<<"Expiry Date:"<<database->retrieve(i)->returnexpiry()<<endl;
				cout<<"discount percent:"<<database->retrieve(i)->getdisc_percent()<<endl;
				cout<<"*************************"<<endl;
			}
		}
	}
	bool product_manager::checkexpired(Product* pro)
	{
		time_t t=time(0);
		tm* now=localtime(&t);
		istringstream instr(search_barcode(pro->getbarcode())->returnexpiry());
		int day, now_day=now->tm_mday;int date;
		int month, now_month=now->tm_mon+1;
		int year, now_year=now->tm_year+1900;
		instr>>date;
		day=date/1000000;
		month=(date/10000)%100;
		year=date%10000;
		if (now_year<year||(now_year==year&&now_month<month)||(now_year==year&&now_month==month&&now_day<day))
			return false;
		return true;
	}
	void product_manager::checkexpired(string ncm)
	{
		double x;bool answer;
		vector<Product*> search_result=search_name(ncm);
		if(search_result.size()==0)
			vector<Product*> search_result=search_category(ncm);
		if(search_result.size()==0)
			vector<Product*> search_result=search_manufacturer(ncm);
		if(search_result.size()>=1)
		{
			if(search_result[0]->returnexpiry()!=" ")
			{
				answer=checkexpired(search_result[0]);
				UI ui;
				if(answer)
				{
					ui.printoutput("Product has Expired");
				}
				else
					ui.printoutput("Product has not Expired");
			}
		}
		else
		{
			UI ui;
			ui.printoutput("Enter barcode");
			x=ui.in_double();
			checkexpired(x);
		}
	}

	void product_manager::checkexpired(double barcode)
	{
		Product* ans=search_barcode(barcode);
		UI ui;
		if (ans!=NULL)
		if(ans->returnexpiry()!=" ")
		{
			bool answer=checkexpired(ans);
			if(answer)
			{
				ui.printoutput("Product has Expired");
			}
			else
				ui.printoutput("Product has not Expired");
		}
	}
	void product_manager::getjobs()
	{
		ifstream readfile("batchjobs.txt");
		int numuser;
		stack<user> tasklist;
		user user1;
		readfile>>numuser;
		bool result;
		for(int i=0;i<numuser;i++)
		{
			string user;
			getline(readfile,user);getline(readfile,user);
			user1.user_name=user;
			queue<task> list;
			int num2;
			readfile>>num2;
			task newtask;
			for(int j=0;j<num2;j++)
			{
				string taskname;
				getline(readfile,taskname);getline(readfile,taskname);
				if(taskname=="ADD")
				{
					string name,manufacturer,category;
					int barcode;double price,disc_percent;
					int no_in_stock;
					getline(readfile,name);//>>name>>category>>barcode>>price>>manufacturer>>no_in_stock>>no_sold;
					getline(readfile,category);
					readfile>>barcode;
					readfile>>price;
					getline(readfile,manufacturer);getline(readfile,manufacturer);
					readfile>>no_in_stock;
					Product newprod(name,barcode,price,manufacturer,no_in_stock,0,category);
					newtask.task_name=taskname;
					newtask.item=newprod;
				}
				else if(taskname=="DELETE")
				{
					double barcode;
					readfile>>barcode;
					Product newprod("",barcode,0,"",0,0,"");
					newtask.task_name=taskname;
					newtask.item=newprod;
				}
				else if(taskname=="RESTOCK")
				{
					double barcode;double number;
					readfile>>barcode;
					readfile>>number;
					Product newprod("",barcode,0,"",number,0,"");
					newtask.task_name=taskname;
					newtask.item=newprod;
				}
				else if(taskname=="DISPOSE")
				{
					double barcode;
					double expiry;
					readfile>>barcode;
					readfile>>expiry;
					Product newprod("",barcode,0,"",expiry,0,"");
					newtask.task_name=taskname;
					newtask.item=newprod;
				}
				else if(taskname=="SALE")
				{
					double barcode;double number;
					readfile>>barcode;
					readfile>>number;
					Product newprod("",barcode,0,"",number,0,"");
					newtask.task_name=taskname;
					newtask.item=newprod;
				}
				list.push(newtask);
			}
			user1.list=list;
			tasklist.push(user1);
		}
		dojobs(tasklist);
		readfile.close();
	}
	//above function updated with stack & queue
	bool product_manager::checkexpired(int barcode, int date)
	{
		Product* pro=search_barcode(barcode);
		if(pro!=NULL && pro->returnexpiry()!=" ")
		{
			istringstream os(pro->returnexpiry());
			int expiry;
			os>>expiry;
			int day=expiry/1000000;
			int month=(expiry/10000)%100;
			int year=expiry%10000;
			int now_day=date/1000000;
			int now_month=(date/10000)%100;
			int now_year=date%10000;
			if (now_year<year||(now_year==year&&now_month<month)||(now_year==year&&now_month==month&&now_day<day))
				return false;
			return true;
		}
		else
			return false;
	}
	void product_manager::dojobs(stack<user> userlist)
	{
		bool result;
		ofstream writefile("log.txt");
		int size=userlist.size();
		for(int k=0;k<size;k++)
		{
			int size2=(userlist.top()).list.size();
		for(int i=0;i<size2;i++)
		{
			result=false;
			if((userlist.top()).list.front().task_name=="ADD")
			{
				Product* newprop=new Product((userlist.top()).list.front().item.getname(),(userlist.top()).list.front().item.getbarcode(),(userlist.top()).list.front().item.getprice(),(userlist.top()).list.front().item.getmanufacturer(),(userlist.top()).list.front().item.getno_in_stock(),(userlist.top()).list.front().item.getno_sold(),(userlist.top()).list.front().item.get_category());
				result=add_item_user(newprop);
			}
			else if((userlist.top()).list.front().task_name=="DELETE")
			{
				result=delete_item((userlist.top()).list.front().item.getbarcode());
			}
			else if((userlist.top()).list.front().task_name=="RESTOCK")
			{
				result=restock((userlist.top()).list.front().item.getbarcode(),(userlist.top()).list.front().item.getno_in_stock());
			}
			else if((userlist.top()).list.front().task_name=="DISPOSE")
			{
				bool result1=checkexpired((userlist.top()).list.front().item.getbarcode(),(userlist.top()).list.front().item.getno_in_stock());
				if(result1)
				{
					result=reset_sales((userlist.top()).list.front().item.getbarcode());
				}
			}
			else if((userlist.top()).list.front().task_name=="SALE")
			{
				for(int j=0;i<(userlist.top()).list.front().item.getno_in_stock();i++)
				{	
					result=sale((userlist.top()).list.front().item.getbarcode());
					if(!result)
						break;
				}
			}
			if(!result)
			{
				writefile<<(int)(userlist.top()).list.front().item.getbarcode()<<" "<<(userlist.top()).list.front().task_name<<" "<<(userlist.top()).user_name<<endl;
			}
			userlist.top().list.pop();
		}
		userlist.pop();
		}
		writefile.close();
	}

