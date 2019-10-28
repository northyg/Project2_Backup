/**********/
// Author: Giselle Northy
// Date: 10/28/2019
// Class Number: CS260
// Program Number: Project 2
// Purpose: Restaurant waiting list program that keeps track of guest list in a queue and if a customer wants promotional material, the program pushes names to the stack
// Name and Purpose of this file: project2.cpp, this serves as the main testing file for the project
/**********/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "stack.h"

#define MYFILE "promo.txt"
#define MAX_CHAR 101

using namespace std;

void loadFile(const char* filename, 

int main()
{
	SomeClass someClass;

	loadFile(MYFILE, SomeClass someClass);
	
	return 0;
}	



// Functiion works on a file expecting unix style new line characters ('\n')
void loadFile(const char* filename, SomeClass someClass)
{
	// Loads the file - open file to read in data
	ifstream inputFile;
	inputFile.open(filename);
	if(inputFile.is_open())
	{
		cout << "Welcome to Waiting list... Successfully opened " << filename << endl;
		loadQUEUE thing(inputFile, SomeClass someClass);
	{
	else
	}
		cout << "Error, could not open file " << filename << " for reading.\n";
	}
}	// END loaded file	




// Writes array data to an external text file
void writeInfo(ofstream & outputFile)
{
        outputFile
}



