//------------------------------------------------------------------------------
// LinkedList.cpp : class definition
// 
// Author: unknown book example, unknown author
// 
// This code is intended as an example for students in my classes.
//------------------------------------------------------------------------------
#include "LinkedList.h"

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
LinkedList::LinkedList() { pHead = nullptr; }

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
LinkedList::~LinkedList() { makeEmpty(); }

//------------------------------------------------------------------------------
// new item becomes list _head
//------------------------------------------------------------------------------
void LinkedList::addNode(void* pData) {

	Node* pNode = new Node(pData);

	pNode->pNext = pHead;
	pHead = pNode;
}

//------------------------------------------------------------------------------
// returns true if list is empty, false otherwise
//------------------------------------------------------------------------------
bool LinkedList::isEmpty() { return pHead == nullptr; }

//------------------------------------------------------------------------------
// release all node memory
//------------------------------------------------------------------------------
void LinkedList::makeEmpty() {

	Node* pNode = pHead;			// traverse list from beginning

	while (pNode != nullptr) {

		Node* pZap = pNode;
		pNode = pNode->pNext;

		delete pZap;
	}

	pHead = nullptr;
}
