
#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 1;
    for (int i = 1; i <= 10; i)
        std::cout << i++ << std::endl;

    std::cout << i << std::endl;

        {
            int i = 1;
            while(i <= 10)
             std::cout << i++ << std::endl;
        }

    
        

    return 0;
}
