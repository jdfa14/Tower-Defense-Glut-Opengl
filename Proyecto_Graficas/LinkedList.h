#pragma once

#include "BadAgent.h"

struct Node{
	BadAgent *data;
	Node* next;
	Node* prev;
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
	int size;
public:
	LinkedList();

	void addAtTail(BadAgent* data); // pointer to the new object created
	void addAtHead(BadAgent* data);
	void remove(Node* node); // deletes that node
	void removeTail(); // deletes tail
	void removeHead(); // deletes head
	void clear();// deletes all elements

	Node* getTail();
	Node* getHead();
	int getSize();

};

