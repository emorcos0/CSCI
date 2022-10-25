
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "person.h"
#include "floors.h"
#include "elevator.h"
#include "building.h"

bool createPerson()
{
    if (randomRange(1, 1000) <= 35)
    {
        return true;
    }

    return false;
}

bool personLeave()
{

    if (randomRange(1, 1000) <= 15)
    {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[]) //sometimes works, other times elevator goes to highest floor and exits.
{
    srand(time(NULL));

    Building theMedford;
    for (size_t i{0}; i < 1000000; ++i)
    {
        if (createPerson())
        {
            std::cout << "A person has entered the building.\n";
            Person p;
            theMedford.floors.getInLine(0, p);
            theMedford.elevator.elevOnCall(0);             // wants to get on elevator at lobby
                                                          // wants to get off elevator at determined floor
            if (theMedford.elevator.getCurrentFloor() == 0 && theMedford.elevator.getCurrentSize() <= MAX_SIZE && !theMedford.floors.queue[0].empty())
            {
                theMedford.elevator.getOnElev(p);
                theMedford.floors.getInElev(0);
                std::cout << "Someone on floor " << theMedford.elevator.getCurrentFloor() << " entered the elevator\n";
                theMedford.elevator.elevOffCall(p.getFloor());
            }
        }

        if (personLeave())
        {
            for (size_t z = 1; z < 50; z++)
            {
                if (theMedford.floors.floors[z].size() > 0)
                {
                    theMedford.floors.getInLine(z, theMedford.floors.floors[z].grab()); // enters queue to leave floor
                    theMedford.elevator.elevOnCall(z);                                  // get on elevator at i floor
                    theMedford.elevator.elevOffCall(0);                                 // get off call to lobby made when person enters elevator
                }
            }
        }
        if (!theMedford.elevator.wait())
        {

            if (theMedford.elevator.getCurrentFloor() == 0) // go up if at base
                theMedford.elevator.up = true;

            if (theMedford.elevator.offCall[theMedford.elevator.getCurrentFloor()]) // getting off elevator and picking up anyone in potential queue
            {
                if (theMedford.elevator.getWait() == 0)
                    theMedford.elevator.setWait();

                if (theMedford.elevator.getCurrentSize() > 0)
                {
                    theMedford.floors.getOnFloor(theMedford.elevator.getCurrentFloor(), theMedford.elevator.getOffElev()); // person leaves elevator
                    std::cout << "Someone has got off the elevator on floor " << theMedford.elevator.getCurrentFloor() << std::endl;
                    theMedford.elevator.offCall[theMedford.elevator.getCurrentFloor()] = 0;
                }
                while (theMedford.elevator.getCurrentSize() <= MAX_SIZE && theMedford.elevator.onCall[theMedford.elevator.getCurrentFloor()]) // if free space, floor queue enters elevtor
                {
                    theMedford.elevator.getOnElev(theMedford.floors.getInElev(theMedford.elevator.getCurrentFloor()));
                }
                if (theMedford.floors.queue[theMedford.elevator.getCurrentFloor()].empty()) // if elevator picks up whole queue, turn off on call
                {
                    theMedford.elevator.onCall[theMedford.elevator.getCurrentFloor()] = 0;
                }
                theMedford.elevator.offCall[theMedford.elevator.getCurrentFloor()] = 0; // turn off "off" call
                //break;
            }

            while (theMedford.elevator.onCall[theMedford.elevator.getCurrentFloor()] && theMedford.elevator.getCurrentSize() <= MAX_SIZE && !theMedford.floors.queue[theMedford.elevator.getCurrentFloor()].empty())
            {
                if (theMedford.elevator.getWait() == 0)
                    theMedford.elevator.setWait();
                theMedford.elevator.getOnElev(theMedford.floors.getInElev(theMedford.elevator.getCurrentFloor()));
                std::cout << "Someone on floor " << theMedford.elevator.getCurrentFloor() << " entered the elevator\n"; //when someone enters a floor, simulation ends for some reason
                if(theMedford.floors.queue[theMedford.elevator.getCurrentFloor()].empty()) theMedford.elevator.onCall[theMedford.elevator.getCurrentFloor()] = false;
            }

            for (size_t k = theMedford.elevator.getCurrentFloor() + 1; k <= 49; k++) // direction change
            {
                if (theMedford.floors.queue[k].empty() && !theMedford.elevator.offCall[k])  //if all floors above the elevator have no one in queue
                {                                                                          // and no one wants to get off on a higher floor then change direction
                    theMedford.elevator.up = false;
                }
                else
                {
                    theMedford.elevator.up = true;
                    break; 
                    //when this break is commented out the elevator will be stuck returning to lobby whenever a new person enterrs, regardless of direction
                    //when not commented out the elevator is stuck going up, till floor 50
                }
            }
            
            if (theMedford.floors.queue[0].empty())
                theMedford.elevator.onCall[0] = false;

            for (size_t j = 0; j <= 49; j++) // moving up and down
            {
                if (theMedford.elevator.offCall[j] || theMedford.elevator.onCall[j] && j > theMedford.elevator.getCurrentFloor() && theMedford.elevator.up && theMedford.elevator.getWait() == 0)
                {
                    if (theMedford.elevator.goUp())
                        std::cout << "The elevator has gone up one floor\n";
                    std::cout << "The elevator is now at floor " << theMedford.elevator.getCurrentFloor() << std::endl;
                    break;
                }
                if (theMedford.elevator.offCall[j] || theMedford.elevator.onCall[j] && j < theMedford.elevator.getCurrentFloor() && !theMedford.elevator.up && theMedford.elevator.getWait() == 0)
                {
                    if (theMedford.elevator.goDown())
                        std::cout << "The elevator has gone down one floor\n";
                    std::cout << "The elevator is now at floor " << theMedford.elevator.getCurrentFloor() << std::endl;
                    break;
                }
            }

            // when the bottom code is uncommented out, the elevator will continually dump everyone that enters the elevator as they
            // while (theMedford.elevator.getCurrentFloor() == 0 && theMedford.elevator.getCurrentSize() > 0) // drops off all passengers when returned to lobby
            // {
            //     theMedford.elevator.getOffElev();
            //     if (theMedford.elevator.getWait() == 0)
            //         theMedford.elevator.setWait();
            // }

            if(!theMedford.floors.queue[0].empty()) theMedford.elevator.elevOnCall(0); //call elevator to lobby if it has a queue

            
        }
    }


    return 0;
}
