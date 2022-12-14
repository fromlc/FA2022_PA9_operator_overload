//------------------------------------------------------------------------------
// LinkedList class declaration, Node class declaration and definition
//------------------------------------------------------------------------------
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//------------------------------------------------------------------------------
// Node
//------------------------------------------------------------------------------
class Node {
public:
	void* pData;
	Node* pNext;

	// constructor
	Node(void* pInput) {
		pData = pInput;
		pNext = nullptr;
	}
};

//------------------------------------------------------------------------------
// LinkedList : contains Node as composition
//------------------------------------------------------------------------------
class LinkedList {
private:
	Node* pHead;						// internal use: first node in list

public:
	LinkedList();
	~LinkedList();

	// manage nodes
	void addNode(void* pData);				// add new node at head of list

public:
	// manage list 
	bool isEmpty();
	void makeEmpty();	// release each Node's memory
};
#endif