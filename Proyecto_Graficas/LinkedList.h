#pragma once

template <class T>
class Node{
public:
	T *data;
	Node* next;
	Node* prev;
};

template <class T>
class LinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	LinkedList();

	void addAtTail(T* data); // pointer to the new object created
	void addAtHead(T* data);
	void addAtTail(Node<T> *node);
	void addAtHead(Node<T> *node);

	void remove(Node<T>* node); // deletes that node
	void removeTail(); // deletes tail
	void removeHead(); // deletes head
	void clear();// deletes all elements

	Node<T>* getTail();
	Node<T>* getHead();
	bool empty();
	int getSize();
};

template <class T>
LinkedList<T>::LinkedList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
void LinkedList<T>::addAtHead(T *data){
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
	else {// more than one element
		n->next = head;
		n->prev = NULL;
		head->prev = n;
		head = n;
	}
	size++;
}

template<class T>
void LinkedList<T>::addAtHead(Node<T> *node){
	addAtHead(node->data);
}

template <class T>
void LinkedList<T>::addAtTail(T *data){
	Node<T> *n = new Node<T>;
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

template<class T>
void LinkedList<T>::addAtTail(Node<T> *node){
	addAtTail(node->data);
}

template <class T>
void LinkedList<T>::remove(Node<T>* n){
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
	//free(n->data);
	free(n);
	size--;
}

template <class T>
void LinkedList<T>::removeTail(){
	Node<T> *n = tail;
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
	//free(n->data); potential memory leak
	free(n);
	size--;
}
template <class T>
void LinkedList<T>::removeHead(){
	Node<T> *n = head;
	T * data = n->data;
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
	free(n);
	size--;
}

template <class T>
void LinkedList<T>::clear(){
	while (head != NULL)
		removeHead();
}
template <class T>
Node<T>* LinkedList<T>::getTail(){
	return tail;
}
template <class T>
Node<T>* LinkedList<T>::getHead(){
	return head;
}

template<class T>
bool LinkedList<T>::empty(){
	return head == NULL;
}

template <class T>
int LinkedList<T>::getSize(){
	return size;
}

