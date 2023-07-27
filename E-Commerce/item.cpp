#include "item.h"
#include <string>

using namespace std;

Item::Item() {

}

Item::Item(string n, double p, int q) {
    name = n;
    price = p;
    quantity = q;
}

// Setters
void Item::setName(string n) {
    name = n;
}

void Item::setPrice(double p) {
    price = p;
}

void Item::setQuantity(int q) {
    quantity = q;
}

// Definition of the friend function
istream& operator >>(istream& ins, Item& target)
{
    cout << "Item->";
    ins >> target.name;
    cout << "Price->";
    ins >> target.price;
    cout << "Quantity->";
    ins >> target.quantity;

    return ins;
}

// Definition of non-member functions

// Overloaded equality operator to compare two Item objects.
bool operator ==(Item i1, Item i2) {
    return (i1.getName() == i2.getName() && i1.getPrice() == i2.getPrice()
            && i1.getQuantity() == i2.getQuantity());
}

// Overloaded output stream operator to output the item details.
ostream& operator <<(ostream& outs, const Item& source)
{
    outs << source.getName() << ",   $" << source.getPrice() << ",   " << source.getQuantity() << endl;
    return outs;
}
