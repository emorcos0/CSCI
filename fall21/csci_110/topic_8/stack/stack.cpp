#include <stdexcept>

#include "stack.h"

void Stack::push(double val)
{
    if(top == MAX_STACK_QTY)
        throw std::runtime_error("stack is full");

    array[top++] = val;
}


double Stack::pop()
{
    if(isEmpty())
        throw std::runtime_error("stack is empty");

    return array[--top];
}


double Stack::peek()
{
    if(isEmpty())
      throw std::runtime_error("stack is empty");

    return array[top - 1];
}


bool Stack::isEmpty()
{
    return top == 0;
}


void Stack::clear()
{
    top = 0;
}
