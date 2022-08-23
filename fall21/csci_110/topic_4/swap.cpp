//put template here

#include <iostream>

void swap(int&,int&);


int main()
{
    int x{20};
    int y{40};

    std::cout << "x = " << x << " y = " << y <<std::endl;

    swap (x, y);

    std::cout << "x = " << x << " y = " << y <<std::endl;



    return 0;
}


void swap(int& x,int& y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}