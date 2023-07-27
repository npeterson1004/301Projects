/* Thid program demonstrates a faction class used as peramters
    Along with the use of opererating overlaoding.
    
    Name: Nathan Peterson
    StarID: qw3581ym
    Due: June: 30, 2023
    Intructor: Jie Meichsner
*/

#include<iostream>
#include "newfraction.h"
using namespace std;


int main()
{
    double n ,d;
    fraction<double> f1, f2;

    cout << "Enter the numerator of a fraction:";
    cin >> n;
    f1.set_n(n);
    cout << "Enter the denominator of a fraction:";
    cin >> d;
    f1.set_d(d);
    cout << "Your Fraction:";
    f1.display_frac();

    cout << "Enter the numerator of a 2nd fraction:";
    cin >> n;
    f2.set_n(n);
    cout << "Enter the denominator of a 2nd fraction:";
    cin >> d;
    f2.set_d(d);
    cout << "Your 2nd Fraction:";
    f2.display_frac();

    
    cout << "Your Fractions Added:";
    sum(f1, f2);
    cout << endl;

    cout << "Your Fractions Subtracted:";
    sub(f1, f2);
    cout << endl;

    cout << "Your Fractions Multiplied:";
    mult(f1, f2);
    cout << endl;

    cout << "Your Fractions Divided:";
    divide(f1, f2);
    cout << endl;


    return 0;
}