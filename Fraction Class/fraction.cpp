#include <iostream>
#include "fraction.h"
#include <math.h>
using namespace std;

template<class ItemType>
fraction<ItemType>::fraction()
{
	    n = 0.0;   // Constructor sets values to a given position
		d = 1.0;
		    
}	   


//set the numerator of the fraction
template<class ItemType>
void fraction<ItemType>::set_n(double n_amount)
{
    n = n_amount;
}
    
//set the denominator of the fraction
template<class ItemType>
void fraction<ItemType>::set_d(double d_amount)
{
    d = d_amount;
}
    
//dispalys the fraction
template<class ItemType>
void fraction<ItemType>::display_frac()
{
    cout << n << "/" << d << endl;
}
    