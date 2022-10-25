#include <iostream>
#include <array>

void printArray(int a[], size_t size)
{
    std::cout << sizeof a << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << ' ';
    }

    std::cout << "]";
    
}

void printArray(const std::array<int, 4>& a)
{
    std::cout << sizeof a << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a.at(i) << ' ';
    }

    std::cout << "]";
    
}

// int main(int argc, char const *argv[])
// {
//     int array[20]{1,2,3,4};


//     std::array<int, 4> array2 {1,2,3,4};
//     //std::cout << sizeof(array) << std::endl;
//     //printArray(array, sizeof(array) >> 2);
//     printArray(array2);

    


//     return 0;
// }
