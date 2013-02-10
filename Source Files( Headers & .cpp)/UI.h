#include <iostream>
#include <string>
#include <vector>
using namespace std;
class UI
{
public:
	UI(){};
	int in_int();
	double in_double();
	string in_string();
	char in_char();
	long in_long();
	void print_menu_footer();
	void get_name_string();
	void get_product_details();
	void print_error();
	void printoutput(string a);
	void printoutput(vector<string> a);
	void print_menu();
	void header_text();
	void print_stats_menu();
	void confirm_perishable();
	void get_perishable_details();
	void getcontinue();
};