#ifndef GENERATE_STATISTICS_H
#define GENERATE_STATISTICS_H
#include "database.h"
#include <string>
#include <vector>
class generate_statistics
{
private:
	int findNextMax(Base* data, int max); //find highest no of selling that is lower than max
public:
	void topselling(int number, Base* data); //if many products have the same no of sold, print all
	int highestselling(Base*); //get highest selling
    void bestselling(Base*); //print product(s) with highest selling
	void bestmanufacturer(Base*); //print the manufacturer(s) whose products are highest-selling.
	int highest_incategory(Base*, string); //get the highest selling among products in a particular category
	void best_incategory(Base*, string); //print the product(s) with highest selling in a particular category
};
#endif