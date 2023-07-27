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

    /** Contructor;
    * @pre none
    * @post sets the num and denominator back to inital values*/
    fraction();

  

    /** sets the numerator
	/* @param n_amount the amount to move along the x axis
	/* @pre None
	/* @post The numerator has been set into the fraction */
    void set_n(double n_amount);
        
                
	/** sets the denominator
	/* @param d_amount the amount to move along the x axis
	/* @pre None
	/* @post The drnominator has been set into the fraction */
    void set_d(double d_amount);
        
        
	/** returns the numerator.
	/* @pre None
	/* @post The value returned is the numerator of the fraction.*/
    double get_n( ) const { return n; } 

	/** returns the denominator of the fraction.
	/* @pre None
	/* @post The value returned is the denominator fo the fraction.*/
    double get_d( ) const { return d; }
 
    /** Displays the fraction.
	/* @pre None
	/* @post the fraction is displayed*/
	void display_frac();
	

};

#include "fraction.cpp"

#endif