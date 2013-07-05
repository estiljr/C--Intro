// chapter04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exams grade: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Please enter your homework scores followed by 'end': ";
	vector<double> homework;
	read_hm();
	return 0;
}

istream& read_hm(istream& input, vector<double>& hw)
{
	double x;
	while(input)
		input >> x;
	
}
