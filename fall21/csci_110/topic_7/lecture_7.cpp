// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>

void countDown(int);
void triangle(int);
unsigned long long factorial(unsigned long long n);
void arrayReverse(int[], int, int);
void printArray(int[], int, int);
unsigned long long fibonacci(unsigned int);
int arraySum(int [], int);
bool runAgain();
void clearScreen();

int main(int argc, char const *argv[])
{
    int n{50};
    //std::cout << "The " << n << "th fib value is " << fibonacci(n) << std::endl;

    //int array[] {1,2,3,4,5,6,7,8,9};
    //printArray(array, 0, 10);
    //arrayReverse(array, 0, 9);
    //printArray(array, 0, 10);
    //countDown(10);
    triangle(10);
    //std::cout << n << "! = " << factorial(n) << std::endl;

    //std::cout << "The sum of the array values is: " << arraySum(array, 9) << std::endl;

    if(runAgain())
        std::cout << "Wants to run again\n";
    else   
        std::cout << "Doesn't want to run again\n";

    return 0;
}

void countDown(int t)
{
    std::cout << t << std::endl;

    if (t > 0)
    {
        countDown(t - 1);
        std::cout << t << std::endl;
    }
}

void triangle(int n)
{
    if (n <= 1)
        std::cout << "*" << std::endl;
    else
    {
        for (int i = 0; i < n; i++)
            std::cout << "*";

        std::cout << std::endl;
        triangle(n - 2);
    }
    
}

unsigned long long factorial(unsigned long long n)
{
    if(n == 0 || n == 1) return 1;

    return n * factorial(n - 1);
}

void swap(int& left, int& right)
{
    int temp = left;
    left = right;
    right = temp;
}

void arrayReverse(int array[], int start, int end)
{
    if(end <= start) return;

    swap(array[start], array[end]);
    arrayReverse(array, start +1, end -1);
}

void printArray(int array[], int index, int size)
{
    if(index == size) 
    {
        std::cout << std::endl;
    return;
    }
     std::cout << array[index] << ' ';
     printArray(array, index + 1, size);
}

unsigned long long fibonacci(unsigned int n)
{
    if(n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int arraySum(int array[], int size)
{
    if (size == 0) return 0;

    return array[size - 1] + arraySum(array, size -1);
}

bool runAgain()
{
    char choice;
    std::cout << "Do you want to run again (y/n):  ";
    std::cin >> choice;
    choice = tolower(choice);

    if(choice == 'y' || choice == 'n')
        return choice == 'y';

    clearScreen();
    std::cout << "Invalid choice!!\n";
    return runAgain();
    
}

void clearScreen()
{
    system("cls"); 
}