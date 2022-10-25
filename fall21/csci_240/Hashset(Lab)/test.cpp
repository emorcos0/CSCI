#include <iostream>
#include <functional>
#include <stdexcept>
#include "hashset_lp.h"
#include "hashset_qp.h"

template <typename T>
void testInsertContains(T hash)
{
    for (size_t i = 0; i < 160; i++)
        hash.insert(i);

    for (size_t i = 0; i < 160; i++)
        if (!hash.contains(i))
            throw std::runtime_error("FAILED: DOES NOT CONTAIN AN ADDED VALUE.\n");
    if (hash.contains(1400))
        throw std::runtime_error("FAILED: CONTAINS AN UNADDED VALUE.\n");
    if (hash.contains(1556))
        throw std::runtime_error("FAILED: CONTAINS AN UNADDED VALUE.\n");

    std::cout << "SUCCESS: CONTAINS ADDED VALUES.\n";
    std::cout << "SUCCESS: DOES NOT CONTAIN EXTRANEOUS VALUES. \n";
}

template <typename T>
void testFindErase(T hash)
{
    for (size_t i = 0; i < 10; i++)
        hash.insert(i);

    int x;
    for (size_t i = 0; i < 10; i++)
    {
        x = *hash.find(i);
        if (x != i)
            throw std::runtime_error("FALIED: FOUND POINTER DOES NOT POINT TO SPECIFIED VALUE.\n");
    }


    hash.erase(4);
    if (hash.contains(4))
        throw std::runtime_error("FAILED: CONTAINS AN ERASED VALUE. \n");

    std::cout << "SUCESS: FOUND CORRECT POINTER TO VALUE.\n";
    std::cout << "SUCCESS: ERASED VALUE NO LONGER CONTANIED. \n";
}

int main(int argc, char const *argv[])
{
    HashSetLP<int> lhash{[](int k)
                         { return k; }};

    HashSetQP<int> qhash{[](int k)
                         { return k; }};

    try
    {
        testInsertContains<HashSetLP<int>>(lhash);
        testFindErase<HashSetLP<int>>(lhash);
        std::cout << std::endl;
        testInsertContains<HashSetQP<int>>(qhash);
        testFindErase<HashSetQP<int>>(qhash);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
