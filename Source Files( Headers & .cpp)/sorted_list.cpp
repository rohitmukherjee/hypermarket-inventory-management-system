#include "sorted_list.h"
#include <ctime>

sorted_list::~sorted_list()
{
	while (head!=NULL)
	{
		ListNode* cur=head;
		head=head->next;
		delete cur;
	}
}

Product* sorted_list::retrieve(int index)
{
	if (index>=size || index<0)
		return NULL;
	ListNode* cur=head;
	for (int i=0;i<index;i++)
		cur=cur->next;
	return cur->item;
}

void sorted_list::add(Product* pro)
{
	ListNode* newNode=new ListNode;
	newNode->item=pro;
	newNode->next=NULL;
	if (head==NULL || pro->getbarcode()<head->item->getbarcode())
	{
		newNode->next=head;
		head=newNode;
		size++;
		return;
	}
	ListNode* cur=head;
	while (cur->next!=NULL && cur->next->item->getbarcode()<pro->getbarcode())
		cur=cur->next;
	newNode->next=cur->next;
	cur->next=newNode;
	size++;
}

void sorted_list::scrap(Product* pro)
{
	ListNode* cur=head;

	//delete the first item
	if (pro->getbarcode()==head->item->getbarcode())
	{
		head=head->next;
		delete cur;
		size--;
		return;
	}

	//delete at other positions
	while (cur->next!=NULL && cur->next->item->getbarcode()!=pro->getbarcode())
		cur=cur->next;
	if (cur->next!=NULL)
	{
		ListNode* temp=cur->next;
		cur->next=cur->next->next;
		delete temp;
		size--;
	}
}

sorted_list::ListNode* sorted_list::traverse(Product* pro)
{
	ListNode* cur=head;
	while (cur!=NULL)
	{
		if (cur->item->getbarcode()==pro->getbarcode())
			return cur;
		cur=cur->next;
	}
	return false;
}

void sorted_list::reset_no_sold(Product* pro)
{
	traverse(pro)->item->reset();
}

void sorted_list::sale(Product* pro, int num)
{
	traverse(pro)->item->sell(num);
}

void sorted_list::restock(Product* pro, int num)
{
	traverse(pro)->item->restock(num);
}

bool sorted_list::check_expired(Product* pro)
{
	time_t t=time(0);
	tm* now=localtime(&t);
	istringstream instr(traverse(pro)->item->returnexpiry());
	int day, now_day=now->tm_mday;int date;
	int month, now_month=now->tm_mon+1;
	int year, now_year=now->tm_year+1900;
	instr>>date;
	day=date/1000000;
	month=(date/10000)%100;
	year=date%10000;
	if (now_year<year||(now_year==year&&now_month<month)||(now_year==year&&now_month==month&&now_day<day))
		return false;
	return true;
}

vector<Product*> sorted_list::search_name(string name)
{
	vector<Product*> ans;
	ListNode* cur=head;
	while (cur!=NULL)
	{
		if (cur->item->getname()==name)
			ans.push_back(cur->item);
		cur=cur->next;
	}
	return ans;
}
vector<Product*> sorted_list::search_category(string cate)
{
	vector<Product*> ans;
	ListNode* cur=head;
	while (cur!=NULL)
	{
		if (cur->item->get_category()==cate)
			ans.push_back(cur->item);
		cur=cur->next;
	}
	return ans;
}
vector<Product*> sorted_list::search_manufacturer(string manu)
{
	vector<Product*> ans;
	ListNode* cur=head;
	while (cur!=NULL)
	{
		if (cur->item->getmanufacturer()==manu)
			ans.push_back(cur->item);
		cur=cur->next;
	}
	return ans;
}
Product* sorted_list::search_barcode(double barcode)
{
	ListNode* cur=head;
	while (cur!=NULL)
	{
		if (cur->item->getbarcode()==barcode)
			return cur->item;
		cur=cur->next;
	}
	return NULL;
}
