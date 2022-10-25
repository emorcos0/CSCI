#include "queue.h"
#include <stdexcept>

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define DEFAULT_SIZE 16
#define SCALING_FACTOR 2

template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue() : frontIdx{-1}, backIdx{-1}, store{new T[DEFAULT_SIZE]}, currentSize{DEFAULT_SIZE}, count{0} {}

    void enqueue(T item)
    {
        if (count == currentSize)
            resize();

        ++backIdx;
        backIdx %= currentSize;
        store[backIdx] = item;
        ++count;

        if (frontIdx == -1)
            frontIdx = backIdx;
    }

    T dequeue()
    {
        T rtnItem{store[frontIdx++]};

        if (empty()) throw std::runtime_error("Dequeue on empty Queue");

        frontIdx %= currentSize;
        --count;

        return rtnItem;
    }

    T front()
    {
        if (empty()) throw std::runtime_error("Front on empty Queue");
        return store[frontIdx];

    }

    bool empty() { return count == 0; }

    void clear()
    {
        count = 0;
        frontIdx = backIdx = -1;
    }

private:
    size_t currentSize;
    int frontIdx;
    int backIdx;
    size_t count;
    T *store;

    void resize()
    {
        size_t newSize{currentSize * SCALING_FACTOR};
        T *newStore{new T[newSize]};

        for (size_t i = 0; i < count; ++i)
        {
            newStore[i] = store[frontIdx];
            ++frontIdx;
            frontIdx %= currentSize;
        }

        delete[] store;
        store = newStore;
        frontIdx = 0;
        backIdx = count - 1;
        currentSize = newSize;
    }
};

#endif