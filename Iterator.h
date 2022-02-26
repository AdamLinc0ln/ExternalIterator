#pragma once
#include "Node.h"
class Iterator
{
public:
	Iterator();
	~Iterator();
	//Iterator(Node * start, int myIndex);
	Iterator(Node* start);
	int operator*();
	Iterator operator++();
	//Iterator operator++(int dummy);
	bool operator!=(const Iterator& other);
	bool is_item();


private:
	Node* myStart;
	int index;

};
