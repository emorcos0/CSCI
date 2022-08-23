
#ifndef STACK_H
#define STACK_H
#include <stdexcept>

template <typename T, size_t N>
class Stack
{
public:
    bool isEmpty() { return top == 0; }

    T peek()
    {
        if (isEmpty())
            throw std::runtime_error("stack is empty");

        return array[top - 1];
    }

    T pop()
    {
        if (top == 0)
            throw std::runtime_error("stack is empty");

        return array[top--];
    }

    void push(T val)
    {
        if (top == N)
            throw std::runtime_error("stack is full");

        array[top++] = val;
    }

    void clear() { top = 0; }

private:
    T array[N];
    int top{0};
};

#endif
