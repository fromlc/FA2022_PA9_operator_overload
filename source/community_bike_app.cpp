//------------------------------------------------------------------------------
// community_bike_app.cpp 
//------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "CommunityBike.h"
#include "LinkedList.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// global variables 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main() : entry point
//------------------------------------------------------------------------------
int main() {
	LinkedList bikes;			// list of community bikes

	bikes.addNode(new CommunityBike("green", 21));
	bikes.addNode(new CommunityBike("blue", 23));
	bikes.addNode(new CommunityBike("red", 19));

	CommunityBike* pBMatch = new CommunityBike("red", 19);

	// find the matching bike in the list and display it

	Node* p = bikes.getListHead();

	while (p != nullptr && *((CommunityBike*)(p->pData)) != *pBMatch) {
		p = p->pNext;
	}

	if (p != nullptr) {
		cout << ((CommunityBike*)(p->pData));
	}

	cin.get();

	return 0;
}
