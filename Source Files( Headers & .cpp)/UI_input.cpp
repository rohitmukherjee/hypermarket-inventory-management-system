#include "UI_input.h"
	int ui_input::in_int()
	{
		int a;
		cin>>a;
		return a;
	}
	double ui_input::in_double()
	{
		double a;
		cin>>a;
		return a;
	}
	string ui_input::in_string()
	{
		getchar();
		string a;
		getline(cin,a);
		return a;
	}
	char ui_input::in_char()
	{
		char a;
		cin>>a;
		return a;
	}
	long ui_input::in_long()
	{
		long a;
		cin>>a;
		return a;
	}