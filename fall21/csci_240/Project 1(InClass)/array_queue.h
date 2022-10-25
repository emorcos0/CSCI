#include <stdexcept>
#include "queue.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define DEFAULT_SIZE 20
#define SCALING_FACTOR 2

template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue() : store{new T[DEFAULT_SIZE]}, currentSize{DEFAULT_SIZE} {}

    bool empty()
    {
        if(this->count == 0) return true;
        return false;
    }

    bool enqueue(T item)
    {
        if (this->count >= currentSize)
            resize();

        store[this->count++] = item;
        return true;
    }

    T dequeue()
    {
        if (this->count == 0)
            throw std::runtime_error("The queue is empty.");
        T temp{store[0]};
        reorder();
        --this->count;
        return temp;
    }

    T front()
    {
        if (this->count == 0)
            throw std::runtime_error("The queue is empty.");
        return store[0];
    }

    void clear()
    {
        this->count = 0;
    }

private:
    T *store;
    size_t currentSize;

    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    void resize()
    {
        currentSize *= SCALING_FACTOR;
        T *newStore{new T[currentSize]};

        for (size_t i{0}; i < this->count; ++i)
            newStore[i] = store[i];

        delete[] store;

        store = newStore;
    }

    void reorder()
    {
        for (size_t i = (this->count - 1); i > 0; --i)
        {
            swap(store[i], store[0]);
        }
    }
};

#endif