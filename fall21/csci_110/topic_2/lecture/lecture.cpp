#include <iostream>

int main(int argc, char const *argv[])
{
    int integer1;
    int integer2;
    int integer3;
    int coefficient;
    int result;

    std::cout << "Enter the first integer: ";
    std::cin >> integer1;

    std::cout << "Enter the second integer: ";
    std::cin >> integer2;

    std::cout << "Enter the third integer: ";
    std::cin >> integer3;

    std::cout << "Enter the coefficient: ";
    std::cin >> coefficient;

    result = (integer1 + integer2 + integer3) * coefficient;
    std::cout << "The sum of the integers multiplied by the coefficient is " << result << std::endl;

    result = (integer1 + integer2 + integer3) / coefficient;
    std::cout << "The sum of the integers divided by the coefficient is " << result << std::endl;

    return 0;
}


// // declarations
// Declare Integer integer1
// Declare Integer integer2
// Declare Integer integer3
// Declare Integer coefficient
// Declare Integer result

// // input
// Display "Enter the first integer: "
// Input integer1

// Display "Enter the second integer: "
// Input integer2

// Display "Enter the third integer: "
// Input integer3

// Display "Enter a coefficient: "
// Input coefficient

// // processing and output
// Set result = (integer1 + integer2 + integer3) * coefficient
// Display "The sum of the integers multiplied by the coefficient is ", result

// Set result = (integer1 + integer2 + integer3) / coefficient
// Display "The sum of the integers divided by the coefficient is ", result
