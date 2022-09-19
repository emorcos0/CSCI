#include <iostream>
#include <stdexcept>

#include "bag.h"
#include "array_bag.h"
#include "linked_bag.h"

const int TEST_VAL{5};
const int TEST_VALS[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const size_t TEST_VALS_SIZE{11};

void testAdd_Size(Bag<int> *bag);
void testContains(Bag<int> *bag);
void testContainsUsingArray(Bag<int> *bag);

int main(int argc, char const *argv[])
{

    try
    {
        // test arraybag
        testAdd_Size(new ArrayBag<int>);

        testContains(new ArrayBag<int>);

        testContainsUsingArray(new ArrayBag<int>);

        //test linkedbag
        testAdd_Size(new LinkedBag<int>);

        testContains(new LinkedBag<int>);

        testContainsUsingArray(new LinkedBag<int>);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void testAdd_Size(Bag<int> *bag)
{
    bag->add(TEST_VAL);
    if (bag->size() != 1)
        throw std::runtime_error("FAIL: Tested Add function. Size did not return correct value.");

    delete bag;
    std::cout << "PASS: Add Passed.\n";
}

void testContains(Bag<int> *bag)
{
    bag->add(TEST_VAL);

    if (!bag->contains(TEST_VAL))
        throw std::runtime_error("FAIL: Tested Contains function. Did not report membership.");

    delete bag;
    std::cout << "PASS: Contains Passed.\n";
}

void testContainsUsingArray(Bag<int> *bag)
{
    for (size_t i = 0; i < TEST_VALS_SIZE; ++i)
        bag->add(TEST_VALS[i]);

    if (!bag->contains(TEST_VALS[0]))
        throw std::runtime_error("FAIL: Tested Contains function on first item added. Did not report membership.");

    if (!bag->contains(TEST_VALS_SIZE - 1))
        throw std::runtime_error("FAIL: Tested Contains function on last item added. Did not report membership.");

    if (!bag->contains(TEST_VALS[TEST_VALS_SIZE >> 1]))
        throw std::runtime_error("FAIL: Tested Contains function on middle item added. Did not report membership.");

    if (bag->contains(0))
        throw std::runtime_error("FAIL: Tested Contains function on value not added. Report membership.");

    delete bag;

    std::cout << "PASS: Contains on multiple values Passed.\n";
}
