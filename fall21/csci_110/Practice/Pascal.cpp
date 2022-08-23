
#include <iostream>
using namespace std;

void Pascal(int rows);
int main(int argc, char const *argv[])
{
    int rows;
    cout << "Enter the number of rows you want in Pascal's triangle: " << endl;
    cin >> rows;
    Pascal(rows);

    return 0;
}

void Pascal(int rows)
{

    int pascal[rows][rows];

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c <= r; c++)
        {
            if (c == 0 || r == c)
                pascal[r][c] = 1;
            else
                pascal[r][c] = pascal[r - 1][c] + pascal[r - 1][c - 1];
        }
    }

    for (int r = 0; r < rows; r++)
    {
        cout.width(rows * 2 - r );
        for (int c = 0; c <= r; c++)
        {
            cout << pascal[r][c] << " ";
        }
        cout << endl;
    }
}