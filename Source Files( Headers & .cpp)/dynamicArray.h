#ifndef DYNAMICARRAY_DATABASE_H
#define DYNAMICARRAY_DATABASE_H
#include "Base.h"

class dynamicArray:public Base{
private:
	Product** arr;
	int max_size, size;

	void grow(); 
	int getIndex(Product* pro);
public:
	dynamicArray():max_size(10),size(0)
	{
		arr=new Product*[max_size];
	}
	~dynamicArray();

	Product* retrieve(int);
	int getsize(){return size;}
	void add(Product*);
	void scrap(Product*);
};

#endif