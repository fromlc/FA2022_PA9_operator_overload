//------------------------------------------------------------------------------
// community_bike_app.cpp : driver
//------------------------------------------------------------------------------

#include <iostream>
#include <string>

#include "LinkedList.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void rentBike(CommunityBike* pBMatch);

//------------------------------------------------------------------------------
// global variables 
//------------------------------------------------------------------------------
LinkedList g_bikes;			// list of community bikes

//------------------------------------------------------------------------------
// main() : entry point
//------------------------------------------------------------------------------
int main() {

	// add bikes to the list, each becomes the new list head
	g_bikes.addNode(new CommunityBike("green", 21));
	g_bikes.addNode(new CommunityBike("blue", 23));
	g_bikes.addNode(new CommunityBike("silver", 23));
	g_bikes.addNode(new CommunityBike("red", 19));
	g_bikes.addNode(new CommunityBike("black", 19));
	g_bikes.addNode(new CommunityBike("red", 21));

	// rent requested bikes
	rentBike(new CommunityBike("red", 19));
	rentBike(new CommunityBike("green", 19));
	rentBike(new CommunityBike("red", 19));

	return 0;
}

//------------------------------------------------------------------------------
// search for the requested bike in the list
//------------------------------------------------------------------------------
void rentBike(CommunityBike* pBMatch) {
	// find the matching bike in the list and display it

	Node* p = g_bikes.getListHead();

	// traverse the list comparing bikes by frame height
	while (p != nullptr && *(p->pData) != *pBMatch) {
		p = p->pNext;
	}

	// check whether loop stopped because we found the bike
	if (p != nullptr) {
		if (p->pData->rentBike("Jane")) {
			cout << '\n' << p->pData->getRenterName()
				<< ", your bike is waiting: " << p->pData << '\n';
		}
		else {
			cout << "\nSorry, the " << p->pData 
				<< "is rented to " << p->pData->getRenterName() << '\n';
		}
	}
	// or whether p went past the last bike on the list with no match
	else {
		// #TODO no exact match, turn the person away
		cout << "\nSorry, there's no " << pBMatch << '\n';

		// #TODO 
		// Instead of turning the person away,
		// how can we check for another bike that might work?
		// 
		// Overload the <= operator, then use the <= to compare
		// bike instances in a loop to list all available bikes 
		// with frame height no taller than the height requested. 

	}
	cout << '\n';

	// release memory for this bike
	delete pBMatch;

	// pause keeps app window from closing
	cout << "Type the enter key to continue...";
	cin.get();
}
