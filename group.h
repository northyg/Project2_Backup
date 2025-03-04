/**********/
// Author: Giselle Northy
// Date: 10/28/2019
// Class Number: CS260
// Program Number: Project 2
// Purpose: Restaurant waiting list program that keeps track of guest list in a queue and if a customer wants promotional material, the program pushes names to the stack
// Name and Purpose of this file: group.h
/**********/

#ifndef GROUP_H
#define GROUP_H

class Group
{
public:
        Group(char* name, int size, bool accom, char* accomDetails);
        ~Group();

        char* getName(); // gets the party name
        int getSize(); // gets the party size
        bool getAccom(); // yes or no if party needs accomadations
        char* getAccomDetails(); // get special instructions. only needed if getAccom = true

private:
        char* name; // name of the group/party
        int size; // size of the party
        bool accom; // accomodations yes or no
        char* accomDetails; // special instructions
};

#endif
