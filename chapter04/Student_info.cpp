// source file for Student_info-related functions
#include <stdafx.h>
#include "Student_info.h"
using namespace std;

bool compare (const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& istrm, Student_info& student)
{
	// read and store the student's name and midterm and final exam grades
	istrm >> student.name >> student.midterm_exam >> student.final_exam;

	// read and store all the student's homework grades
	read_hw(istrm,student.homework);

	return istrm;
}

// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& input, vector<double>& hw)
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

