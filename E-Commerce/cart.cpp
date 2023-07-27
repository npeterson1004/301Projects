#include "cart.h"

// Default Constructor
template <class ItemType>
ShoppingCart<ItemType>::ShoppingCart() {
    totalPrice = 0;
}

template <class ItemType>
bool ShoppingCart<ItemType>::add(Item newItem) {
    bool added = Bag<ItemType>::add(newItem);
    totalPrice = totalPrice + (newItem.getQuantity() * newItem.getPrice());
    return added;
}

template <class ItemType>
bool ShoppingCart<ItemType>::remove(Item anItem) {
    bool removed = Bag<ItemType>::remove(anItem);
    totalPrice = totalPrice - (anItem.getQuantity() * anItem.getPrice());
    return removed;
}

template <class ItemType>
double ShoppingCart<ItemType>::getTotalPrice() {
    return totalPrice;
}
