// ask for a person's name, and greet the person
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

int main()
{
	// ask for the person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;     // define `name'
	std::cin >> name;     // read into `name'

	// write a greeting
	std::cout << "Hello, " << name  << "!" << std::endl;
	_getch();
	return 0;
}
