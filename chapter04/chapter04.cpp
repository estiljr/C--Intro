// chapter04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// read homework grades from an input stream into a `vector<double>'
istream& read_hm(istream& input, vector<double>& hw)
{
	if(input){
		// get rid of previous contents
		hw.clear();		

		// read homework grades
		double x;				
		while(input >> x)								
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		input.clear();									
	}
	return input;
}

// compute the median of a `vector<double>'
// note that calling this function copies the entire argument `vector'
double get_median(vector<double> vec)
{
	typedef vector<double>::size_type vec_size;
	vec_size size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());
	vec_size mid = size/2;
		
	return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, get_median(hw));
}



int main()
{
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exams grade: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Please enter all your homework scores followed by 'end': ";

	vector<double> homework;

	// read the homework grades
	read_hm(cin, homework);

	// compute and generate the final grade, if possible
	try{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is: " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch(domain_error){
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}

	return 0;
}


