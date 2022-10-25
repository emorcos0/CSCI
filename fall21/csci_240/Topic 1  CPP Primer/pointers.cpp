

#include "pointers.h"
#include "arrays.h"

int main(int argc, char const *argv[])
{

    int array[]{1, 2, 3, 4, 5};

    printArray<int, 5>(array);

    // int *a{nullptr}; //can use NULL and 0 when initializing a null pointer
    // int b{55};

    // a = &b;

    // std::cout << a << ' ' << *a << std::endl;

    // *a = 10;

    // std::cout << a << ' ' << *a++ << std::endl; //having ++*a instead would output 11

    // std::cout << a << ' ' << *a << std::endl;

    return 0;
}

// void printArray(int *array, size_t size)
// {
//     int *a{array};
//     std::cout << "[ ";

//     while(a < array + size)
//     {
//         std::cout << *a++ << ' ';

//     }

//     std::cout << "]\n";
// }

// void printArray(int *array, size_t size)
// {
//     int *a{array};
//     std::cout << "[ ";

//     for (size_t i = 0; i < size; i++)
//         std::cout << array[i] << ' '; // can replace 'array' with 'a'
    

//     std::cout << "]\n";
// }