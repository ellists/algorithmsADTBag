/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Created on July 14, 2012, 11:45 AM
* Updated pointers to smart pointers in ABag and BDictionary on 12/14/2018
*/

#include <string>
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"

using namespace std;

const size_t DICTIONARY_SIZE = 20;								//The dictionary size variable.

void PauseScreen(); //Used to pause screen output
void addItemTest(ABag<KVpair<int, string>>&); //shows the working addItem bag method
void plusEqualTest(ABag<KVpair<int, string>>&); //shows the working += operator
void inspectTopTest(ABag<KVpair<int, string>>&); //shows inspectTop is working
void bagCapacityTest(const ABag<KVpair<int, string>>&); //shows the max capicity member function works

/*
* Tests BDictionary with int and string objects only.
*/
int main(int argc, char** argv) {

	cout << "<Tyler Ellis> -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);		//declares an object of type BDictionary with int/string parameters
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);		//same as above, reverses the order of parameters

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {				//this loop iterates DICTIONARY_SIZE number of times, with a stringstream variable sn writing to a position
		stringstream sn;										//in the dictionary, the dictionary insert method uses a key of the loop count * 10, and a value of the
		sn << "Beth " << i * 10;								//stringstream being written.
		myIntStrDict.insert(i * 10, sn.str());
	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	/* end myStrIntDict tests ---------------------------------------------*/

	/* Demonstrate any Bag functions that were not used/demonstrated in the implemention 
	of your BDictionary and ABag using a Bag of KVpairs<int, string>. */

	ABag<KVpair<int, string>> myBag(5); //Used to test bag functions not previously demonstrated, initialized with a set capacity of 5

	cout << "\nTesting Other Bag Functions\n\n";

	addItemTest(myBag);
	plusEqualTest(myBag);
	inspectTopTest(myBag);
	bagCapacityTest(myBag);

	return 0;
}

//Used to pause the screen wherever desired
void PauseScreen()
{
	char ch;
	cout << "\nPress the Enter key to continue ... ";
	cin.get(ch);
}

void addItemTest(ABag<KVpair<int, string>>& myBag) {

	cout << "Testing the addItem method!...\n\n";
	cout << "Size before addItem: ";
	cout << myBag.size();
	cout << ".\n";
	cout << "Adding item!\n";
	KVpair<int, string> someKeyValue1 = KVpair<int, string>(15, "Computer Science");
	myBag.addItem(someKeyValue1);

	cout << "Size after addItem: ";
	cout << myBag.size();
	cout << ".\n";

}

void plusEqualTest(ABag<KVpair<int, string>>& myBag) {

	cout << "\n\nTesting the += overloaded operator!...\n\n";
	cout << "Size before +=  : ";
	cout << myBag.size();
	cout << ".\n";
	cout << "Adding item via += operator!\n";
	KVpair<int, string> someKeyValue2 = KVpair<int, string>(7, "Cybersecurity");
	myBag += someKeyValue2;

	cout << "Size after +=  : ";
	cout << myBag.size();
	cout << ".\n";

}

void inspectTopTest(ABag<KVpair<int, string>>& myBag) {

	cout << "\n\nTesting the inspectTop member function!...\n\n";
	KVpair<int, string> someItem(45, "Liberty University");
	myBag += someItem;

	if (myBag.inspectTop(someItem)) {
		cout << "The value of the top item is: " << someItem.value();
	}
	else {
		cout << "The bag is empty!\n";
	}

	cout << "\n\nNow we will try again with an empty bag:\n\n";
	cout << "Testing the inspectTop member function!...\n\n";
	myBag.emptyBag();
	if (myBag.inspectTop(someItem)) {
		cout << "The value of the top item is: " << someItem.value();
	}
	else {
		cout << "The bag is empty!\n";
	}

}

void bagCapacityTest(const ABag<KVpair<int, string>>& myBag) {

	cout << "\n\nTesting that the bagCapacity method works, knowing our capacity is 5...\n\n";
	
	cout << "My bag object's capacity is: ";
	cout<< myBag.bagCapacity();

}