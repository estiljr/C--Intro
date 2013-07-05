#include <stdafx.h>
#include "grade.h"
#include "median.h"
#include <stdexcept>
using namespace std;

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

double grade(const Student_info& stud)
{
	return grade(stud.midterm_exam, stud.final_exam, stud.homework);
}