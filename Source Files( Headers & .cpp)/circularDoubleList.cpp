#include "circularDoubleList.h"
#include <vector>
#include <ctime>
#include <sstream>

circular_double_list::~circular_double_list()
{
	if (head==NULL)
		return;
	while (head->next!=head)
	{
		object* cur=head;
		head=head->next;
		head->prev=cur->prev;
		cur->prev->next=head;
		delete cur->item;
		delete cur;
	}
	delete head->item;
	delete head;
}

circular_double_list::object* circular_double_list::traverse(Product* pro)
{
	object* cur=head;
	do{
		if (cur->item->getbarcode()==pro->getbarcode())
			return cur;
		cur=cur->next;
	} while(cur!=head);
	return NULL;
}

Product* circular_double_list::retrieve(int index)
{
	object* cur=head;
	for (int i=0;i<index;i++)
		cur=cur->next;
	return cur->item;
}

void circular_double_list::add(Product* pro)
{
	//create a new object
	object* cur=new object;
	cur->item=pro;
	cur->next=NULL;
	cur->prev=NULL;

	//case empty list
	if (head==NULL)
	{
		cur->next=cur;
		cur->prev=cur;
	}

	//otherwise: insert to the begining of the list
	else
	{
		cur->next=head;
		cur->prev=head->prev;
		head->prev->next=cur;
		head->prev=cur;
	}

	//update head and size
	head=cur;
	size++;
}

void circular_double_list::scrap(Product* pro)
{
	object* cur=traverse(pro);
	if (cur==head)
		head=cur->next;
	cur->prev->next=cur->next;
	cur->next->prev=cur->prev;
	delete cur->item;
	delete cur;
	size--;
	if (size==0)
		head=NULL;
}
