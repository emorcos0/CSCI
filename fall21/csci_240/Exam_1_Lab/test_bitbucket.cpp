#include <iostream>
#include "bit_bucket.h"

#define TEST_POS 999
int main(int argc, char const *argv[])
{
    BitBucket<1000> bb;

    for (size_t i{0}; i < 1000; ++i)
        if (bb.at(i))
            std::cout << "got a prob with the bucket\n";

    bb.set(TEST_POS);

    for (size_t i{0}; i < 1000; ++i)
        if (bb.at(i))
            std::cout << " have a bit set at " << i << std::endl;

    bb.unset(TEST_POS);

    for (size_t i{0}; i < 1000; ++i)
        if (bb.at(i))
            std::cout
                << "got a prob with the bucket\n";

    try
    {
        bb.at(1000);
        std::cout << "FAIL: did not throw exception on bound check\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "PASS: Threw an exception on an out of bounds call";
    }
    

    return 0;
}
