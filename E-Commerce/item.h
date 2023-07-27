#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
 * The Item class represents an item in the shopping cart.
 */
class Item {
private:
    string name;
    double price;
    int quantity;

public:
    /**
     * Default constructor for Item class.
     */
    Item();

    /**
     * Constructor for Item class with parameters.
     * @param n The name of the item.
     * @param p The price of the item.
     * @param q The quantity of the item.
     */
    Item(string n, double p, int q);

    // Setters

    /**
     * Sets the name of the item.
     * @param s The name of the item.
     */
    void setName(string s);

    /**
     * Sets the price of the item.
     * @param p The price of the item.
     */
    void setPrice(double p);

    /**
     * Sets the quantity of the item.
     * @param q The quantity of the item.
     */
    void setQuantity(int q);

    // Getters

    /**
     * Gets the name of the item.
     * @return The name of the item.
     */
    string getName() const { return name; };

    /**
     * Gets the price of the item.
     * @return The price of the item.
     */
    double getPrice() const { return price; };

    /**
     * Gets the quantity of the item.
     * @return The quantity of the item.
     */
    int getQuantity() const { return quantity; };

    /**
     * Overloaded input stream operator to input the item details.
     * @param is The input stream.
     * @param item The Item object to store the input.
     * @return The input stream after input operation.
     */
    friend istream& operator>>(istream& is, Item& item);

    /**
     * Overloaded equality operator to compare two Item objects.
     * @param i1 The first Item object.
     * @param i2 The second Item object.
     * @return True if the items are equal, false otherwise.
     */
    friend bool operator==(Item i1, Item i2);

    /**
     * Overloaded output stream operator to output the item details.
     * @param os The output stream.
     * @param source The Item object to output.
     * @return The output stream after output operation.
     */
    friend ostream& operator<<(ostream& os, const Item& source);
};

#include "item.cpp"
#endif // ITEM_H
