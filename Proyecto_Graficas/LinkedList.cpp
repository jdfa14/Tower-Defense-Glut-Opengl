#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void LinkedList::addAtHead(BadAgent *data){
	Node *n = new Node;
	n->data = data;
	if (head == NULL){// no elements
		head = n;
		tail = n;
		n->next = NULL;
		n->prev = NULL;
	}
	else if (head == tail){// one element
		head->next = n;
		tail = n;
		tail->prev = head;
		tail->next = NULL;
	}
	else{// more than one element
		n->next = head;
		n->prev = NULL;
		head->prev = n;
		head = n;
	}

	size++;
}

void LinkedList::addAtTail(BadAgent *data){
	Node *n = new Node;
	n->data = data;

	if (head == NULL){// no elements
		head = n;
		tail = n;
		n->next = NULL;
		n->prev = NULL;
	}
	else if (head == tail){// one element
		head->next = n;
		tail = n;
		tail->prev = head;
		tail->next = NULL;
	}
	else{// more than one element
		n->prev = tail;
		n->next = NULL;
		tail->next = n;
		tail = n;
	}
	size++;
}

void LinkedList::remove(Node* n){
	if (n == NULL)
		return;
	if (head == NULL)
		return;
	if (n == head){//deleting first
		removeHead();
		return;
	}
	if (n == tail){// deleting last
		removeTail();
		return;
	}
	//re-linking
	n->prev->next = n->next;
	n->next->prev = n->prev;
	//free
	free(n->data);
	free(n);
	size--;
}

void LinkedList::removeTail(){
	Node *n = tail;
	if (n == NULL)//empty
		return;


	if (head == tail){//solo un elemento
		head = NULL;
		tail = NULL;
	}
	else{// dos o mas elementos
		tail = tail->prev;
		tail->next = NULL;
	}
	free(n->data);
	free(n);
	size--;
}

void LinkedList::removeHead(){
	Node *n = head;
	if (n == NULL)
		return;
	if (head == tail){//solo un elemento
		head = NULL;
		tail = NULL;
	}
	else{//dos elementos
		head = head->next;
		head->prev = NULL;
	}
	free(n->data);
	free(n);
	size--;
}

void LinkedList::clear(){
	while (head != NULL)
		removeHead();
}

Node* LinkedList::getTail(){
	return tail;
}

Node* LinkedList::getHead(){
	return head;
}

int LinkedList::getSize(){
	return size;
}