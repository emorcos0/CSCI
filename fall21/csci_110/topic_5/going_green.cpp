// who: emorcos
// what: Find how much money is saved going green 
// why: lab 5a
// when: 10/10/2021

// includes go here
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

const int SIZE = 12;
void greeting();
float getYear(std::string);
float getSpendings(float [], const std::string[], int SIZE);
float calcSavings(float [], float [], float [], int SIZE);
void displayInfo(float [], float [], const std::string[], float [], int SIZE, float, float);



int main(int argc, char const *argv[])
{
    float beforeGreen[SIZE];
    float afterGreen[SIZE];
    float savings[SIZE];
    const std::string months[]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    greeting();

    std::string response = "n";
    while (response == "n")
    {
        float firstYear{getYear("Enter year before going green (yyyy) : ")};
        getSpendings(beforeGreen, months, SIZE);
        float secondYear{getYear("Enter year after going green (yyyy) : ")};
        getSpendings(afterGreen, months, SIZE);
        calcSavings(beforeGreen, afterGreen, savings, SIZE);
        displayInfo(beforeGreen, afterGreen, months, savings, SIZE, firstYear, secondYear);
        std::cout << "Do you want to end the program? (y/n) : ";
        std::cin >> response;
        
    }
    
    return 0;
}


void greeting()
{
    std::cout << "Welcome to the GREEN Saving Calculator\n";
}

float getYear(std::string prompt)
{
    float year;
    std::cout << prompt;
    std::cin >> year;
    return year;
}

float getSpendings(float spendings[], const std::string months[], int SIZE)
{
    std::cout << "Enter the energy costs for... \n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << months[i] << " $: ";
        std::cin >> spendings[i];
    }
    std::cout << "--------------------------------\n";
}

float calcSavings(float beforeGreen[], float afterGreen[], float savings[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        savings[i] = beforeGreen[i] - afterGreen[i];
    }
    
}

void displayInfo(float beforeGreen[], float afterGreen[], const std::string months[], float savings[], int SIZE, float firstYear, float secondYear)
{
    std::cout << "                              SAVINGS                             \n";
    std::cout << "____________________________________________________________\n";
    std::cout << "SAVINGS              " << firstYear << "            " << secondYear << "              MONTH\n" << std::endl;
    std::cout << "____________________________________________________________\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "$" << savings[i] << "              $" << beforeGreen[i] << "             $" << afterGreen[i] <<  "          "  << months[i] << std::endl;
    }
    
}
