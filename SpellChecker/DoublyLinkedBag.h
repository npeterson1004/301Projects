#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"

/**
 * @brief DoublyLinkedBag class represents a bag implemented using a doubly linked list.
 * @tparam ItemType The type of items stored in the bag.
 */
template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node
    int itemCount;           // Current count of bag items

    /**
     * @brief Returns either a pointer to the node containing a given entry or nullptr if the entry is not in the bag.
     * @param target The item to search for.
     * @return Pointer to the node containing the target item, or nullptr if the item is not found.
     */
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    /**
     * @brief Default constructor for DoublyLinkedBag class.
     */
    DoublyLinkedBag();

    /**
     * @brief Copy constructor for DoublyLinkedBag class.
     * @param aBag The bag to be copied.
     */
    DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag);

    /**
     * @brief Destructor for DoublyLinkedBag class.
     */
    virtual ~DoublyLinkedBag();

    /**
     * @brief Gets the current number of items in the bag.
     * @return The number of items in the bag.
     */
    int getCurrentSize() const;

    /**
     * @brief Checks if the bag is empty.
     * @return True if the bag is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Adds an item to the bag.
     * @param newEntry The item to be added.
     * @return True if the addition is successful, false otherwise.
     */
    bool add(const ItemType& newEntry);

    /**
     * @brief Removes an occurrence of the item from the bag.
     * @param newEntry The item to be removed.
     * @return True if the removal is successful, false otherwise.
     */
    bool remove(const ItemType& newEntry);

    /**
     * @brief Removes all items from the bag.
     */
    void clear();

    /**
     * @brief Checks if the bag contains a specific item.
     * @param anEntry The item to be checked.
     * @return True if the item is found in the bag, false otherwise.
     */
    bool contains(const ItemType& anEntry) const;

    /**
     * @brief Checks if the bag contains a specific item and suggests a spelling correction.
     * @param anEntry The item to be checked.
     * @return True if the item is found in the bag, false otherwise.
     */
    bool spell_check(const ItemType& anEntry) const;

    /**
     * @brief Gets the number of occurrences of a specific item in the bag.
     * @param anEntry The item to be counted.
     * @return The number of occurrences of the item in the bag.
     */
    int getFrequencyOf(const ItemType& anEntry) const;

    /**
     * @brief Converts the bag into a vector containing all items in the bag.
     * @return A vector containing all items in the bag.
     */
    std::vector<ItemType> toVector() const;

    /**
     * @brief Overloaded equality operator.
     * @param newEntry The item to compare.
     * @return True if the item in the bag is equal to newEntry, false otherwise.
     */
    bool operator==(const ItemType& newEntry);
};

#include "DoublyLinkedBag.cpp"
#endif
