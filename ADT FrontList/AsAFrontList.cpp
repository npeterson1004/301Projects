/**
 * @file AsAFrontList.cpp
 * @brief Implementation file for the AsAFrontList class, a sorted linked list.
 * It inherits from LinkedList and implements the FrontListInterface.Name: Nathan Peterson
   StarID: qw3581ym
   Due: July: 17, 2023
   Intructor: Jie Meichsner
 */

#include "AsAFrontList.h"
#include <cassert>
#include <cmath>
  
template<class ItemType>
AsAFrontList<ItemType>::AsAFrontList()
{
}  // end default constructor

template<class ItemType>
AsAFrontList<ItemType>::AsAFrontList(const AsAFrontList<ItemType>& sList)
		: LinkedList<ItemType>(sList)
{
	
}  // end copy constructor

template<class ItemType>
AsAFrontList<ItemType>::~AsAFrontList()
{
    clear();
}  // end destructor

template<class ItemType>
void AsAFrontList<ItemType>::insertSorted(const ItemType& newEntry)
{
   int newPosition = fabs(getPosition(newEntry));
   this->insert(newPosition, newEntry);
}  // end insertSorted

template<class ItemType>
bool AsAFrontList<ItemType>::removeSorted(const ItemType& anEntry)
{
   bool ableToDelete = false;

   if (!LinkedList<ItemType>::isEmpty())
   {
      int position = getPosition(anEntry);
             
      ableToDelete = position > 0;
      if (ableToDelete)
      {
         ableToDelete = remove(position);
      }  // end if
   }  // end if

   return ableToDelete;
}  // end removeSorted

template<class ItemType>
int AsAFrontList<ItemType>::getPosition(const ItemType& anEntry) const
{
   int position = 1;
   int length = LinkedList<ItemType>::getLength();
   
   while ((position <= length) && (anEntry > LinkedList<ItemType>::getEntry(position)))
   {
      position++;
   }  // end while
   
   if ((position > length) || (anEntry != LinkedList<ItemType>::getEntry(position)))
   {
      position = -position;
   }  // end if
   
   return position;
}  // end getPosition

// List operations:

template<class ItemType>
void AsAFrontList<ItemType>::clear()
{
    LinkedList<ItemType>::clear();
}  // end clear

template<class ItemType>
bool AsAFrontList<ItemType>::isEmpty() const
{
    return LinkedList<ItemType>::isEmpty();
}  // end isEmpty

template<class ItemType>
int AsAFrontList<ItemType>::getLength() const
{
    return LinkedList<ItemType>::getLength();
}  // end getLength

template<class ItemType>
bool AsAFrontList<ItemType>::remove(int position)
{
    return LinkedList<ItemType>::remove(position);
}

template<class ItemType>
ItemType AsAFrontList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    return LinkedList<ItemType>::getEntry(position);
}
