#ifndef VECTOR_VERSION_H
#define VECTOR_VERSION_H
#include "Base.h"

class vector_version:public Base{
private:
	vector<Product*> vtr;
public:
	~vector_version();

	Product* retrieve(int index) {return vtr[index];}
	int getsize() {return vtr.size();}
	void add(Product*);
	void scrap(Product*);	
};

#endif;