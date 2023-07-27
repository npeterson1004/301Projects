#include <iostream>
#include "newfraction2.h"
#include <math.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Function to convert the obtained fraction
// into its simplest form
void lowest(int &den3, int &num3)
{
    // Finding gcd of both terms
    int common_factor = gcd(num3, den3);
 
    // Converting both terms into simpler
    // terms by dividing them by common factor
    den3 = den3 / common_factor;
    num3 = num3 / common_factor;
    cout << num3 << "/" << den3 << endl;
}

template<class ItemType>
fraction<ItemType>::fraction()
{
    n = 0.0;   // Constructor sets values to a given position
    d = 1.0;
}	   

// Set the numerator of the fraction
template<class ItemType>
void fraction<ItemType>::set_n(double n_amount)
{
    n = n_amount;
}

// Set the denominator of the fraction
template<class ItemType>
void fraction<ItemType>::set_d(double d_amount)
{
    d = d_amount;
}

// Display the fraction
template<class ItemType>
void fraction<ItemType>::display_frac()
{
    cout << n << "/" << d << endl;
}

// Operate the sum of two fractions
template<class ItemType>
void fraction<ItemType>::operator +(const fraction<ItemType>& f)
{
    double n1 = f.get_n();
    double d1 = f.get_d();

    // Finding gcd of den1 and den2
    int den1 = d1;
    int den2 = d;
    int den3 = gcd(den1, den2);
 
    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b
    den3 = (den1 * den2) / den3;
 

    int num1 = n1;
    int num2 = n;
    // Changing the fractions to have the same denominator
    // Numerator of the final fraction obtained
    int num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);
 
    // Calling function to convert final fraction
    // into its simplest form
    lowest(den3, num3);
}

// Operate the subtraction of two fractions
template<class ItemType>
void fraction<ItemType>::operator -(const fraction<ItemType>& f)
{
    double n1 = f.get_n();
    double d1 = f.get_d();

    // Finding gcd of den1 and den2
    int den1 = d;
    int den2 = d1;
    int den3 = gcd(den1, den2);
 
    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b
    den3 = (den1 * den2) / den3;
 

    int num1 = n;
    int num2 = n1;
    // Changing the fractions to have the same denominator
    // Numerator of the final fraction obtained
    int num3 = (num1) * (den3 / den1) - (num2) * (den3 / den2);
 
    // Calling function to convert final fraction
    // into its simplest form
    lowest(den3, num3);
}

template<class ItemType>
// Operate the multiplication of two fractions
void operator *(const fraction<ItemType>& f1, const fraction<ItemType>& f2)
{
    double n1 = f1.get_n();
    double d1 = f1.get_d();

    double newnum = n1 * f2.get_n();
    double newden = d1 * f2.get_d();
    
    cout << newnum << "/" << newden << endl;
}

// Operate the division of two fractions
template<class ItemType>
void operator /(const fraction<ItemType>& f1, const fraction<ItemType>& f2)
{
    double n1 = f1.get_n();
    double d1 = f1.get_d();

    int newden = d1 * f2.get_n();
    int newnum = n1 * f2.get_d();
    
    lowest(newden, newnum);
}

// Output the fraction
template<class ItemType>
ostream& operator <<(ostream& outs, const fraction<ItemType>& source)
{
    outs << source.get_n() << "/" << source.get_d();
    return outs;
}

// Input the fraction
template<class ItemType>
istream& operator >>(istream& ins, fraction<ItemType>& target)
{
    ins >> target.n >> target.d;
    return ins;
}

template<class ItemType>
void sum(const fraction<ItemType>& f1, const fraction<ItemType>& f2)
{
    double n1 = f1.get_n();
    double d1 = f1.get_d();
    double n2 = f2.get_n();
    double d2 = f2.get_d();

    // Finding gcd of den1 and den2
    int den1 = d1;
    int den2 = d2;
    int den3 = gcd(den1, den2);
 
    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b
    den3 = (den1 * den2) / den3;
 

    int num1 = n1;
    int num2 = n2;
    // Changing the fractions to have the same denominator
    // Numerator of the final fraction obtained
    int num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);
 
    // Calling function to convert final fraction
    // into its simplest form
    lowest(den3, num3);
}

template<class ItemType>
void sub(const fraction<ItemType>& f1, const fraction<ItemType>& f2)
{
    double n1 = f1.get_n();
    double d1 = f1.get_d();
    double n2 = f2.get_n();
    double d2 = f2.get_d();

    // Finding gcd of den1 and den2
    int den1 = d1;
    int den2 = d2;
    int den3 = gcd(den1, den2);
 
    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b
    den3 = (den1 * den2) / den3;
 

    int num1 = n1;
    int num2 = n2;
    // Changing the fractions to have the same denominator
    // Numerator of the final fraction obtained
    int num3 = (num1) * (den3 / den1) - (num2) * (den3 / den2);
 
    // Calling function to convert final fraction
    // into its simplest form
    lowest(den3, num3);
}

template<class ItemType>
void mult(const fraction<ItemType>& f1, const fraction<ItemType>& f2)
{
    double n1 = f1.get_n();
    double d1 = f1.get_d();

    double newnum = n1 * f2.get_n();
    double newden = d1 * f2.get_d();
    
    cout << newnum << "/" << newden << endl;
}

template<class ItemType>
void divide(const fraction<ItemType>& f1, const fraction<ItemType>& f2)
{
    double n1 = f1.get_n();
    double d1 = f1.get_d();

    int newden = d1 * f2.get_n();
    int newnum = n1 * f2.get_d();
    
    lowest(newden, newnum);
}
