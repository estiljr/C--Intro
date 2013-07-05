// source file for the median function
#include <stdafx.h>
#include <algorithm>
#include <vector>
using namespace std;

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