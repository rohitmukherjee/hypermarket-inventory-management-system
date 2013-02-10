#ifndef UI_INPUT_H
#define UI_INPUT_H
#include <iostream>
#include <string>
using namespace std;
class ui_input
{
public:
	int in_int();
	double in_double();
	string in_string();
	char in_char();
	long in_long();
};
#endif