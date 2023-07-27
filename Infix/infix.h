#ifndef _INFIX_
#define _INFIX_

#include <iostream>
#include <string>

using namespace std;

class Infix
{
    private:
        //private variables
        string infixExp;
        string postfix;
        int ans;
        char op1, op2;
        
        
        /** Ranks the operortors by order of pemdas
        @post If successful, fuction returns a value per specific operator
        @param op, input an operator 
        @return integer "weight" as per operotor  */
        int GetOperatorWeight(char op);
        
        
        /** checks if input is an operator
        @post If successful, fuction returns a boolean 
        @param op, input an operator 
        @return bool true or false if input is an operator or not */
        bool IsOperator(char entry);
        
         /** checks if input is an operand
        @post If successful, fuction returns a boolean 
        @param op, input an operand 
        @return bool true or false if input is an operad or not */
        bool IsOperand(char entry);
        
         /** compares weight of operators
        @post If successful, operatro eith greater weight
        @param op, input two operators to compare
        @return the greater weighted operator */
        int HasHigherPrecedence(char op1, char op2);
        
         /** calcuate the arithmic operations
        @post If successful, fuction returns a double of the calculated value 
        @param op, input two values to be operated 
        @return double if the calulated operation*/
        double eval(double op1, double op2, char ch);
        
        
        

        /** checks if the expression has parenthesis
        @post If successful, fuction returns a boolean 
        @param none 
        @return bool true or false if expression has parenthesis */
        bool parenthesis(char entry);
        
        
    public:
    
        Infix();
        
        /** sets the infix expression into the class
        @post If successful, fuction adds the users input into the class 
        @param string of the expression
        @return none */
        void setInfix(string input);
        
        /** evaluates the value of the expression
        @post If successful, fuction retruned the vlaue of the expression 
        @param string of the expression
        @return value of expression */
        double evaluate(string entry);
        
        /** converts the infix to postfix exopression
        @post If successful, expression is converted to postfix
        @param none
        @return postfix expression */
        string convert();
        
        /** checks if the expresssion is valid
        @post If successful, fuction returns a bool value 
        corressponign the the correctbness of the expression
        @param noen
        @return boolean wether the expression is in the correct format */
        bool validate();
};

#include "infix.cpp"


#endif