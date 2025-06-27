/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Tyler Ellis
*
* You may use this template to implement your Dictionary
*/

#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"
#include <memory>

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:

	//Constructor that takes a key, value (E), and size as parameters to construct a dynamically allocated ABag object.
	BDictionary<Key, E>(int size) {
		dictionary = std::make_unique<ABag<KVpair<Key, E>>>(size); //smart pointer
	}

	//Default Destructor for BDictionary
	~BDictionary() {

	}
	
	//Accesses the emptyBag method via the pointer-to-member operator to empty the contents of the dictionary.
	//Postcondition: the contents of the dictionary object are emptied.
	void clear() {
		dictionary->emptyBag();
	}

	//Inserts a key/value pair into the dictionary using smart pointers.
	//Postcondition: A new record is placed within the dictionary
	bool insert(const Key& k, const E& e) {
		std::unique_ptr<KVpair<Key, E>> insertedVal = std::make_unique<KVpair<Key, E>>(k, e); //smart pointer
		return dictionary->addItem(*insertedVal);
	}

	//Removes a record from the dictionary.
	//Postcondition: Assuming the item exists, the desired key and/or value is found and removed from the dictionary.
	bool remove(const Key& k, E& rtnVal) {

		bool itemExists;
		std::unique_ptr<KVpair<Key, E>> removedVal = std::make_unique<KVpair<Key, E>>(k, rtnVal); //smart pointer

		itemExists = dictionary->remove(*removedVal);

		if (itemExists) {
			rtnVal = removedVal->value();
		}

		return itemExists;
	}

	//Removers any record from the dictionary using the removeTop bag method.
	//Postcondition: The top value is removed from the dictionary, value is pushed to the member access function value() from KVpair.h
	bool removeAny(E& returnValue) {
		bool removeSuccess;
		std::unique_ptr<KVpair<Key, E>> removedVal = std::make_unique<KVpair<Key, E>>(); //smart pointer

		removeSuccess = dictionary->removeTop(*removedVal);
		if (removeSuccess) {
			returnValue = removedVal->value();
		}
		
		return removeSuccess;
	}
	
	//Locates a dictionary record using key/value pairs.
	//Postcondition: Assuming the record exists, the record is located and pushed to the member access function value() from KVpair.h
	bool find(const Key& k, E& returnValue) const {

		bool itemExists;
		std::unique_ptr<KVpair<Key, E>> finder = std::make_unique<KVpair<Key, E>>(k, returnValue); //smart pointer

		itemExists = dictionary->find(*finder);
		if (itemExists) {
			returnValue = finder->value();
		}

		return itemExists;

	}

	//Gets the size of the dictionary
	//Postcondition: The size is returned using the bag method.
	int size() {
		return dictionary->size();
	}

private:
	std::unique_ptr<ABag<KVpair<Key, E>>> dictionary; //smart pointer to a dictionary
};


#endif	/* BDICTIONARY_H */

