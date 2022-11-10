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
void showBikes();
void requestBike(CommunityBike* pBMatch, const string& name);
CommunityBike* findExactMatch(CommunityBike* pBMatch);
CommunityBike* findAlternates(CommunityBike* pBMatch);
void transactBike(CommunityBike* pBike, const string& renterName);

//------------------------------------------------------------------------------
// global variables 
//------------------------------------------------------------------------------
LinkedList g_bikes;			// list of community bikes

//------------------------------------------------------------------------------
// main() : entry point
//------------------------------------------------------------------------------
int main() {

	// add bikes to the list, each becomes the new list head
	g_bikes.addNode(new CommunityBike("blue", 21));
	g_bikes.addNode(new CommunityBike("white", 21));
	g_bikes.addNode(new CommunityBike("green", 21));
	g_bikes.addNode(new CommunityBike("green", 21));
	g_bikes.addNode(new CommunityBike("blue", 23));
	g_bikes.addNode(new CommunityBike("silver", 23));
	g_bikes.addNode(new CommunityBike("red", 19));
	g_bikes.addNode(new CommunityBike("black", 19));
	g_bikes.addNode(new CommunityBike("red", 21));

	// requested bikes
	requestBike(new CommunityBike("red", 19), "Jane");
	requestBike(new CommunityBike("green", 21), "Peter");
	requestBike(new CommunityBike("red", 19), "Wesley");
	requestBike(new CommunityBike("blue", 19), "Josh");
	requestBike(new CommunityBike("yellow", 21), "Vivian");
	requestBike(new CommunityBike("black", 25), "Lance");

	// list all bikes
	showBikes();

	return 0;
}

//------------------------------------------------------------------------------
// display all bikes in the list
//------------------------------------------------------------------------------
void showBikes() {
	cout << "\nCommunity Bike List\n\n";

	int countBikes = 0;
	Node* pNode = g_bikes.getListHead();

	// traverse the list and display bike info
	while (pNode != nullptr) {
		CommunityBike* pBike = pNode->pData;

		cout << '\t' << ++countBikes << ") " 
			<< pBike << ", bike id=" << pBike->getID();

		if (!pBike->isAvailable()) {
			cout << " (rented to " << pBike->getRenterName() << ')';
		}
		cout << '\n';

		pNode = pNode->pNext;
	}
}

//------------------------------------------------------------------------------
// search the list for an exact match of the requested bike
//------------------------------------------------------------------------------
void requestBike(CommunityBike* pBMatch, const string& name) {

	// list all bikes
	showBikes();

	cout << '\n' << name << " requested: " << pBMatch;

	bool successfulRent = false;

	// no exact match, or requested bike already rented: list alternate bikes
	CommunityBike* pBike = findExactMatch(pBMatch);
	if (!pBike) {
		cout << "\nSorry " << name << ", there's no " << pBMatch << ".\n\n";
	}
	else if (pBike->isAvailable()) {
		successfulRent = true;
		transactBike(pBike, name);
	}
	else {
		cout << "\nSorry " << name << ", the " << pBike
			<< " is rented to " << pBike->getRenterName() << "\n\n";
	}

	// handle no exact match or exact match already rented
	if (!successfulRent) {
		CommunityBike* pBike = findAlternates(pBMatch);

		if (pBike) {
			transactBike(pBike, name);
		}
		else {
			cout << "\nSorry " << name << ", no bikes found with a " 
				<< pBMatch->getFrameHeight() << "\" frame\n\n";
		}
	}

	// release memory allocated by caller for requested bike parameter
	delete pBMatch;

	// pause keeps app window from closing
	cout << "Type the enter key to continue...";
	cin.get();
}

//------------------------------------------------------------------------------
// returns pointer to exact match, or nullptr if no exact match exists
//------------------------------------------------------------------------------
CommunityBike* findExactMatch(CommunityBike* pBMatch) {

	Node* pNode = g_bikes.getListHead();

	// traverse the list comparing bikes by frame height

	// overloaded comparison operator !=
	while (pNode != nullptr && *(pNode->pData) != *pBMatch) {
		pNode = pNode->pNext;
	}

	return pNode ? pNode->pData : nullptr;
}

//------------------------------------------------------------------------------
// list available bikes with frame height <= the height requested
// 
// returns:
//		- pointer to an alternate bike with requested frame height,
//		- nullptr if no bikes found with requested frame height
//------------------------------------------------------------------------------
CommunityBike* findAlternates(CommunityBike* pBMatch) {

	cout << "Bikes available with frame height at most "
		<< pBMatch->getFrameHeight() << "\":\n";

	int countAlternates = 0;
	CommunityBike* pBestAlternate = nullptr;

	Node* pNode = g_bikes.getListHead();

	while (pNode != nullptr) {
		CommunityBike* pBike = pNode->pData;

		// overloaded comparison operator <=
		if (*pBike <= *pBMatch && pBike->isAvailable()) {
			cout << '\t' << ++countAlternates << ") " 
				<< pBike << ", bike id=" << pBike->getID() << '\n';

			if (pBike->getFrameHeight() == pBMatch->getFrameHeight()) {
				pBestAlternate = pBike;
			}
		}
		pNode = pNode->pNext;
	}

	if (!countAlternates) {
		cout << "\tnone\n";
	}

	return pBestAlternate;
}

//------------------------------------------------------------------------------
// completes bike rental
//------------------------------------------------------------------------------
void transactBike(CommunityBike* pBike, const string& renterName) {
	pBike->rentBike(renterName);
	cout << '\n' << renterName << ", your bike is waiting: "
		<< pBike << ", bike id=" << pBike->getID() << "\n\n";
}