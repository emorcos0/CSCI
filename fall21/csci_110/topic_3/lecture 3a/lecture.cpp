#include <iostream>
#include <string>


int getInteger(std::string);
int calcSum(int,int,int);
int getMin(int,int,int);
int getMax(int,int,int);
void printInteger(std::string, int);

int main(int argc, char const *argv[])
{
    
    int num1{getInteger("Enter first integer ")};
    int num2{getInteger("Enter second integer ")};
    int num3{getInteger("Enter third integer ")};
    int coefficient{getInteger("Enter coefficient ")};
   

    
    int sum{calcSum(num1, num2, num3)};

    
    int min{getMin(num1, num2, num3)};
    int max{getMax(num1, num2, num3)};


    printInteger("The sum is ", sum);
    printInteger("The min value is ", min);
    printInteger("The max value is ", max);


    return 0;
}




int getInteger(std::string prompt)
{
    int value;

    std::cout << prompt;
    std::cin >> value;
    return value;
}


int calcSum( int a, int b, int c)
{
    return a + b + c;
}

int getMin(int a,int b,int c)
{
    int min{a};
    if(b < min) min = b;
    if(c < min) min = c;

    return min;
}

int getMax(int a,int b,int c)
{
    int max{a};
    if(b > max) max = b;
    if(c > max) max = c;

    return max;
}

void printInteger(std::string msg, int value)
{
    std::cout << msg << value << std::endl;
}
