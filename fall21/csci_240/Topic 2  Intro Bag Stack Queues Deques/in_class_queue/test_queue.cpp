#include <iostream>
#include <stdexcept>
#include "queue.h"
#include "array_queue.h"
#include "linked_queue.h"

#define TESTVAL 5

void testEnqueue_Empty(Queue<int> *);
void testEnqueue_multiItems(Queue<int> *);
void testDequeue(Queue<int> *);

void testClear(Queue<int> *);

int main(int argc, char const *argv[])
{
    try
    {
        testEnqueue_Empty(new ArrayQueue<int>);
        testEnqueue_multiItems(new ArrayQueue<int>);
        testDequeue(new ArrayQueue<int>);
        testClear(new ArrayQueue<int>);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

void testEnqueue_Empty(Queue<int> *q)
{
    if (!q->empty())
        throw std::runtime_error("FAIL: initially not empty");
    q->enqueue(TESTVAL);

    if (q->empty())
        throw std::runtime_error("FAIL: empty after add");

    std::cout << "SUCCESS: testEnqueue_Empty\n";
}

void testEnqueue_multiItems(Queue<int> *q)
{
    for (int i{1}; i <= 30; ++i)
        q->enqueue(i);

    if (q->empty())
        throw std::runtime_error("FAIL: empty after add");

    std::cout << "SUCCESS: testEnqueue_multiItems\n";
}

void testDequeue(Queue<int> *q)
{
    for (int i{1}; i <= 30; ++i)
        q->enqueue(i);
    for (int i{1}; i <= 30; ++i)
        if (q->dequeue() != i)
            throw std::runtime_error("FAIL: did not dequeue in correct order");

    std::cout << "SUCCESS: testDequeue\n";
}

void testClear(Queue<int> *q)
{
}


