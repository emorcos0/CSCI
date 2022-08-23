// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include "stack.h"



int main(int argc, char const *argv[])
{
    Stack stack;
    double val;
    bool isCorrect{true};

	std::cout << "testing isEmpty\n"; 
    std::cout << "the stack is initially " << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << "testing not isEmpty by adding 10 values [0 - 9]\n"; 
    for (int i = 0; i < 10; i++)
        stack.push(i);
    
    std::cout << "the stack is " << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    val = 9;
    while(!stack.isEmpty())
    {
        if(stack.pop() != val--)
        {
            std::cout << "the values did not pop in the correct order\n";
            isCorrect = false;
            break;
        }
    }
    if(isCorrect)
        std::cout << "the values did pop in the correct order\n";

    std::cout << "testing clear by adding the value 10 \n"; 
    stack.push(10);    
    stack.clear();
    std::cout << "the stack is " << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    try
    {
        for (int i = 0; i <= MAX_STACK_QTY; i++)
            stack.push(i);
        std::cout << "did not catch exception on stack overflow\n";
            
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "caught exception on stack overflow\n";
    }
    
    try
    {
        for (int i = 0; i <= MAX_STACK_QTY; i++)
            stack.pop();
        std::cout << "did not catch exception on pop on empty stack\n";
            
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "caught exception on pop on empty stack\n";
    }

    try
    {
        stack.clear();
        stack.peek();
        std::cout << "did not catch exception for peek on empty stack\n";
            
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "caught exception on peek on empty stack\n";
    }
    
    std::cout << "now testing the peek funciton by adding value 8\n";
    stack.push(8);
    std::cout << "now peeking on the value " << stack.peek();
    




	return 0;
}

