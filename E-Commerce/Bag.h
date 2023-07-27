//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Array-based implementation.
 @file Bag.h */

#ifndef _BAG
#define _BAG

#include "BagInterface.h"

/**
 * Bag class represents a collection of items using an array-based implementation.
 * It implements the BagInterface.
 * @tparam ItemType The type of items in the bag.
 */
template<class ItemType>
class Bag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_BAG_SIZE = 15;
	ItemType items[DEFAULT_BAG_SIZE]; // Array of bag items
   int itemCount;                    // Current count of bag items
   int maxItems;                     // Maximum capacity of the bag
   
   /**
    * Returns the index of the element in the items array that contains the given target.
    * @param target The item to search for.
    * @return The index of the target item in the array, or -1 if not found.
    */
   int getIndexOf(const ItemType& target) const;   

public:
   /**
    * Default constructor for the Bag class.
    * Initializes the bag with an empty state.
    */
	Bag();

   /**
    * Gets the current number of items in the bag.
    * @return The current number of items.
    */
	int getCurrentSize() const;

   /**
    * Checks if the bag is empty.
    * @return True if the bag is empty, false otherwise.
    */
	bool isEmpty() const;

   /**
    * Adds an item to the bag.
    * @param newEntry The item to add.
    * @return True if the addition was successful, false otherwise.
    */
	bool add(const ItemType& newEntry);

   /**
    * Removes an item from the bag.
    * @param anEntry The item to remove.
    * @return True if the removal was successful, false otherwise.
    */
	bool remove(const ItemType& anEntry);

   /**
    * Removes all items from the bag.
    */
	void clear();

   /**
    * Checks if the bag contains a specific item.
    * @param anEntry The item to search for.
    * @return True if the bag contains the item, false otherwise.
    */
	bool contains(const ItemType& anEntry) const;

   /**
    * Counts the number of times a specific item appears in the bag.
    * @param anEntry The item to count.
    * @return The number of times the item appears in the bag.
    */
	int getFrequencyOf(const ItemType& anEntry) const;

   /**
    * Converts the bag into a vector.
    * @return A vector containing all the items in the bag.
    */
	vector<ItemType> toVector() const;
};  // end Bag

#include "Bag.cpp"

#endif
