#ifndef BASE_H
#define BASE_H
#include "Product.h"
#include "Perishable.h"
#include <vector>
#include <cmath>

class Base  //store the products
{
public:
	virtual Product* retrieve(int)=0;
	virtual int getsize()=0;
	virtual void add(Product*)=0;
		virtual void scrap(Product*)=0;
};

#endif;