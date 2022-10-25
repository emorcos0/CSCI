#include <iostream>
#include "pet.h"
#include "dog.h"
#include "cat.h"


int main(int argc, char const *argv[])
{
    Pet* pets[] {new Cat{"Frisky"}, new Dog {"Fido"}};

    //Pet p{"N/A", "N/A"};

    for (size_t i = 0; i < 2; i++) 
    std::cout << pets[i]->speak() << std::endl;
    
    

    // Pet p{"UA", "UA"};
    // Dog d {"Fido"};


    // std::cout << p.speak() << std::endl;    
    // std::cout << d.speak() << std::endl;  
    return 0;
}
