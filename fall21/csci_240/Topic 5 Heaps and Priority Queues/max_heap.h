#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include<functional>

#include "heap.h"

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define ROOT 1
#define DEFAULT_SIZE 15
#define SCALING_FACTOR 2

template <typename T>
class MaxHeap : Heap<T>
{
public:
    MaxHeap() : MaxHeap(DEFAULT_SIZE) {}

    MaxHeap(const T array[], size_t size)
    {

        size_t lastParent{getLastParent(size)};

        currentSize = size * SCALING_FACTOR;

        for (size_t i{0}; i < size; ++i)
            store[i + 1] = array[i];
        //call heapify
        heapify(lastParent);
    }

    MaxHeap(size_t initialSize) : store{new T[initialSize + 1]}, currentSize{initialSize + 1} {}

    void add(T item)
    {
        if (itemQty > currentSize)
            resize();
        //throw std::runtime_error("add on full heap"); only throw this if not dynamically resizable
        store[++itemQty] = item;
        upHeap(itemQty >> 1);
    }

    T root()
    {
        if (itemQty == 0)
            throw std::runtime_error("root on an empty heap");
        return store[1];
    }

    T remove()
    {
        if (itemQty == 0)
            throw std::runtime_error("remove on an empty heap");

        T rtnItem{store[1]};
        store[1] = store[itemQty];
        --itemQty;
        downHeap(1);
        return rtnItem;
    }

    void clear() { itemQty = 0; }

    size_t size() { return itemQty; }

private:
    uint64_t itemQty{0};
    size_t currentSize;
    T *store;
    std::function<bool(T,T)> comparator;

    // void downheap(int parent)
    // {
    //     int lchild = parent * 2;
    //     if (lchild >= itemQty)
    //         return;
    //     int rchild = (parent * 2) + 1;
    //     int rtn = (store[parent] < store[lchild]) ? lchild : parent;
    //     if (rchild <= itemQty)
    //         rtn = (store[rtn] < store[rchild]) ? rchild : rtn;
    //     if (rtn != parent)
    //     {
    //         swap(rtn, parent);
    //         downheap(rtn);
    //     }
    // }

    void downHeap(size_t parentIdx)
    {
        size_t maxIdx;
        if (parentIdx >= itemQty)
            return;

        maxIdx = compare(parentIdx);
        if (maxIdx == parentIdx)
            return;

        swap(maxIdx, parentIdx);

        downHeap(maxIdx);
    }

    void upHeap(size_t parentIdx)
    {
        size_t maxIdx;
        if (parentIdx == 0)
            return;

        maxIdx = compare(parentIdx);
        if (maxIdx == parentIdx)
            return;

        swap(maxIdx, parentIdx);

        upHeap(parentIdx >> 1);
    }

    size_t compare(size_t idx)
    {
        size_t rtn = idx;
        size_t lchild = idx * 2;
        size_t rchild = (idx * 2) + 1;

        if (itemQty >= lchild)
            rtn = (comparator(store[lchild] > store[rtn])) ? lchild : rtn;
        if (itemQty >= rchild)
            rtn = (comparator(store[rchild] > store[rtn])) ? rchild : rtn;

        return rtn;
    }

    void swap(size_t term1, size_t term2)
    {
        T temp = store[term1];
        store[term1] = store[term2];
        store[term2] = temp;
    }

    void resize()
    {
        currentSize *= SCALING_FACTOR;
        T *newStore{new T[currentSize]};

        for (size_t i{0}; i < this->itemQty; ++i)
            newStore[i] = store[i];

        delete[] store;

        store = newStore;
    }

    size_t getLastParent(size_t n)
    {
        return static_cast<size_t>(
            ceil(static_cast<double>(n - 1) / 2.0));

        //(double) n; another way to cast using c-style cast
    }

    void heapify(size_t idx)
    {
        for (size_t i{idx}; i >= ROOT; --i) downHeap(i);
    }

    /*  RECURSIVE VERSION OF HEAPIFY
    void heapify(size_t idx)
    {

        if(idx == 0) return;


        downHeap(idx);



        heapify(idx - 1);
    }
*/
};

#endif