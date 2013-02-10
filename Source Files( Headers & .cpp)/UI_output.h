#include "Product.h"
#include "database.h"
#include "Perishable.h"
class UI_output{
public:UI_output();
	void print_menu_footer();
	void get_name_string();
	void get_product_details();
	void print_error();
	void printoutput(string a);
};
