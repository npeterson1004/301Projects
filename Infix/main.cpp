

#include <iostream>
#include <string>
#include "infix.h"
using namespace std;




int main()
{
    Infix x;
    string postfix;
    
    string input;
    label1:
    cout<<"Enter Infix: " << endl;
    cout << "-->";
    cin >> input;
    x.setInfix(input);
    if(x.validate() == true)
    {
        cout << "incorrect input, try again!" << endl;
        goto label1;
    }
    
    postfix = x.convert();
    
    cout << "Postfix orientation: " << postfix << endl;
    cout << "Calculation: " << x.evaluate(postfix) << endl;
    
   
   
    return 0;
}
