#include "array_bag.h"
#include "array_queue.h"
#include "person.h"


#ifndef FLOORS_H
#define FLOORS_H

class Floors
{
public:
    Floors() { }

    void getInLine(int floor,Person p) { queue[floor].enqueue(p);}
    Person getInElev(int floor) { queue[floor].dequeue(); return floors[floor].grab(); }

    void getOnFloor(int floor,Person p) { floors[floor].add(p); }
    
    ArrayBag<Person> floors[50];
    ArrayQueue<Person> queue[50];

    
    

};

#endif