/**
 * @file IsAFrontList.h
 * @brief Header file for the IsAFrontList class, a sorted linked list implementation.
 * It inherits from the LinkedList class.
 * Name: Nathan Peterson
 * StarID: qw3581ym
 * Due: July: 17, 2023
 * Intructor: Jie Meichsner
 */

#ifndef _SORTED_LIST_IS_A
#define _SORTED_LIST_IS_A

#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

/**
 * @brief IsAFrontList class, a sorted linked list implementation.
 * @tparam ItemType The type of the items stored in the list.
 */
template<class ItemType>
class IsAFrontList : public LinkedList<ItemType>
{
public:
   /**
    * @brief Default constructor.
    */
   IsAFrontList();

   /**
    * @brief Copy constructor.
    * 
    * @param sList The list to be copied.
    */
   IsAFrontList(const IsAFrontList<ItemType>& sList);

   /**
    * @brief Destructor.
    */
   virtual ~IsAFrontList();

   /**
    * @brief Inserts a new item into the sorted list.
    * 
    * @param newEntry The item to be inserted.
    */
   void insertSorted(const ItemType& newEntry);

   /**
    * @brief Removes the specified item from the sorted list.
    * 
    * @param anEntry The item to be removed.
    * @return True if the removal was successful, false otherwise.
    */
   bool removeSorted(const ItemType& anEntry);

   /**
    * @brief Gets the position of the specified item in the sorted list.
    * 
    * @param anEntry The item to find the position of.
    * @return The position of the item in the list, or a negative value if not found.
    */
   int getPosition(const ItemType& anEntry) const;
   

   // The following methods must be overridden to disable their
   // effect on a sorted list:

   /**
    * @brief Disables the insert operation for a sorted list.
    * 
    * @param newPosition The desired position for the new item.
    * @param newEntry The item to be inserted.
    * @return False, as insertion at a specific position is not allowed.
    */
   bool insert(int newPosition, const ItemType& newEntry);

   /**
    * @brief Disables the replace operation for a sorted list.
    * 
    * @param position The position of the item to be replaced.
    * @param newEntry The new item to replace the existing item.
    * @return The existing item, as replacement is not allowed in a sorted list.
    * @throw PrecondViolatedExcep as replacement is not allowed in a sorted list.
    */
   ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
}; // end SortedListIsA

#include "IsAFrontList.cpp"
#endif 
