//------------------------------------------------------------------------------
// LinkedList class declaration, Node class declaration and definition
//------------------------------------------------------------------------------
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "CommunityBike.h"

//------------------------------------------------------------------------------
// Node : holds CommunityBike data
//------------------------------------------------------------------------------
class Node {
public:
	CommunityBike* pData;
	Node* pNext;

	// constructor
	Node(CommunityBike* pInput) {
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
	Node* getListHead();				// returns list head pointer
	void addNode(CommunityBike* pData);	// add new node at head of list

	// manage list 
	bool isEmpty();
	void makeEmpty();	// release each Node's memory
};
#endif // LINKEDLIST_H