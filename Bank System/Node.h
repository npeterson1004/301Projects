/**
 * @file Node.h
 * @brief Node class template for a linked list implementation.
 */

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
    ItemType item;           ///< A data item
    Node<ItemType>* next;    ///< Pointer to the next node

public:
    /// Default constructor
    Node();

    /// Constructor with item only
    /// @param anItem The data item to be stored in the node.
    Node(const ItemType& anItem);

    /// Constructor with both item and next node pointer
    /// @param anItem The data item to be stored in the node.
    /// @param nextNodePtr Pointer to the next node in the linked list.
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

    /// Set the data item of the node
    /// @param anItem The data item to be set.
    void setItem(const ItemType& anItem);

    /// Set the next node pointer of the node
    /// @param nextNodePtr Pointer to the next node in the linked list.
    void setNext(Node<ItemType>* nextNodePtr);

    /// Get the data item of the node
    /// @return The data item of the node.
    ItemType getItem() const;

    /// Get the pointer to the next node in the linked list
    /// @return Pointer to the next node.
    Node<ItemType>* getNext() const;
}; // end Node

#include "Node.cpp"
#endif
