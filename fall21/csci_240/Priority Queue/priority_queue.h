#include "queue.h"
#include "ordered_heap.h"
#include <stdexcept>
#include <functional>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define DEFAULT_SIZE 15

template <typename T>
class PriorityQueue : public Queue<T>
{
public:
    PriorityQueue(std::function<bool(T, T)> comparator) : heap{comparator}
    {
       
    }

    PriorityQueue(const T array[], size_t size, std::function<bool(T, T)> comparator) : heap{array,size,comparator}
    {

    }

    PriorityQueue(size_t initialSize, std::function<bool(T, T)> comparator) :  heap{initialSize,comparator}
    {

    }
    void enqueue(T item)
    {
        heap.add(item);
    }

    T dequeue()
    {
        return heap.remove();
    }

    T front()
    {
        return heap.root();
    }

    bool empty() { return heap.size() == 0; }

    void clear()
    {
        heap.clear();
    }

private:
    OrderedHeap<T> heap;
};

#endif