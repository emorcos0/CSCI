#include <iostream>
#include <array>




namespace msac
{
    void printArray(const std::array<int, 4> &a)
    {
        std::cout << sizeof a << std::endl;
        std::cout << "[ ";
        for (int i = 0; i < a.size(); i++)
        {
            std::cout << a.at(i) << ' ';
        }

        std::cout << "]";
    }

}

using namespace msac;

int main(int argc, char const *argv[])
{
    std::array<int, 4> array{1, 2, 3, 4};

    printArray(array);
    //msac::printArray(array); if "using namespace msac" was not included
    //std::printArray(array); this can be used if msac is renamed to std.

    return 0;
}
