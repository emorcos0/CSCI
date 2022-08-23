#include <iostream>

using namespace std;

bool isPrime(int i)
{
    if (i == 2)
        return true;
    if (i == 0 || i == 1 || i % 2 == 0)
        return false;
    for (int j = 3; j <= i/2; j+=2)
        if (i % j == 0)
            return false;
}

int main(int argc, char const *argv[])
{
    int input;
    bool prime;
    


    for (int i = 0; i < 1'000'000; i++)
    {
        if (isPrime(i))
            cout << i << "\n";
    }


    // while (true)
    // {
    //     cout << "Enter the digit" << endl;
    //     cin >> input;
    //     prime = isPrime(input);
    //     cout << "The digit is " << (prime ? "prime." : "composite.") << endl;
    // }

    return 0;
}
