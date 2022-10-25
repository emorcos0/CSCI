
#ifndef PERSON_H
#define PERSON_H
#include "rand.cpp"
class Person
{
public:
    
    Person() { this->floor = randomRange(1,49); this->id = setCount();}

    int getId() {return id;}

    int getFloor() {return floor;}

    int setCount();

    bool operator==(const Person& other) const { return id == other.id;}
    

private:
    static int count;
    int id;
    int floor;
};

int Person::count = 0;
int Person::setCount() { ++count;}

#endif