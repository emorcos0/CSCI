#include <stdexcept>

#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
    virtual bool enqueue(T item) = 0;
    virtual T dequeue() = 0;
    virtual T front() = 0;
    virtual bool empty() = 0;
    virtual void clear() = 0;

    Queue() : count{0} { } 
protected:
    size_t count;

};



#endif