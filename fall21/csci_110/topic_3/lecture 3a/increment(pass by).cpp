// who: Edward Morcos emorcos
// what: 
// why: 
// when:

#include <iostream>
void increment(int&);
int preIncrement(int&);
//int postIncrement(const int&);
int postIncrement(int&);

int x;
const float PI {3.141};
int main ()
{
    // used to be int x {10}
     x = 10;
   //  int& y{x};
    std::cout << x << std::endl;
    // std::cout <<  << std::endl;

    std::cout << postIncrement(x) << std::endl; 
    //std::cout << postIncrement() << std::endl;

    std::cout << x << std::endl;
    //std::cout <<  << std::endl;

    std::cout << preIncrement(x) << std::endl;
   // std::cout << preIncrement() << std::endl;

    std::cout << x << std::endl;
   // std::cout <<  << std::endl;

    return 0;
}

void increment (int& v)
//void increment ()
{
    //v = v + 1;
    //v += 1;
    //v++;
    // v++ called a postincrement
    v = v++ ;
    // x = x++ ;
    // ++v called a preincrement

}

int preIncrement(int& value)
// int preIncrement()
{
    value = value + 1;
    return value;
    // x = x + 1;
     //return x;
}



//int postIncrement(int& value)
// int postIncrement()
int postIncrement(int& value)
{
    int temp {value};
    value = value + 1;
    return temp;
    // int temp {x}
    // x = x + 1
    // return x;
}