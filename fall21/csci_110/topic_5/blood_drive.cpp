// who: emorcos
// what: Collect pints donated, find average, max, and min. 
// why: lab 5a
// when: 10/10/2021

// includes go here
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

//prototypes go here
const int SIZE = 7;
float getPints(float [], int SIZE);
float getTotal(const float [], int SIZE);
float getAverage(float, int SIZE);
float getHigh(const float pints[], int SIZE);
float getLow(const float pints[], int SIZE);
void displayInfo(float, float, float);


int main(int argc, char const *argv[])
{
	
    float pints[SIZE];
    float averagePints {0};
    float highPints{0};
    float lowPints{0};
    std::string again = "no";
    while (again == "no")
    {
      getPints(pints, SIZE);
      float totalPints{getTotal(pints, SIZE)};
      float averagePints{getAverage(totalPints, SIZE)};
      float highPints{getHigh(pints, SIZE)};
      float lowPints{getLow(pints, SIZE)};
        displayInfo(averagePints, highPints, lowPints);
        std::cout << "Do you want to end the program: yes or no ";
        std::cin >> again;
        
    }
    
	return 0;
}

float getPints(float pints[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Enter the pints collected: ";
        std::cin >> pints[i];
    }
    
}

float getTotal(const float pints[], int SIZE)
{
    float totalPints;
    for (int i = 0; i < SIZE; i++)
        totalPints += pints[i];

       
       return totalPints;
}

float getAverage(float totalPints, int SIZE)
{
    float averagePints{0};
    averagePints = totalPints / SIZE;
    return averagePints;
}

float getHigh(const float pints[], int SIZE)
{
    float highPints{pints[0]};
    for (int i = 1; i < SIZE; i++)
      {  if(pints[i] > highPints)
        highPints = pints[i];
      }
    return highPints;
}

float getLow(const float pints[], int SIZE)
{
    float lowPints{pints[0]};
    for (int i = 1; i < SIZE; i++)
      {  if(pints[i] < lowPints)
        lowPints = pints[i];
      }
    return lowPints;
}

void displayInfo(float averagePints, float highPints, float lowPints)
{
    std::cout << "The average number of pints donated is " << averagePints << std::endl;
    std::cout << "The highest pints donated is " << highPints << std::endl;
    std::cout << "The lowest pints donated is " << lowPints << std::endl;
}