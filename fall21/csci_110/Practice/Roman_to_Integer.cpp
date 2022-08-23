using namespace std;
#include <string>
#include <iostream>

int romanToInt(string);

int main(int argc, char const *argv[])
{
    
    int Test = romanToInt("XIV");
    
    cout << Test;
    return 0;
}

int romanToInt(string s)
{
    int tot{0};
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == 'I')
        {

            if (s[i + 1] == 'X')
            {
                tot += 9;
                i += 1;
                continue;
            }

            if (s[i + 1] == 'V')
            {
                tot += 4;
                i += 1;
                continue;
            }

            if (s[i + 1] != 'V' && s[i + 1] != 'X')
            {
                tot += 1;
                continue;
            }
        }

        if (s[i] == 'X')
        {

            if (s[i + 1] == 'L')
            {
                tot += 40;
                i += 1;
                continue;
            }

            if (s[i + 1] == 'C')
            {
                tot += 90;
                i += 1;
                continue;
            }

            if (s[i + 1] != 'L' && s[i + 1] != 'C')
            {
                tot += 10;
                continue;
            }
        }

        if (s[i] == 'C')
        {

            if (s[i + 1] == 'D')
            {
                tot += 400;
                i += 1;
                continue;
            }

            if (s[i + 1] == 'M')
            {
                tot += 900;
                i += 1;
                continue;
            }

            if (s[i + 1] != 'D' && s[i + 1] != 'M')
            {
                tot += 100;
                continue;
            }
        }

        if (s[i] == 'V')
            tot += 5;
        if (s[i] == 'L')
            tot += 50;
        if (s[i] == 'D')
            tot += 500;
        if (s[i] == 'M')
            tot += 1000;
    }
    return tot;
}