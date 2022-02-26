#pragma once
#include "Iterator.h"
class List
{
public:
	List();
	~List();
	void push_front(const int& value);
	void push_back(const int& value);
	void remove(const int& value);
	Iterator begin();
	Iterator end();
	int getSize();
	void PrintList();


private:
	Node* tail = nullptr;
	Node* head = nullptr;
	int size;

};
