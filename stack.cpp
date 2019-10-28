/**********/
// Author: Giselle Northy
// Date: 10/28/2019
// Class Number: CS260
// Program Number: Project 2
// Purpose: Restaurant waiting list program that keeps track of guest list in a queue and if a customer wants promotional material, the program pushes names to the stack
// Name and Purpose of this file: stack.cpp
/**********/

#include "stack.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


// Constructor for Stack which has an initial size, and count starts at 0 
Stack::Stack()
{
	currCapacity = INITIAL_CAP;
	aStack = new Person*[currCapacity];
	count = 0;
}



// Destructor for the array elements
Stack::~Stack()
{
	for(int i = 0; i < count; i++)
	{ 
		delete aStack[i];
	}
	delete[] aStack;
}



// Push elements onto stack and call growStack if count = currCapacity
void Stack::push(Person* aPerson)
{
	if (count == currCapacity)
	{
		growStack();
	}
	aStack[count] = aPerson;
	count++;
}



// Pops char array name & email off stack to be written to file
bool Stack::pop(Person& aPerson)
{
	if(count != 0)
	{
		aPerson = *(aStack[count - 1]);
		delete aStack[count - 1];
		count--;
		return true;
	}
	return false;
}



// Peek shows the name of what is on the top of the stack
bool Stack::peek(Person *& aPerson)
{
	if (count != 0)
	{
		aPerson = aStack[count - 1];
		return true;
	}
	return false;
}



// Shows the contents of the promo array - full name, email 
void Stack::display()
{
	for (int i = 0; i < count; i++)
	{
		cout << aStack[i]->fullName << " " << aStack[i]->email << endl;
	}
}



// Grows the stack size when the array gets full
void Stack::growStack()
{
	currCapacity *= GROWTH_VALUE;
	Person ** tempStack = new Person*[currCapacity];
	for (int i = 0; i < count; i++)
	{
		tempStack[i] = aStack[i];
	}
	delete[] aStack;
	aStack = tempStack;
	tempStack = nullptr;
}



/**Writes array data to an external text file
void writeInfo(ofstream & outputFile)
{
	outputFile
}
**/ // might not need this here



