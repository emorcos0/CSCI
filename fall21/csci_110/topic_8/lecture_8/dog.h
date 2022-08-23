#include <string>

#include "pet.h"

#ifndef DOG_H
#define DOG_H

class Dog : public Pet
{
public: 
    Dog(std::string id, std::string name, std::string breed) : Pet(id, name, "Dog"), breed{breed} { }
 

    std::string getBreed(){return breed;}

    std::string speak() { return "Woof";}
private:
    std::string breed;
};


#endif