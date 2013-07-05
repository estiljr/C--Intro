#include <stdafx.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
using namespace std;

struct Student_info
{
	string name;
	double midterm_exam, final_exam;
	vector<double> homework;
};

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


istream& read(istream& istrm, Student_info& student)
{
	// read and store the student's name and midterm and final exam grades
	istrm >> student.name >> student.midterm_exam >> student.final_exam;

	// read and store all the student's homework grades
	read_hw(istrm,student.homework);

	return istrm;
}

double grade(const Student_info& stud)
{
	return grade(stud.midterm_exam, stud.final_exam, stud.homework);
}

bool compare (const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the records, and find the length of the longest name
	while (read(cin, record))
	{
		maxlen = max(maxlen,record.name.size());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);

	for(vector<Student_info>::size_type i=0; i!=students.size(); ++i){
		try{
			// compute the final grade
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();

			// write the name, padded on the right to maxlen + 5 characters
			cout << students[i].name 
				<< string(maxlen + 5 - students[i].name.size(), ' ') << setprecision(3) 
				<< final_grade << setprecision(prec) << endl;
		} catch(domain_error e){
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}