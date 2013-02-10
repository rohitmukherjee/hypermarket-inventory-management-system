
#ifndef PRODUCT_MANAGER
#define PRODUCT_MANAGER
#include "Base.h"
#include <queue>
#include <stack>

class product_manager{
	
private: 
	Base* database;

	//private function for basic functionality
	bool checkexpired(Product*);

	//private function for generating statistics
	int findNextMax(Base* data, int max); //find highest no of selling that is lower than max
	bool is_in_vector(vector<string>,string);

	//private structures for doing jobs using stack and queues
	struct task{
		Product item;
		string task_name;
	};
	struct user
	{
		queue<task> list;
		string user_name;
	};
	
public:
	
product_manager();
~product_manager();
	
	
	//basic list operations
	bool add_item(Product* );
	bool add_item_user(Product*);
	
	bool delete_item(string ncm);//this delete_item deletes item by matching input string against Product name,Manufacturer or Category.
	
	bool delete_item(double barcode);//overloaded function deleting using barcode

	bool sale(string ncm);
	bool sale(double barcode);
	bool restock(string ncm,int number);
	bool restock(double barcode,int number);
	bool reset_sales(string ncm);
	bool reset_sales(double barcode);
	void list_items();
	void checkexpired(string);
	void checkexpired(double);
	bool checkexpired(int,int);
	
	vector<Product*> search_name(string);
	vector<Product*> search_category(string);
	vector<Product*> search_manufacturer(string);
	Product* search_barcode(double);
	//file operations
	void list_initialize(string a);
	void file_update();
	void revieve_feedback(string s, string t);
	
	//batch-processing
	void getjobs();
	void dojobs(stack<user>);
	

	//the below functions are taken from original generate_statistics.h
	void topselling(int number); //if many products have the same no of sold, print all
	double highestselling(); //get highest selling
    void bestselling(); //print product(s) with highest selling
	vector<string> bestmanufacturer(); //print the manufacturer(s) whose products are highest-selling.
	double highest_incategory( string); //get the highest selling among products in a particular category
	void best_incategory(string); //print the product(s) with highest selling in a particular category
};
#endif

