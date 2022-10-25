#include <iostream>
#include <functional>
#include <stdexcept>
#include "ordered_heap.h"
#include "priority_queue.h"

#define SIZE 20

template <typename T>
void testMaxAddRoot(PriorityQueue<T> heap)
{
    for (size_t i{0}; i < 15; ++i)
        heap.enqueue(i);
    heap.enqueue(25);
    heap.enqueue(19);

    if (heap.front() != 25)
        throw std::runtime_error("FAILED: ROOT OF HEAP IS NOT THE LARGEST VALUE\n");
    std::cout << "SUCCESS: ROOT OF HEAP IS THE LARGEST VALUE\n";
}

template <typename T>
void testMaxRemoveEmptyClear(PriorityQueue<T> heap)
{
    for (size_t i{0}; i < 15; ++i)
        heap.enqueue(i);
    heap.enqueue(25);
    heap.enqueue(19);

    if (heap.empty())
        throw std::runtime_error("FAILED: HEAP IS EMPTY WHEN IT SHOULD NOT BE\n");
    if (heap.dequeue() != 25)
        throw std::runtime_error("FALIED: ITEM DEQUEUED IS NOT THE LARGEST ITEM\n");
    if (heap.dequeue() != 19)
        throw std::runtime_error("FALIED: ITEM DEQUEUED IS NOT THE LARGEST ITEM\n");
    heap.clear();
    if (!heap.empty())
        throw std::runtime_error("FAILED: HEAP IS NOT EMPTY AFTER CLEAR\n");

    std::cout << "SUCCESS: HEAP DEQUEUES THE LARGEST ITEM\n";
    std::cout << "SUCCESS: HEAP CLEARS AND IS EMPTY WHEN IT SHOULD BE\n";
}

template <typename T>
void testMinAddRoot(PriorityQueue<T> heap)
{
    for (size_t i{0}; i < 15; ++i)
        heap.enqueue(i);
    heap.enqueue(25);
    heap.enqueue(19);

    if (heap.front() != 0)
        throw std::runtime_error("FAILED: ROOT OF HEAP IS NOT THE SMALLEST VALUE\n");
    std::cout << "SUCCESS: ROOT OF HEAP IS THE SMALLEST VALUE\n";
}

template <typename T>
void testMinRemoveEmptyClear(PriorityQueue<T> heap)
{
    for (size_t i{0}; i < 15; ++i)
        heap.enqueue(i);
    heap.enqueue(25);
    heap.enqueue(19);

    if (heap.empty())
        throw std::runtime_error("FAILED: HEAP IS EMPTY WHEN IT SHOULD NOT BE\n");
    if (heap.dequeue() != 0)
        throw std::runtime_error("FALIED: ITEM DEQUEUED IS NOT THE SMALLEST ITEM\n");
    if (heap.dequeue() != 1)
        throw std::runtime_error("FALIED: ITEM DEQUEUED IS NOT THE SMALLEST ITEM\n");
    heap.clear();
    if (!heap.empty())
        throw std::runtime_error("FAILED: HEAP IS NOT EMPTY AFTER CLEAR\n");

    std::cout << "SUCCESS: HEAP DEQUEUES THE SMALLEST ITEM\n";
    std::cout << "SUCCESS: HEAP CLEARS AND IS EMPTY WHEN IT SHOULD BE\n";
}


int main(int argc, char const *argv[])
{

    PriorityQueue<int> maxHeap{(
        [](int l, int r)
        { return l > r; })};

    PriorityQueue<int> minHeap{(
        [](int l, int r)
        { return l < r; })};

    int array[SIZE]{};
    for (size_t i{0}; i < 20; ++i)
        array[i] = i;

    PriorityQueue<float> maxFloatHeap{SIZE, [](float left, float right)
                                   { return left > right; }};

    PriorityQueue<int> minIntHeapArr{array, SIZE, [](int left, int right)
                                  { return left < right; }};

    try
    {
        testMaxAddRoot<int>(maxHeap);
        testMaxRemoveEmptyClear<int>(maxHeap);
        std::cout << std::endl;

        testMinAddRoot<int>(minHeap);
        testMinRemoveEmptyClear<int>(minHeap);
        std::cout << std::endl;

        testMaxAddRoot<float>(maxFloatHeap);
        testMaxRemoveEmptyClear<float>(maxFloatHeap);
        std::cout << std::endl;

        testMinAddRoot<int>(minIntHeapArr);
        testMinRemoveEmptyClear<int>(minIntHeapArr);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
