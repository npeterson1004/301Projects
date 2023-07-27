/* Thid program demonstrates a faction class used as peramters
    Along with the use of opererating overlaoding.
    
    Name: Nathan Peterson
    StarID: qw3581ym
    Due: June: 30, 2023
    Intructor: Jie Meichsner
*/

#include <iostream>
#include <string>
#include "newfraction2.h"

using namespace std;

int main()
{
    double n, d;
    fraction<double> f1, f2;

    while (true)
    {
        cout << "Enter the numerator of a fraction: ";
        cin >> n;
        f1.set_n(n);
        
        cout << "Enter the denominator of a fraction: ";
        cin >> d;
        f1.set_d(d);
        
        cout << "Your Fraction: " << f1;
        cout << endl;
  
        
        cout << "Enter the numerator of a 2nd fraction: ";
        cin >> n;
        f2.set_n(n);
        
        cout << "Enter the denominator of a 2nd fraction: ";
        cin >> d;
        f2.set_d(d);
        
        cout << "Your 2nd Fraction: " << f2;
        cout << endl;
        
        cout << "_________________________________________" << endl;
        cout << endl;
    
        cout << "Your Fractions Added: " ;
        f1.operator +(f2);
        cout << endl;

        cout << "Your Fractions Subtracted: " ;
        f1.operator -(f2);
        cout << endl;

        cout << "Your Fractions Multiplied: " ;
        operator *(f1, f2);
        cout << endl;

        cout << "Your Fractions Divided: ";
        operator *(f1, f2);
        cout << endl;
        
        cout << "_________________________________________" << endl;
        cout << endl;
        
        string b;
        cout << "Do you want to try another fraction? (y/n)" << endl;
        
        while (true)
        {
            cout << "-> ";
            cin >> b;
            
            if (b == "y" || b == "n")
                break;
            
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
        
        if (b == "n")
            break;
        
        cout << endl;
    }

    return 0;
}