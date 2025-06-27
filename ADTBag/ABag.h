/*
* File:   ABag.h
* Author: Tyler Ellis
*
* You may use this template to implement your ABag. 
*/

#ifndef ABAG_H
#define	ABAG_H
#include <memory>  //This will be needed for smart pointers
#include "book.h"
#include "bagADT.h"

template <typename E>
class ABag : public Bag<E> {
public:


	//Default constructor for the ABag ADT in the event of initialization without parameters
	ABag() {

	}

	//One-parameter constructor that takes a size_t type variable (such as the DICTIONARY_SIZE from the .cpp file)
	ABag(size_t size) {
		capacity = size;
		used = 0;
		data = std::make_unique<E[]>(capacity); //smart pointer for an E array object (bag)
	}

	//Default destructor
	~ABag() {

	}

	//The addItem method to take an E object and add it to the array.
	//Postcondition: As long as the used space within the bag does not equal or exceed the maximum space, the item is added to the bag.
	bool addItem(const E& item) {
		if (used >= capacity) {
			return false;
		}
		else {
			data.get()[used] = item;
			used++;
			return true;
		}
	}
	//The remove method to remove an item from the bag
	//Postcondition: Assuming the desired array location exists, the item is removed by shifting the rest of the bag back one index.
	bool remove(E& item) {
		bool item_Exists = false;
		for (int i = 0; i < used; i++) {
			if (data.get()[i] == item) {
				item_Exists = true;
				item = data.get()[i];
				for (int j = i + 1; j < used; j++) {
					data.get()[i] = data.get()[j];
				}
				used--;
				break;
			}
		}
		return item_Exists;
	}

	//Removes the top item out of a bag, similar to a stack.
	//Postcondition: the top item is removed and used variable is decremented.
	bool removeTop(E& returnValue) {
		if (used > 0) {
			returnValue = data.get()[--used];
			return true;
		}
		else {
			return false;
		}
	}

	//Looks for an item within the bag, comparing the input parameter to each index of the array with a for loop.
	//Postcondition: If a match exists, returnValue is set to equal that matching value.
	bool find(E& returnValue) const {
		bool item_Exists = false;
		for (int i = 0; i < used; i++) {
			if (data.get()[i] == returnValue) {
				item_Exists = true;
				returnValue = data.get()[i];
				break;
			}
		}
		return item_Exists;
	}

	//Shows the top item in the bag
	//Postcondition: The top item's details is displayed to the console.
	bool inspectTop(E& item) const {
		if (used > 0) {
			item = data.get()[used-1];
			return true;
		}
		else {
			return false;
		}
	}

	//Deletes or "empties" the contents of the entire bag
	//Postcondition: The used variable is set to 0
	void emptyBag() {
		used = 0;

	}

	//Overloads the += operator for the E object, allowing it to use the addItem method.
	//Postcondition: the addItem method is executed using the += operator
	bool operator+=(const E& addend) {
		return addItem(addend);
	}

	//Queries the bag for its size.
	//Postcondition: The bag's current size is returned.
	int size() const {
		return used;
	}

	//Queries the bag for its maximum capacity.
	//Postcondition: the bag's capacity value is returned.
	int bagCapacity() const {
		return capacity;
	}

private:
	

	std::unique_ptr<E[]> data; // an array of items, using a smart pointer.
	int used;           // number of items the data array currently holds.
	int capacity;       // the number of items the bag can hold (size of array).
};

#endif	/* ABAG_H */

