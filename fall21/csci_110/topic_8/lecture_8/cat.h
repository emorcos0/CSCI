#include <string>

#include "pet.h"

#ifndef CAT_H
#define CAT_H

class Cat : public Pet
{
public: 
    Cat(std::string id, std::string name, std::string breed) : Pet(id, name, "Cat"), breed{breed} { }
  

    std::string getBreed(){return breed;}

    std::string speak() { return "Meow";}
private:
    std::string breed;
};


#endif