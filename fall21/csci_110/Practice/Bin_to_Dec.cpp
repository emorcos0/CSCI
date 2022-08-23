#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter a binary value: ";
    string bin;
    cin >> bin;

    vector<int> binary;
    for (int i = 0; i < bin.length(); i++)
    {
        binary.push_back(bin[i] - '0');
    }

    reverse(binary.begin(), binary.end());
    int dec{0};
    int count{0};
    for (int i : binary)
    {
        if (i == 0)
        {
            count++;
            continue;
        }
        if (i == 1)
        {
            dec += pow(2, count);
            count++;
        }
    }
cout << dec << endl;
cout <<"hi" << endl;

    return 0;
}
