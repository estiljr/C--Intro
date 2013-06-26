// GridToXYZ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <string>
using namespace std;

int _tmain(int argc, const char* argv[])
{
	//ifstream inputFile ("C:\\Users\\Bebom\\Desktop\\testReadWrite.txt");
	ifstream inputFile (argv[1]);
	cout << inputFile << endl;
	string line[6], LineQuery[6];
	if (inputFile.is_open()){
		for (int x = 0; x <= 5; x++){
			getline(inputFile,line[x]);											//getline(object from which characters are extracted, object where the extracted line is stored)
			unsigned spacePosition = line[x].find("\t");
			LineQuery[x] = line[x].substr(spacePosition);
		}
			int ncols = atoi(LineQuery[0].c_str()); 
			int nrows = atoi(LineQuery[1].c_str()); 
			int xllcorner = atoi(LineQuery[2].c_str()); 
			int yllcorner = atoi(LineQuery[3].c_str());
			int dx = atoi(LineQuery[4].c_str());
			cout << "ncols: "<< ncols<< endl; 
			cout << "nrows: " << nrows << endl; 
			cout << "xllcorner: " << xllcorner << endl; 
			cout << "yllcorner: " << yllcorner << endl;
			cout << "cellsize: " << dx << endl;
			inputFile.close();
	}
	else cout << "The input file is not open!";
	_getch();
	return 0;
	
}

