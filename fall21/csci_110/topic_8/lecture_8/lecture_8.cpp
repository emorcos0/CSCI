// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.


#include <iostream>
#include "pet.h"
#include "dog.h"
#include "cat.h"



int main(int argc, char const *argv[])
{
	Pet* pets[]
    {
         new Dog{"A654321", "Fido", "Terrier"},
         new Cat{"A655555", "Fluffy", "Siamese"}
    };
	
    for (int i = 0; i < 2; i++)
    {
       std::cout << pets[i]->getId() << " " << pets[i]->getName() << " " << pets[i]->getSpecies()  << " says " << pets[i]-> speak() <<  " of breed " << pets[i]->getBreed() << std::endl;
    }
    
    
    
	return 0;
}
