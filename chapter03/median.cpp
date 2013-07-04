#include <stdafx.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double medterm, final;
	cin >> medterm >> final;

	// ask for and read the homework grades
	cout << "Enter all your homework grades, "
		"and write 'end' at the end: ";
	
	double x;
	vector <double> homework;
	// invariant: homework contains all the homework grades read so far
	while (cin >> x)
		homework.push_back(x);

	// check that the student entered some homework grades
	typedef vector<double>::size_type vector_size;
	vector_size size = homework.size();
	if (size == 0){
		cout << endl << "You must enter your grades. " 
			"Please try again." << endl;
		return 1;
	}

	// sort the grades
	sort(homework.begin(), homework.end());

	// compute the median homework grade
	vector_size mid = size/2;
	double median = size % 2 == 0 ? (homework[mid]+homework[mid-1])/2 : homework[mid];
	cout << "Your median score is " << median << endl;

	// compute and write the final grade
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2*medterm + 0.4*final + 0.4*median 
		<< setprecision(prec) << endl << endl;;

	return 0;
}