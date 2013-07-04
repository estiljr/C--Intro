#include <stdafx.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{dz
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double median, final;
	cin >> median >> final;

	// ask for and read the homework grades
	cout << "Enter all your homework grades, "
		"and write end at the end: ";
	
	double x;
	vector <double> homework;

	//invariant: homework contains all the homework grades read so far
	while (cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	return 0;
}