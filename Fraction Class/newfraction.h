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

 //NONMEMBER FUNCTION
    /** computes the sum of two fractions
    /* @param f1 is the second fraction
    /* @pre None
    /* @post The sum of p1 and p2 is dispalyed*/
		template<class ItemType>
        void sum(const fraction<ItemType>& f1, const fraction<ItemType>& f2);


    /** computes the subtraction of two fractions
    /* @param f is the second fraction
    /* @pre None
    /* @post The sum of p1 and p2 is displayed*/
		template<class ItemType>
        void sub(const fraction<ItemType>& f1, const fraction<ItemType>& f2);
        
        
    /** computes the multiplication of two fractions
    /* @param f is the second fraction
    /* @pre None
    /* @post The multiplication of p1 and p2 is dsiplayed*/
		template<class ItemType>
        void mult(const fraction<ItemType>& f1, const fraction<ItemType>& f2);
        
            
    /** computes the multiplication of two fractions
    /* @param f is the second fraction
    /* @pre None
    /* @post The multiplication of p1 and p2 is dsiplayed*/
		template<class ItemType>
        void divide(const fraction<ItemType>& f1, const fraction<ItemType>& f2);



#include "newfraction.cpp"

#endif