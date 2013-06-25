// ReadWrite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"		// precompiled stuffs so that compiling doesn't start from scratch everytime.
#include <iostream>		// header that defines the standard input/output stream objects
#include <fstream>		// stream class to both read and write from/to files.
using namespace std;

int _tmain(int argc, const char* argv[])
{
	ofstream myfile;	// ofstream is a class to write on files
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	return 0;
}

