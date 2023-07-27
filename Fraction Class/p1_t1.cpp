/* Thid program demonstrates a faction class used as peramters
    Along with the use of opererating overlaoding.
    
    Name: Nathan Peterson
    StarID: qw3581ym
    Due: June: 30, 2023
    Intructor: Jie Meichsner
*/

#include<iostream>
#include "fraction.h"
using namespace std;


int main()
{
    double n ,d;
    fraction<double> f1;

    cout << "Enter the numerator of a fraction:";
    cin >> n;
    f1.set_n(n);
    cout << "Enter the denominator of a fraction:";
    cin >> d;
    f1.set_d(d);
    cout << "Your Fraction:";
    f1.display_frac();
    
    return 0;
}