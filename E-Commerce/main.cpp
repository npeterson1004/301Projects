/*
Class inheritance to solve a problem
This Program simulates When shopping online, you can select items and add them to a shopping cart. Duplicate items
are permitted in a shopping cart, as you can purchase multiples of the same item. You
also can remove an item from a shopping cart, if you change your mind about buying it.
The shopping cart can show its current contents with their prices and the total cost of
these items.

o Your startID and name: qw3581ym
o Due Date:7/3/23
o Instructor: Jei Meichsner
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "cart.h"
#include "item.h"   // For ADT bag

using namespace std;

/**
 * Displays the items in the bag.
 * @param aBag The bag containing items.
 */
template<class ItemType>
void displayBagItems(const Bag<ItemType>& aBag);

/**
 * Adds an item to the shopping cart.
 * @param cart The shopping cart.
 * @param item The item to add.
 */
void addItem(ShoppingCart<Item>& cart, Item& item);

/**
 * Removes an item from the shopping cart.
 * @param cart The shopping cart.
 * @param item The item to remove.
 */
void removeItem(ShoppingCart<Item>& cart, Item& item);

/**
 * Changes the quantity of an item in the shopping cart.
 * @param cart The shopping cart.
 * @param item The item to change the quantity for.
 */
void changeQuantity(ShoppingCart<Item>& cart, Item& item);

int main()
{
    Item item;
    ShoppingCart<Item> cart;
    cout << "Welcome to Nathan's Shopping Center!" << endl;

    // Display the cart
    cout << "Your Cart: " << endl;
    cout << "Item     Price     Quantity" << endl;
    cout << "______________________________" << endl;
    displayBagItems(cart);
    cout << "______________________________" << endl;
    cout << "Your Total: $" << cart.getTotalPrice() << endl;

    while (true) {
        int option;
        cout << "What do you want to do? (Enter option 1-4)" << endl;
        cout << "1: Add Item" << endl;
        cout << "2: Remove Item" << endl;
        cout << "3: Change Quantity" << endl;
        cout << "4: Exit Program" << endl;

        label3:
        cout << "->";
        cin >> option;

        if (option == 1) {
            addItem(cart, item);
        } else if (option == 2) {
            removeItem(cart, item);
        } else if (option == 3) {
            changeQuantity(cart, item);
        } else if (option == 4) {
            break;
        } else {
            goto label3;
        }

        // Display the cart
        cout << "Your Cart: " << endl;
        cout << "Item     Price     Quantity" << endl;
        cout << "______________________________" << endl;
        displayBagItems(cart);
        cout << "______________________________" << endl;
        cout << "Your Total: $" << cart.getTotalPrice() << endl << endl;
    }

    return 0;
}

template<class ItemType>
void displayBagItems(const Bag<ItemType>& aBag)
{
    vector<ItemType> bagItems;
    bagItems = aBag.toVector();
    int numOfItems = bagItems.size();
    int n = 1;

    for (int i = 0; i < numOfItems; ++i) {
        cout << n << ": ";
        operator<<(cout, bagItems[i]);
        n++;
    }
}

void addItem(ShoppingCart<Item>& cart, Item& item)
{
    cout << "Enter the item you selected in the following order:\nname unitPrice quantity" << endl;

    while (true) {
    label:
        cin >> item;
        cart.add(item);
        cout << endl;

        string b;
        cout << "Do you want to add another item? (y/n)" << endl;

        cout << "->";
        cin >> b;

        if (b == "y") {
            goto label;
        } else if (b == "n") {
            break;
        }
        cout << endl;
    }
}

void removeItem(ShoppingCart<Item>& cart, Item& item)
{     
   label2:
   cout << "Enter the item you selected in the following order:\nname unitPrice quantity" << endl;

   while (true) {
   label:
      cin >> item;
      if (cart.contains(item)) {
        cart.remove(item);
      }
      else{
         cout << "Cart Does not contain that item!" << endl;
         cout << "Do you still want to remove an item?(y/n)" << endl;
         label3:
         cout << "->";
         string c;
         cin >> c;
         if(c == "y")
         {
            goto label2;
         }
         else if(c == "n")
         {
            break;
         }
         else
         {
            goto label3;
         }
      }
        cout << endl;

        string b;
        cout << "Do you want to remove another item? (y/n)" << endl;

        cout << "->";
        cin >> b;

        if (b == "y") {
            goto label;
        } else if (b == "n") {
            break;
        }
        cout << endl;
    }
}

void changeQuantity(ShoppingCart<Item>& cart, Item& item)
{
    int q;

label1:
    cout << "Enter the item to change in the following order: name unitPrice quantity" << endl;
    cin >> item;

    if (cart.contains(item)) {
    label2:
        cout << "Enter the new quantity:" << endl;
        cout << "-->";
        cin >> q;

        if (q > 0) {
            cart.remove(item);
            item.setQuantity(q);
            cart.add(item);
            cout << "The item's quantity has been updated!" << endl;
            cout << endl;
        } else {
            cout << q << " is an invalid input, try again! " << endl;
            goto label2;
        }
    } else {
        cout << "No such item in the shopping cart!" << endl;
        goto label1;
    }
}
