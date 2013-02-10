#ifndef CIRCULAR_DOUBLE_LIST
#define CIRCULAR_DOUBLE_LIST
#include "Base.h"

class circular_double_list: public Base{
private:
	struct object{
		Product* item;
		object* next;
		object* prev;
	};
	object* head;
	int size;

	object* traverse(Product*); //traverse to a particular product
public:
	circular_double_list(): head(NULL), size(0){}
	~circular_double_list();

	Product* retrieve(int);
	int getsize(){return size;}
	void add(Product*);
	void scrap(Product*);
};
#endif