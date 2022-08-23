#include "widget.h"
#include <iostream>
#include "utilities.h"

int main(int argc, char const *argv[])
{
    Widget widgets1[]{
        {3, "B"},
        {1, "A"},
        {2, "A"},
        {4, "C"}};

    //Widget widgets2[4];

    // swap<Widget>(w1, w2);
    //arrayReverse<Widget>(widgets, 0, 3);
    
    insertionSort<Widget, 4>(widgets1);

    //arrayCopy<Widget>(widgets1, 4, widgets2, 4);
    
    printArray<Widget, 4>(widgets1, std::cout);
    std::cout << std::endl;
    if(binarySearch<Widget>(widgets1, 0, 4, {1, "B"}) != -1)
        std::cout << "Widget ser# 1 exists\n";
    else
        std::cout << "Widget ser#1 does not exist\n";
    

    return 0;
}
