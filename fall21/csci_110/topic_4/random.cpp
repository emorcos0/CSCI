
// include template here



#include <iostream>
#include <cstdlib>
#include <ctime>

int random(int);
int random(int, int);

int main()
{
    srand(time(NULL));

    for (size_t i = 0; i < 100; i++)
    {  
        std::cout << random(1, 21) << std::endl;
    }
    

}

int random(int end)
{

    return rand() % end;
}

int random(int start, int end)
{
    return rand() % (end-start) + start;
}