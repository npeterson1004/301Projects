#include "HasAFrontList.h"  // Header file
#include "LinkedList.h"
#include <cassert>
#include <cmath>
  
template<class ItemType>
HasAFrontList<ItemType>::HasAFrontList()
{
   // Default constructor
   listPtr = new LinkedList<ItemType>();
}  // end default constructor

template<class ItemType>
HasAFrontList<ItemType>::HasAFrontList(const HasAFrontList<ItemType>& sList) 
{
	// Copy constructor
	// First, create our own list
	listPtr = new LinkedList<ItemType>();
	
	// Then add items to it using public methods
	for(int position = 1; position <= sList.getLength(); position++)
	{
		listPtr->insert(position, sList.getEntry(position));
	}  // end for	
}  // end copy constructor

template<class ItemType>
HasAFrontList<ItemType>::~HasAFrontList()
{
   // Destructor
   clear();
}  // end destructor

template<class ItemType>
void HasAFrontList<ItemType>::insertSorted(const ItemType& newEntry)
{
   // Inserts a new item into the sorted list
   int newPosition = fabs(getPosition(newEntry));
   listPtr->insert(newPosition, newEntry);
}  // end insertSorted

template<class ItemType>
bool HasAFrontList<ItemType>::removeSorted(const ItemType& anEntry)
{
   // Removes the specified item from the sorted list
   bool ableToRemove = false;
   if (!isEmpty())
   {
      int position = getPosition(anEntry);
             
      ableToRemove = position > 0;
      if (ableToRemove)
      {
         ableToRemove = listPtr->remove(position);
      }  // end if
   }  // end if

   return ableToRemove;
}  // end removeSorted

template<class ItemType>
int HasAFrontList<ItemType>::getPosition(const ItemType& anEntry) const
{
   // Gets the position of the specified item in the sorted list
   int position = 1;
   int length = listPtr->getLength();
   
   while ( (position <= length) && (anEntry > listPtr->getEntry(position)) )
   {
      position++;
   } // end while
   
   if ( (position > length) || (anEntry != listPtr->getEntry(position)) )
      position = -position;
   
   return position;
}  // end getPosition

//=====================
// List operations:

template<class ItemType>
bool HasAFrontList<ItemType>::remove(int position)
{
   // Removes the item at the specified position in the sorted list
   return listPtr->remove(position);
}  // end remove

template<class ItemType>
void HasAFrontList<ItemType>::clear()
{
   // Clears all items from the sorted list
   listPtr->clear();
}  // end clear

template<class ItemType>
ItemType HasAFrontList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Gets the item at the specified position in the sorted list
   return listPtr->getEntry(position);
}  // end getEntry

template<class ItemType>
bool HasAFrontList<ItemType>::isEmpty() const
{
   // Checks if the sorted list is empty
   return listPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
int HasAFrontList<ItemType>::getLength() const
{
   // Gets the length of the sorted list
   return listPtr->getLength();
}  // end getLength

//  End of implementation file.
