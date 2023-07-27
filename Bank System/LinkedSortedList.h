/**
 * @file LinkedSortedList.h
 * ADT sorted list: Link-based implementation.
 */

#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to the first node in the chain
    int itemCount;           // Current count of list items

    // Locates the node that is before the node that should or does
    // contain the given entry.
    // @param anEntry  The entry to find.
    // @return  Either a pointer to the node before the node that contains
    //    or should contain the given entry, or nullptr if no prior node exists.
    Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;

    // Locates the node at a given position within the chain.
    Node<ItemType>* getNodeAt(int position) const;

    // Returns a pointer to a copy of the chain to which origChainPtr points.
    Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);

public:
    // Default constructor
    LinkedSortedList();

    // Copy constructor
    LinkedSortedList(const LinkedSortedList<ItemType>& aList);

    // Destructor
    virtual ~LinkedSortedList();

    // Insert an entry into the sorted list in its proper order.
    // @param newEntry The entry to be inserted into the sorted list.
    void insertSorted(const ItemType& newEntry);

    // Remove an entry from the sorted list, if possible.
    // @param anEntry The entry to be removed from the sorted list.
    // @return True if the removal is successful, false otherwise.
    bool removeSorted(const ItemType& anEntry);

    // Find the position of an entry in the sorted list.
    // @param newEntry The entry to find in the sorted list.
    // @return The position of the entry in the sorted list, or -1 if not found.
    int getPosition(const ItemType& newEntry) const;

    // The following methods are the same as given in ListInterface:
    // Check if the list is empty
    bool isEmpty() const;

    // Get the current length of the list
    int getLength() const;

    // Remove an entry from the list at a specified position
    // @param position The position of the entry to be removed.
    // @return True if removal was successful, false otherwise.
    bool remove(int position);

    // Clear the entire list by removing all entries
    void clear();

    // Get the data of the entry at the specified position in the list.
    // @param position The position of the entry to get the data from.
    // @return The data of the entry at the specified position.
    // @throw PrecondViolatedExcep if position < 1 or position > getLength().
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);
}; // end LinkedSortedList

#include "LinkedSortedList.cpp"
#endif
