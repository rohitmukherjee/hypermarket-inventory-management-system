#include "databasebase.h"
#include "product_manager.h"
#include "Product.h"
#include "Perishable.h"
	
	int	product_manager::findNextMax(Base* databasebase, int max)
	{
		int nextmax=0;
		for (int i=0;i<database.getsize();i++)
		{
			Product* cur=database.getProduct(i);
			if (cur->getno_sold()>nextmax && cur->getno_sold()<max)
				nextmax=cur->getno_sold();
		}
		return nextmax;
	}
	void product_manager::topselling(int number, Base* database)
	{
		int count=0, max=32767;
		while (count<number)
		{
			max=findNextMax(database,max);
			for (int i=0;i<database.getsize();i++)
			{
				Product* cur=database.getProduct(i);
				if (cur->getno_sold()==max)
				{
					cout<<cur->getname()<<endl;
					count++;
				}
			}
		}
	}
	int product_manager::highestselling(Base* database)
	{
		int max=0;
		for (int i=0;i<database.getsize();i++)
		{
			int total=database.getProduct(i)->getno_sold()*database.getProduct(i)->getprice();
			if (total>max)
				max=total;
		}
		return max;
	}
    void product_manager::bestselling(Base* database)
	{
		for (int i=0;i<database.getsize();i++)
		{
			int total=database.getProduct(i)->getno_sold()*database.getProduct(i)->getprice();
			if (total==highestselling(database))
				cout<<database.getProduct(i)->getname()<<endl;
		}
	}

