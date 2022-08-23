#include <string>
#include <stdexcept>
#ifndef PET_H
#define PET_H

class Pet
{
public:
    Pet(std::string id, std::string name, std::string species) : id{id}
    {
        if(!name.empty())
            this->name = name;
        else
            throw std::invalid_argument("Name cannot be empty");

        if(!species.empty())
            this->species = species;
        else
            throw std::invalid_argument("Species cannot be empty");
     
    }
    // (This can only be applied as long as Pet doesn't have a pure virtual function or an abstract class)
    //std::string getOtherId(Pet other) 
   // {
   //     return other.id;
    //}

    std::string getId() {return id;}

    std::string getName() {return name;}

    std::string getSpecies() {return species;}

    virtual std::string speak() = 0;

    virtual std::string getBreed(){return " ";}

private:
    std::string id;
    std::string name;
    std::string species;
};

#endif