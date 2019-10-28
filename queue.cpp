/**********/
// Author: Giselle Northy
// Date: 10/28/2019
// Class Number: CS260
// Program Number: Project 2
// Purpose: Restaurant waiting list program that keeps track of guest list in a queue and if a customer wants promotional material, the program pushes names to the stack
// Name and Purpose of this file: queue.cpp
/**********/

#include "queue.h"

// Constructor function initializes front and rear ptrs to null and size to 0
Queue::Queue(): front(nullptr), rear(nullptr), size(0)
{
}



// Destructor function destroys front and rear ptrs and sets to null
Queue::~Queue()
{
	destroy(front);
	front = nullptr;
	rear = nullptr;
}



// Destroy Recursive function destroys nodes and burninates villages
void Queue::destroy(Node *& currHead)
{
	if(currHead->next != front)
	{
		destroy(currHead->next);
		delete currHead->data; // is data the correct thing here?
		delete currHead;
	}
}



// Enqueue function sets the people pointers
// The queue should be implemented using a circular linked list of people, where the rear pointer points to the most recent group to arrive at the restaurant, and rear->next points to the first group to arrive that hasn’t yet been seated.
void Queue::enqueue(char* name, int size, bool accom, char* accomDetails)
{
	Group* newGroup = new Group(name, size, accom, accomDetails); // initializing a new group

	Node * newNode = new Node(newGroup);
	if (!rear)
	{	
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	rear->next = front; // set the rear pointing to the front
	size++;
}



// Dequeue function removes person at the front of the queue
bool Queue::dequeue(Group& aGroup)
{
	if(size == 0)
	{
		return false;
	}
	Node * temp = front;
	front = front->next;
	rear->next = front;
	aGroup = *(temp->data);
	delete temp->data;
	delete temp;
	size--;
	return true;
}




// Peek function shows the top of the queue
bool Queue::peek(Group *& aGroup) const // shows top of queue
{
	if(size != 0)
	{
		aGroup = front->data; // returns a ptr
		return true;
	}
	return false;
}



// Write Info function writes data to the external data text file
void Queue::writeInfo(ofstream & outputFile)
{
	Node* currPtr = front;
	bool doneLooping = false;

	while(doneLooping == false)
	{
		outputFile << currPtr->data->getName() << ";" << 
		currPtr->data->getSize() << ";" <<
		currPtr->data->getAccom() << ";"; // gets the name
		if(currPtr->data->getAccom() == true) // checking if accom is true or false
		{
			outputFile << currPtr->data->getAccomDetails() << ";";
		}
		outputFile << "\n";
		if(currPtr->next == front)
		{
			doneLooping = true;
		}
		currPtr = currPtr->next;
	}
}


// Display function diplays the contents of the queue
void Queue::display() const
{
	for (Node * curr = front; curr; curr = curr->next)
	{
		cout << curr->data->getName() << " " << curr->data->getSize() << " " <<
		curr->data->getAccom();
		if(curr->data->getAccom() == true)
		{
			cout << curr->data->getAccomDetails();
		}
		cout << endl;
	}	
}






