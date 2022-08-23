// who: emorcos
// what: different sorting programs
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "utils.h"

#define RANDOMIZE_COUNT 600000

//prototypes go here

void printArray(int[], int);

//definitions go here

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    std::string userInput;

    std::cout << "Enter a sentence: ";
    getline(std::cin, userInput);

    std::cout << "This is what you've enetered: " << userInput << std::endl;

    std::string alpha{randomizeString(userInput)};

    std::cout << "The middle character in the alphabetically sorted string is " << medianString(alpha) << std::endl;

    std::cout << userInput << std::endl;

    std::cout << alpha << std::endl;

    insertionSort(alpha);

    std::cout << alpha << std::endl;

    
    return 0;
}

void printArray(int array[], int size)
{
    std::cout << "[ ";
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << ' ';

    std::cout << "]\n";
}

