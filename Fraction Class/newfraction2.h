#ifndef FRAC_H
#define FRAC_H

#include <iostream>
using namespace std;

template<class ItemType>
class fraction
{
private:
    double n;
    double d;

public:
    /**
     * Constructor.
     * @pre none
     * @post Sets the numerator and denominator back to initial values.
     */
    fraction();

    /**
     * Sets the numerator.
     * @param n_amount the amount to set as the numerator.
     * @pre None
     * @post The numerator has been set into the fraction.
     */
    void set_n(double n_amount);

    /**
     * Sets the denominator.
     * @param d_amount the amount to set as the denominator.
     * @pre None
     * @post The denominator has been set into the fraction.
     */
    void set_d(double d_amount);

    /**
     * Returns the numerator of the fraction.
     * @pre None
     * @post The value returned is the numerator of the fraction.
     */
    double get_n() const { return n; }

    /**
     * Returns the denominator of the fraction.
     * @pre None
     * @post The value returned is the denominator of the fraction.
     */
    double get_d() const { return d; }

    /**
     * Displays the fraction.
     * @pre None
     * @post The fraction is displayed.
     */
    void display_frac();

    /**
     * Computes the sum of two fractions.
     * @param f the second fraction.
     * @pre None
     * @post The sum of f1 and f2 is displayed.
     */
    void operator+(const fraction<ItemType>& f);

    /**
     * Computes the subtraction of two fractions.
     * @param f the second fraction.
     * @pre None
     * @post The sum of f1 and f2 is displayed.
     */
    void operator-(const fraction& f);

    /**
     * Reads the coordinates of a point from the istream.
     * @param ins the istream.
     * @param target a fraction.
     * @pre None
     * @post The numerator and denominator of target have been read from ins.
     *       The return value is the istream ins.
     */
    template<typename T>
    friend istream& operator>>(istream& ins, fraction<T>& target);
};

// Non-member functions

/**
 * Computes the sum of two fractions.
 * @param f1 the first fraction.
 * @param f2 the second fraction.
 * @pre None.
 * @post The sum of f1 and f2 is displayed.
 */
template<class ItemType>
void sum(const fraction<ItemType>& f1, const fraction<ItemType>& f2);

/**
 * Computes the subtraction of two fractions.
 * @param f1 the first fraction.
 * @param f2 the second fraction.
 * @pre None.
 * @post The subtraction of f1 and f2 is displayed.
 */
template<class ItemType>
void sub(const fraction<ItemType>& f1, const fraction<ItemType>& f2);

/**
 * Computes the multiplication of two fractions.
 * @param f1 the first fraction.
 * @param f2 the second fraction.
 * @pre None.
 * @post The multiplication of f1 and f2 is displayed.
 */
template<class ItemType>
void mult(const fraction<ItemType>& f1, const fraction<ItemType>& f2);

/**
 * Computes the division of two fractions.
 * @param f1 the first fraction.
 * @param f2 the second fraction.
 * @pre None.
 * @post The division of f1 and f2 is displayed.
 */
template<class ItemType>
void divide(const fraction<ItemType>& f1, const fraction<ItemType>& f2);

/**
 * Computes the multiplication of two fractions.
 * @param f1 the first fraction.
 * @param f2 the second fraction.
 * @pre None.
 * @post The multiplication of f1 and f2 is displayed.
 */
template<class ItemType>
void operator*(const fraction<ItemType>& f1, const fraction<ItemType>& f2);

/**
 * Computes the division of two fractions.
 * @param f1 the first fraction.
 * @param f2 the second fraction.
 * @pre None.
 * @post The division of f1 and f2 is displayed.
 */
template<class ItemType>
void operator/(const fraction<ItemType>& f1, const fraction<ItemType>& f2);

/**
 * Writes the fraction to the ostream.
 * @param outs the ostream.
 * @param source a fraction.
 * @pre None.
 * @post The numerator and denominator of source have been written to outs.
 *       The return value is the ostream outs.
 */
template<class ItemType>
std::ostream& operator<<(std::ostream& outs, const fraction<ItemType>& source);

#include "newfraction2.cpp"

#endif
