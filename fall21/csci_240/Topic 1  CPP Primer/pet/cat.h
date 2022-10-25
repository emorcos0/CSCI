#include "pet.h"

#include <string>

#ifndef CAT_H
#define CAT_H

class Cat : public Pet
{
public:
    Cat(const std::string&);
    std::string speak();



};

#endif