#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    float hitQty;
    float timesAtBat;
    float battingAverage;


    int integer1;
    int integer2;
    int integer3;

    std::string name;

    std::cout << "enter three ints: ";
    std::cin >> integer1 >> integer2 >> integer3;

    std::cout << "Enter the name: ";
    std:: getline(std::cin, name);

    std::cout << "Enter the number of hits: ";
    std:: cin >> hitQty;

    std::cout << "Enter number of times at bat: ";
    std::cin >> timesAtBat;

    battingAverage = hitQty / timesAtBat;
    std::cout << name << "Your batting average is: " << battingAverage * 100 << "%!\n";

    return 0;
}


// Declare Real hitQty
// Declare Real timesAtBat
// Declare Real battingAverage

// Display "Enter the number of hits: "
// Input hitQty

// Display "Enter number of times at bat: "
// Input timesAtBat

// Set battingAverage = hitQty / timesAtBat
// Display "Your batting average is: ", battingAverage