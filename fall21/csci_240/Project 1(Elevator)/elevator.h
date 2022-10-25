#include "array_bag.h"
#include "person.h"
#include "floors.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#define MAX_SIZE 6

class Elevator
{
public:
    Elevator()
    {
        this->up = true;
        this->currentSize = 0;
        this->coolDown = 0;
        this->currentFloor = 0;
    }

    bool goUp()
    {
        if (coolDown == 0)
        {
            ++currentFloor;
            return true;
        }
        if (coolDown == 0)
        {
            coolDown = 4;
        }
        return false;
    }

    bool goDown()
    {
        if (coolDown == 0)
        {
            --currentFloor;
            return true;
        }
        if (coolDown == 0)
        {
            coolDown = 4;
        }
        return false;
    }

    bool wait()
    {
        if (coolDown > 0)
        {
            --coolDown;
            return true;
        }
        return false;
    }

    void setWait() { coolDown += 10; }

    int getWait() { return coolDown; }

    int getCurrentFloor() { return currentFloor; }

    int getCurrentSize() { return currentSize; }

    bool up;

    void elevOnCall(int floor)
    {
        onCall[floor] = true;
    }

    void elevOffCall(int floor)
    {
        offCall[floor] = true;
    }

    void getOnElev(Person p)
    {
        ++currentSize;
        elevator.add(p);
    }

    Person getOffElev()
    {
        --currentSize;
        Person p = elevator.grab();
        return p;
    }

    bool onCall[50] = {false};
    bool offCall[50] = {false};

    
    ArrayBag<Person> elevator;

private:
    int currentFloor;
    int coolDown;
    static size_t currentSize;
};

size_t Elevator::currentSize = 0;

#endif