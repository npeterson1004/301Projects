/**
 * @file AsAFrontList.h
 * @brief Header file for the AsAFrontList class, a sorted linked list implementation.
 * It inherits from LinkedList and implements the FrontListInterface.
   StarID: qw3581ym
   Due: July: 17, 2023
   Intructor: Jie Meichsner
 */

#ifndef _SORTED_LIST_AS_A
#define _SORTED_LIST_AS_A

#include "FrontListInterface.h"
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

/**
 * @brief AsAFrontList class, a sorted linked list implementation.
 * @tparam ItemType The type of the items stored in the list.
 */
template<class ItemType>
class AsAFrontList : public FrontListInterface<ItemType>, private LinkedList<ItemType>
{
public:
   /**
    * @brief Default constructor.
    */
   AsAFrontList();

   /**
    * @brief Copy constructor.
    * 
    * @param sList The list to be copied.
    */
   AsAFrontList(const AsAFrontList<ItemType>& sList);

   /**
    * @brief Destructor.
    */
   virtual ~AsAFrontList();

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
    * @param newEntry The item to find the position of.
    * @return The position of the item in the list, or a negative value if not found.
    */
   int getPosition(const ItemType& newEntry) const;
   
   // The following methods are inherited and have the same 
   // specifications as given in ListInterface:

   /**
    * @brief Checks if the sorted list is empty.
    * 
    * @return True if the list is empty, false otherwise.
    */
   bool isEmpty() const;

   /**
    * @brief Gets the length of the sorted list.
    * 
    * @return The length of the list.
    */
   int getLength() const;

   /**
    * @brief Removes the item at the specified position in the sorted list.
    * 
    * @param position The position of the item to be removed.
    * @return True if the removal was successful, false otherwise.
    */
   bool remove(int position);

   /**
    * @brief Clears all items from the sorted list.
    */
   void clear();

   /**
    * @brief Gets the item at the specified position in the sorted list.
    * 
    * @param position The position of the item to retrieve.
    * @return The item at the specified position.
    * @throw PrecondViolatedExcep if the position is invalid.
    */
   ItemType getEntry(int position) const throw(PrecondViolatedExcep);   
};

#include "AsAFrontList.cpp"
#endif
