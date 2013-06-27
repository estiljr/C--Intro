// GridToXYZ.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char* argv[])
{
	ifstream inputFile(argv[1]);
	ofstream outputFile("GridtoXYZ_output.csv");

	string line[6], LineQuery[6];
	if (inputFile.is_open()){
		for (int x = 0; x <= 5; x++){
			getline(inputFile,line[x]);											//getline(object from which characters are extracted, object where the extracted line is stored)
			unsigned spacePosition = line[x].find(" ");
			LineQuery[x] = line[x].substr(spacePosition);
		}
		const int ncols = atoi(LineQuery[0].c_str()); 
		const int nrows = atoi(LineQuery[1].c_str()); 
		double xllcorner = atof(LineQuery[2].c_str()); 
		double yllcorner = atof(LineQuery[3].c_str());
		double dx = atof(LineQuery[4].c_str());
		int nodata = atoi(LineQuery[5].c_str());
		outputFile << "ncols ,"<< ncols<< "\n";					cout << "ncols: "<< ncols<< "\n"; 
		outputFile << "nrows ," << nrows << "\n";				cout << "nrows: " << nrows << "\n"; 
		outputFile << "xllcorner ," << xllcorner << "\n";		cout << "xllcorner: " << xllcorner << "\n";
		outputFile << "yllcorner ," << yllcorner << "\n";		cout << "yllcorner: " << yllcorner << "\n";
		outputFile << "cellsize ," << dx << "\n";				cout << "cellsize: " << dx << "\n";
		outputFile << "nodata ," << nodata << "\n";				cout << "nodata: " << nodata << "\n";
		outputFile << "i-index ,"<<"j-index ,"<<"x ,"<<"y ,"<<"z"<<"\n";
		cout<<"Reading input Grid file..."<<"\n";

		string** arr = new string*[nrows];
		for(int a = 0; a < nrows; a++)
			arr[a] = new string[ncols];
		double* x = new double[nrows];
		double* y = new double[ncols];
		int* i_index = new int[nrows];
		int* j_index = new int[ncols];

		for (int i = nrows-1; i >=0; i--){
			for (int j = 0; j < ncols; j++){
				if (j==ncols -1)
					getline(inputFile,arr[i][j],'\n');
				else
					getline(inputFile,arr[i][j],' ');
			}
		} 

		cout << "Converting Grid to XYZ..." << "\n";
		for (int m = 0; m < nrows; m++){
			for(int n = 0; n < ncols; n++){
				x[n] = xllcorner + dx*n + 0.5*dx;
				y[m] = yllcorner + dx*m + 0.5*dx;
				j_index[n] = 1+n;
				i_index[m] = 1+m;
				outputFile.precision(10);
				outputFile<<i_index[m]<<','<<j_index[n]<<','<<x[n]<<','<<y[m]<<','<<arr[m][n]<<'\n';
			}
		}

		cout<<"Deallocating memory..."<< "\n";
		for (int i = 0; i < nrows; i++)
			delete [] arr[i];
		delete [] arr; //delete [] x; delete [] y;
		inputFile.close();
		outputFile.close();
	}
	else cout << "The input file is not open!";
	cout << "Process complete! Press any key to continue..." << "\n";
	_getch();
	return 0;
}

