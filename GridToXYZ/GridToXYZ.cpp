// GridToXYZ.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
//#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	ifstream input(argv[1]);
	ofstream output("GridtoXYZ_output.csv");

	int ncols, nrows, i_index, j_index;
	double xll, yll, dx, nodata, val, x, y;
	char nan[20];

	if (input.is_open()){
		input>>nan;		cout<<endl;
		input>>ncols;	cout<<"ncols: "<<ncols<<endl;			output<<"ncols ,"<<ncols<<endl;
		input>>nan;
		input>>nrows;	cout<<"nrows: "<<nrows<<endl;			output<<"nrows ,"<<nrows<<endl;
		input>>nan;
		input>>xll;		cout<<"xllcorner: "<<xll<<endl;			output<<"xllcorner ,"<<xll<<endl;
		input>>nan;
		input>>yll;		cout<<"yllcorner: "<<yll<<endl;			output<<"yllcorner ,"<<yll<<endl;
		input>>nan;
		input>>dx;		cout<<"cellsize: "<<dx<<endl;			output<<"cellsize ,"<<dx<<endl;
		input>>nan;
		input>>nodata;	cout<<"nodata_value: "<<nodata<<endl;	output<<"nodata_value ,"<<nodata<<endl;

		double** z = new double*[nrows];
		for (int i=0; i<nrows; i++)
			z[i] = new double[ncols];

		output<<"i-index,j-index,x,y,z"<<endl; cout<<endl;
		cout<<"Reading input Grid file..."<<endl;
		for (int i=nrows-1; i>=0; i--){
			for(int j=0; j<ncols; j++){
				input>>val;
				z[i][j] = val;
			}
		}
		cout << "Converting Grid to XYZ..." <<endl;
		for (int i=0; i<nrows; i++){
			for (int j=0; j<ncols; j++){
				x = xll + dx*j + dx*0.5;
				y = yll + dx*i + dx*0.5;
				i_index = 1+i;
				j_index = 1+j;
				output<< i_index <<","<< j_index <<","<< x << ","<< y <<","<< z[i][j] <<endl;
			}
		}
		delete [] z;
		input.close();
		output.close();
	}
	else cout << "Input file not loaded!";
	cout << "Process complete! Press any key to continue..." << endl;	
	_getch();
	return 0;
	
}

