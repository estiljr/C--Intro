// chapter02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
using std::cin;	using std::endl;
using std::cout;	using std::string;

int main()
{
	// ask for the person's name
	std::cout << "Please enter your first name: ";
	
	// read the name
	std::string name;
	std::cin >> name;

	// build the message that we intend to write
	const std::string greeting = "Hello, "+name+"!";
	
	// the number of blanks surrounding the greetings
	const int pad = 5;

	// total number of rows and columns to write:
	const int rows = pad * 2 + 3;
	const string::size_type cols = 2 + pad*2 + greeting.size();

	// write a blank line to separate the output from the input
	cout << endl;

	// write rows rows of input
	// invariant: we have written r rows so far
	for (int r=0; r!=rows; ++r){
		string::size_type c = 0;
		//invariant: we have written c characters so far in the current row
		while(c != cols){
			// is it time to write the greeting?
			if (r == pad+1 && c == pad+1){
				cout<<greeting;
				c += greeting.size()-1; 
			// are we in the border?
			} 
			else if (r == 0 || r == rows-1 || c == 0 || c == cols-1){
				cout<<"*";
			} 
			else cout<<" ";
		++c;
		}
		cout<<endl;
	}
	_getch();
	return 0;
}

