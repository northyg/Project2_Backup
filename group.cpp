/**********/
// Author: Giselle Northy
// Date: 10/28/2019
// Class Number: CS260
// Program Number: Project 2
// Purpose: Restaurant waiting list program that keeps track of guest list in a queue and if a customer wants promotional material, the program pushes names to the stack
// Name and Purpose of this file: group.cpp
/**********/

#include <cstdlib>
#include <cstring>
#include "group.h"



// Constructor
Group::Group(char* aName, int aSize, bool aAccom, char* aAccomDetails)
{
	name = strdup(aName);
	size = aSize;
	accom = aAccom;
	if (accom == true)
	{
		accomDetails = strdup(aAccomDetails);
	}
	else
	{
		accomDetails = nullptr;
	}
}



// Default destructor
Group::~Group()
{
	free(name);
	if(accom == true)
	{
		free(accomDetails);
	}
}


// Function for get name gets the party full name
char* Group::getName()
{
	return name;
}


// Function gets the party size
int Group::getSize()
{
	return size;
}


// Function returns accom which will be true or false
bool Group::getAccom()
{
	return accom;
}


// Function get accomdetails will return the char array of group accomidations
// or nullptr if accom is false
char* Group::getAccomDetails()
{
	return accomDetails;
}
