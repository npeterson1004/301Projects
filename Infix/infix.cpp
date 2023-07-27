#include <iostream>
#include <string>
#include <stack>
#include "infix.h"

using namespace std;

Infix::Infix()
{
     //contructor
}

void Infix::setInfix(string input)
{
    infixExp = input;
}



bool Infix::validate()
{
    int len = infixExp.length();
    
    for(int i = 0; i < len; i++)
    {
        if(infixExp[i] == ' ')
        {
            return true;
        }
        else if (IsOperand(infixExp[i]) == false)
        {
            if(IsOperator(infixExp[i]) == false)
            {
                if(parenthesis(infixExp[i]) == false)
                {
                    return true;
                }
            }
           
        }
        
       
    }
    
    return false;
}


bool Infix::parenthesis(char entry)
{
    
    if(entry == '(' || entry == ')')
    {
        return true;
    }
    else{
        return false;
    }
}

bool Infix::IsOperator(char entry)
{
    if(entry == '+' || entry == '-' || entry == '*' || entry == '/')
    {
        return true;
    }
    else{
        return false;
    }
}


int Infix::GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
{
    case '+':
    case '-':
    weight = 1;
    case '*':
    case '/':
    weight = 2;
    case '$':
    weight = 3;
}
    return weight;
}

// Function to perform an operation and return output.
int Infix::HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
        {

            return true;
        }
    return op1Weight > op2Weight ? true: false;
}


bool Infix::IsOperand(char entry)
{
    if(entry >= '0' && entry <= '9') return true;
    return false;
}

// Function to evaluate Postfix expression and return output
string Infix::convert()
{
    bool isMathOperatorRepeated = false;
    bool isOperaendRepeated = false;
    
    // Declaring a Stack from Standard template library in C++.
    stack<char> S;
    string postfix = ""; // Initialize postfix as empty string.
    for(int i = 0;i< infixExp.length();i++) 
    {
        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(infixExp[i] == ' ' || infixExp[i] == ',') continue;
        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(infixExp[i]))
        {
            
            if(isMathOperatorRepeated)
            {
                postfix = "Wrong Expression";
                /*
                After this for loop there is while loop
                which is checking rest of the char and add it with postfix string .
                So this pushed char should be pop out
                beacuse infix expression is wrong.
                */
                while (!S.empty())
                    {
                        S.pop();
                    }
                break;
             }
                            
            while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),infixExp[i]))
                {
                    postfix+= S.top();
                    S.pop();
                }
            S.push(infixExp[i]);
            isMathOperatorRepeated = true;
            isOperaendRepeated = false;
        }

        // Else if character is an operand
        else if(IsOperand(infixExp[i]))
        {
            if(isOperaendRepeated)
            {
                postfix = "Wrong Expression";
                /*
                After this for loop there is while loop
                which is checking rest of the char and add it with postfix string .
                So this pushed char should be pop out
                beacuse infix expression is wrong.
                */

                while (!S.empty())
                {
                    S.pop();
                }
                break;
            }

            postfix +=infixExp[i];
            isMathOperatorRepeated = false;
            isOperaendRepeated = true;
        }

        else if (infixExp[i] == '(')
        {
            S.push(infixExp[i]);
            isMathOperatorRepeated = false;
            isOperaendRepeated = false;
        }

        else if(infixExp[i] == ')')
        {
            while(!S.empty() && S.top() != '(') 
            {
                postfix += S.top();
                S.pop();
            }
            
            if(S.empty())
            {
                postfix = "Wrong Expression";
                break;
            }

            else
            {
                S.pop();
            }

            // poping the opening bracket
            isMathOperatorRepeated = false;
            isOperaendRepeated = false; 
            
        }

    }

    while(!S.empty()) 
    {
    postfix += S.top();
    S.pop();
    }

    return postfix;
}

double Infix::eval(double op1, double op2, char ch) 
{
    switch (ch) {
    case '*': return op2 * op1;
    case '/': return op2 / op1;
    case '+': return op2 + op1;
    case '-': return op2 - op1;
    default : return 0;
    }
}

double Infix::evaluate(string entry) 
{
    string fix = entry;
    stack<int> s;
    int size = fix.length();
    int i = 0;
    char ch;
    double ans;
    while (i < size) 
    {
        ch = fix[i];
    
        if (isdigit(ch)) 
        {
            // we saw an operand
            // push the digit onto stack
            s.push(ch-'0');
        }
        else 
        {
            // we saw an operator
            // pop off the top two operands from the
            // stack and evalute them using the current
            // operator
            double op1 = s.top();
            s.pop();
            double op2 = s.top();
            s.pop();
            ans = eval(op1, op2, ch);
        
           
          
            // push the value obtained after evaluating
            // onto the stack
             s.push(ans);
        }
        i++;
    }
    return ans;
}



