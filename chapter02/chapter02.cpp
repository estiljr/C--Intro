// chapter02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//asks for the person's name
	std::cout << "Please enter your first name: ";
	
	//read the name
	std::string name;
	std::cin >> name;

	//build the message that we intend to write
	const std::string greeting = "Hello, "+name+"!";
	
	//the number of blanks surrounding the greetings
	const int pad = 1;

	//total number of rows to write:
	const int rows = pad * 2 + 3;

	std::cout << std::endl;
	int r = 0;

	while (r != rows)
	{
		std::cout << std::endl;
		++r;
	}
	
	//std::cout<< greeting;
	//_getch();

	return 0;

}

