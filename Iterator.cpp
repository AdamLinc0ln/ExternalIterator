#include <iostream>
#include "Iterator.h"

Iterator::Iterator()
{
}

Iterator::~Iterator()
{
}

Iterator::Iterator(Node* start)// The iterator initially points to “start”.
{
	myStart = start;
}

int Iterator::operator*()// dereference the iterator 
{
	return myStart->data;//looks at data in node
}

Iterator Iterator::operator++()// advance the iterator //pre or post?
{
	// save off current Iterator
	//Iterator temp = *this;
	// increment current Iterator??
	myStart = myStart->next;
	// return saved-off Iterator
	return *this;
}


bool Iterator::operator!=(const Iterator& other) // returns true if and only if other iterator does not equal this iterator 
{
	if (this->myStart != other.myStart)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Iterator::is_item()// returns true if Iterator points to a valid Node (if nullptr return false…) 
{
	if (myStart == nullptr)//??
	{
		return false;
	}
	return true;
}
