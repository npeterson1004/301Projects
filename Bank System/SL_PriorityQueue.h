/**
 * @file SL_PriorityQueue.h
 * @brief Priority Queue class template using a linked sorted list implementation.
 */

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
    LinkedSortedList<ItemType>* slistPtr;  ///< Pointer to the sorted list of items in the priority queue

public:
    /// Default constructor
    SL_PriorityQueue();

    /// Copy constructor
    /// @param pq The priority queue to be copied.
    SL_PriorityQueue(const SL_PriorityQueue<ItemType>& pq);

    /// Destructor
    ~SL_PriorityQueue();

    /// Check if the priority queue is empty
    /// @return True if the priority queue is empty, false otherwise.
    bool isEmpty() const;

    /// Add an item to the priority queue.
    /// @param newEntry The item to be added.
    /// @return True if addition is successful, false otherwise.
    bool add(const ItemType& newEntry);

    /// Remove the highest priority item from the priority queue.
    /// @return True if removal is successful, false otherwise.
    bool remove();

    /**
     * @brief Get the highest priority item from the priority queue without removing it.
     * @return The highest priority item in the priority queue.
     * @throw PrecondViolatedExcep if the priority queue is empty.
     */
    ItemType peek() const throw(PrecondViolatedExcep);
}; // end SL_PriorityQueue

#include "SL_PriorityQueue.cpp"
#endif
