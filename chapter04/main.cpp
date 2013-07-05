#include <stdafx.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "Student_info.h"
#include "grade.h"
using namespace std;

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
	}
	cout << endl;
	return 0;
}