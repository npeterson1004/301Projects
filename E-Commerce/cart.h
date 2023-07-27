#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "bag.h"
#include "item.h"

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * The ShoppingCart class represents a shopping cart that extends the Bag class.
 * It stores a collection of items and provides additional functionality for managing the cart.
 * @tparam ItemType The type of items stored in the shopping cart.
 */
template <class ItemType>
class ShoppingCart : public Bag<ItemType> {
private:
    double totalPrice; // Total price of items in the cart

public:
    /**
     * Default constructor for the ShoppingCart class.
     */
    ShoppingCart();

    /**
     * Calculates and returns the total price of all items in the cart.
     * @return The total price of the items in the cart.
     */
    double getTotalPrice();

    /**
     * Adds an item to the shopping cart.
     * @param item The item to add.
     * @return True if the item was added successfully, false otherwise.
     */
    bool add(Item item);

    /**
     * Removes an item from the shopping cart.
     * @param item The item to remove.
     * @return True if the item was removed successfully, false otherwise.
     */
    bool remove(Item item);
};

#include "cart.cpp"

#endif // SHOPPINGCART_H
