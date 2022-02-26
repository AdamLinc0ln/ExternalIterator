#include <iostream>
#include "List.h"
using namespace std;


List::List()
{
}

List::~List()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}

}

void List::push_front(const int& value)// add new node to front of the list 
{
	Node* myNode = new Node();
	//assign value
	myNode->data = value;
	//
	myNode->next = head;
	//
	head = myNode;//make new node head
	size = size + 1;
}

void List::push_back(const int& value) // add new node to back of the list 
{
	//new node
	Node* myNode = new Node();
	myNode->data = value;
	myNode->next = nullptr;

	//If empty
	if (head == nullptr)
	{
		head = myNode;
		size++;

	}
	//else list is not empty
	// find last list and link the new node
	else
	{
		Node* temp = head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = myNode;
		size++;

	}
	tail = myNode;


}

void List::remove(const int& value)// removes ALL nodes in list with this value 
{
	//remove all nodes from the front of the list
	while (head != nullptr && head->data == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	//remove all nodes from the middle of the list
	Node* temp = head;
	while (temp->next != nullptr)
	{
		if (temp->next->data == value)
		{
			if (temp->next->next == nullptr)
			{
				tail = temp;
			}
			Node* toBeDeleted = temp->next;
			temp->next = toBeDeleted->next;
			delete toBeDeleted;
			size--;
		}
		else
		{
			temp = temp->next;
		}//assign tail to last
	}

}

Iterator List::begin()// iterator to the beginning of the list 
{
	return Iterator(head);//?
}

Iterator List::end()// iterator to the end of the list 
{
	return Iterator(tail->next);//?
}

int List::getSize()// number of elements currently in list 
{
	return size;
}

void List::PrintList()// mainly for debugging 
{
	Node* temp = head;
	//make sure list is not empty
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		//point to next list
		temp = temp->next;
	}
	cout << endl;

}
