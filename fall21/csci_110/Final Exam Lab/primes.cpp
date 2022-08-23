// Edward Morcos
#include <fstream>
#include <iostream>
#include <string>


const int SIZE{1000000};

void init(bool[], const int);
void calcPrimes(bool[], int);
void markNonPrimes(bool[], int, int);

void storePrimes(bool[], int, std::string);

int main(int argc, char const *argv[])
{
    bool nums[SIZE];
    init(nums, SIZE);
    calcPrimes(nums, SIZE);
    std::cout << "Enter the file name for where you want to save the primes: " << std::endl;
    std::string fileName;
    std::cin >> fileName;
    storePrimes(nums, SIZE, fileName);

    return 0;
}

void init(bool nums[], int size)
{
    nums[0] = false;
    nums[1] = false;
    nums[2] = true;
    for (int i = 3; i < size; i = i + 2)
    {
        nums[i] = true;
    }
    for (int i = 4; i < size; i = i + 2)
    {
        nums[i] = false;
    }
}

void calcPrimes(bool nums[], int size)
{
    for (int p = 3; p < size; p = p + 2)
    {
        markNonPrimes(nums, size, p);
    }
}

void markNonPrimes(bool nums[], int size, int p)
{
    
    for (int k = 2; k*p <= size; k++)
    {
        nums[k*p] = false;
    }
}

void storePrimes(bool nums[], int size, std::string fileName)
{
    std::ofstream file;

    file.open(fileName);
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == true)
            file << i << '\n';
    }
    file.close();
}