#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include "Product.h"
#include "Base.h"
#include <vector>

class sorted_list: public Base{   //sort by barcode
private:
	struct ListNode{
		Product* item;
		ListNode* next;
	};

	ListNode* head;
	int size;
	ListNode* traverse(Product*);
public:
	sorted_list(): head(NULL),size(0){}
	~sorted_list();

	Product* retrieve(int);
	int getsize() {return size;}
	void add(Product*);
	void scrap(Product*);
	void reset_no_sold(Product*);
	void sale(Product*, int);
	void restock(Product*, int );
	bool check_expired(Product*);
	vector<Product*> search_name(string);
	vector<Product*> search_category(string);
	vector<Product*> search_manufacturer(string);
	Product* search_barcode(double);
};

#endif;