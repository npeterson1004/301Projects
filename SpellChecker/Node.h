#ifndef NODE_
#define NODE_

/**
 * @brief Node class represents a node in a linked list.
 * @tparam ItemType The type of data held by the node.
 */
template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   
public:
   /**
    * @brief Default constructor for Node class.
    */
   Node();

   /**
    * @brief Parameterized constructor for Node class.
    * @param anItem The data item to be stored in the node.
    */
   Node(const ItemType& anItem);

   /**
    * @brief Parameterized constructor for Node class.
    * @param anItem The data item to be stored in the node.
    * @param nextNodePtr Pointer to the next node.
    */
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

   /**
    * @brief Sets the data item in the node.
    * @param anItem The data item to be set.
    */
   void setItem(const ItemType& anItem);

   /**
    * @brief Sets the pointer to the next node.
    * @param nextNodePtr Pointer to the next node.
    */
   void setNext(Node<ItemType>* nextNodePtr);

   /**
    * @brief Gets the data item stored in the node.
    * @return The data item.
    */
   ItemType getItem() const;

   /**
    * @brief Gets the pointer to the next node.
    * @return Pointer to the next node.
    */
   Node<ItemType>* getNext() const;

   /**
    * @brief Overloaded equality operator.
    * @param anEntry The data item to compare.
    * @return True if the data item in the node is equal to anEntry, false otherwise.
    */
   bool operator==(const ItemType& anEntry);
}; // end Node

#include "Node.cpp"
#endif
