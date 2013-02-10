#include "dynamicArray.h"
#include <sstream>
#include <ctime>

dynamicArray::~dynamicArray()
{
	for (int i=0;i<size;i++)
		delete arr[i];
	delete[max_size]arr;
}

Product* dynamicArray::retrieve(int index)
{
	if (index<0 || index>=size)
		return NULL;
	return arr[index];
}

void dynamicArray::grow()
{
	Product** temp=new Product*[max_size*2];
	for (int i=0;i<max_size;i++)
		temp[i]=arr[i];
	for (int i=max_size;i<(max_size*2);i++)
		temp[i]=NULL;
	
	delete[max_size]arr;
	
	arr=new Product*[max_size*2];
	for (int i=0;i<max_size*2;i++)
		arr[i]=temp[i];
	delete[max_size*2]temp;
	max_size*=2;
}

void dynamicArray::add(Product* pro)
{
	if (size==max_size)
		grow();
	arr[size]=pro;
	size++;
}

int dynamicArray::getIndex(Product* pro)
{
	int i;
	for (int i=0;i<size;i++)
		if (arr[i]->getbarcode()==pro->getbarcode())
			return i;
	return -1;
}

void dynamicArray::scrap(Product* pro)
{
	int index=getIndex(pro);
	if (index!=-1)
	{
		delete arr[index];
		for (int i=index;i<size-1;i++)
			arr[i]=arr[i+1];
		arr[size-1]=NULL;
		size--;
	}
}
