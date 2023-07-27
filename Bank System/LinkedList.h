/**
 * @file LinkedList.h
 * ADT list: Link-based implementation.
 */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to the first node in the chain (contains the first entry in the list)

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<ItemType>* getNodeAt(int position) const;

public:
    // Default constructor
    LinkedList();

    // Copy constructor
    LinkedList(const LinkedList<ItemType>& aList);

    // Destructor
    virtual ~LinkedList();

    // Check if the list is empty
    bool isEmpty() const;

    // Get the current length of the list
    int getLength() const;

    // Insert an entry into the list at a specified position
    // @param newPosition The position to insert the new entry at.
    // @param newEntry The data of the new entry to be inserted.
    // @return True if insertion was successful, false otherwise.
    bool insert(int newPosition, const ItemType& newEntry);

    // Remove an entry from the list at a specified position
    // @param position The position of the entry to be removed.
    // @return True if removal was successful, false otherwise.
    bool remove(int position);

    // Clear the entire list by removing all entries
    void clear();

    /**
     * @brief Get the data of the entry at the specified position in the list.
     * @param position The position of the entry to get the data from.
     * @return The data of the entry at the specified position.
     * @throw PrecondViolatedExcep if position < 1 or position > getLength().
     */
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);

    /**
     * @brief Replace the data of the entry at the specified position with new data.
     * @param position The position of the entry to be replaced.
     * @param newEntry The new data to be assigned to the entry.
     * @return The data of the entry before replacement.
     * @throw PrecondViolatedExcep if position < 1 or position > getLength().
     */
    ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
};

#include "LinkedList.cpp"
#endif
