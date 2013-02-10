#include "vector_version.h"
#include <ctime>
#include <sstream>

vector_version::~vector_version()
{
	while (!vtr.empty())
	{
		delete vtr.back();
		vtr.pop_back();
	}
}

void vector_version::add(Product* pro)
{
	vtr.push_back(pro);
}

void vector_version::scrap(Product* pro)
{
	for (int i=0;i<vtr.size();i++)
		if (vtr[i]->getbarcode()==pro->getbarcode())
		{
			delete vtr[i];
			for (int j=i;j<vtr.size()-1;j++)
				vtr[j]=vtr[j+1];
			vtr.pop_back();
		}
}

