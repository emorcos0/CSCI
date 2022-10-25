
// include template here

#include <iostream>
#include <cstdlib>
#include <ctime>

//int randomRange(int, int);

// int main()
// {
//     srand(time(NULL));
//     int count{0};

//     for(size_t i{0}; i < 1000; ++i)
//     {
//         if(randomRange(1,1000) <= 35) { ++count; std::cout << "A new person enters the building.\n";}
//     }

//     std::cout << count << std::endl;
//     return 0;
// }

int randomRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}