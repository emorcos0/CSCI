#include <iostream>
#include <string>
#define PI 3.141
#define E 2.716
#define MIN(a,b) ( (a < b) ? a : b )

int main(int argc, char const *argv[])
{

    std::string quote;

    std::cout << "The interesting quote: ";
    std::getline(std::cin, quote );

    std::cout << quote << std::endl;

    return 0;
}