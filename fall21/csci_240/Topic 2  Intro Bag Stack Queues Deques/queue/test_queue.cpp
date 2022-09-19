#include <iostream>
#include <stdexcept>
#include "queue.h"
#include "array_queue.h"
#include"linked_queue.h"



const int TEST_VAL{5};
const int TEST_VALS[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const size_t TEST_VALS_SIZE{11};

void testEnqueueFront(Queue<int> *queue);
void testDequeue(Queue<int> *queue);

int main(int argc, char const *argv[])
{
    try
    {
        testEnqueueFront(new ArrayQueue<int>);
        testDequeue(new ArrayQueue<int>);

        testEnqueueFront(new LinkedQueue<int>);
        testDequeue(new LinkedQueue<int>);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void testEnqueueFront(Queue<int> *queue)
{
    queue->enqueue(TEST_VAL);
    if (queue->front() != TEST_VAL)
        throw std::runtime_error("FAIL: Displayed wrong value at front.");
    if (queue->empty())
        throw std::runtime_error("FAIL: The queue is returning that it is empty when it should have a queued item.");

    delete queue;
    std::cout << "PASSED: Front value matches the one and only enqueued value.\n";
    std::cout << "PASSED: Empty returned false as the queue had the test value in it.\n";
}

void testDequeue(Queue<int> *queue)
{
    for (size_t i = 0; i < TEST_VALS_SIZE; ++i)
        queue->enqueue(TEST_VALS[i]);

    if (queue->front() != TEST_VALS[0])
        throw std::runtime_error("FAIL: The front value does not match the first value entered into the queue.");

    if (queue->front() != queue->dequeue())
        throw std::runtime_error("FAIL: The dequeued value does not match the front value.");

    if (TEST_VALS[1] != queue->dequeue())
        throw std::runtime_error("FAIL:The first element in the queue is not the element that should be dequeued next.");

    if (queue->empty())
        throw std::runtime_error("FAIL: The queue is returning that it is empty when it should have a queued item.");

    queue->clear();

    if (!(queue->empty()))
        throw std::runtime_error("FAIL: The queue is returning that it is NOT empty when it should NOT have any queued items.");

    delete queue;
    std::cout << "PASSED: The front item of the queue is the same as the item that is dequeued from the queue.\n";
    std::cout << "PASSED: The values are dequeued in the order they are input.\n";
    std::cout << "PASSED: Clearing the queue does return an empty queue.\n";
}
