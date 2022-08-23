// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>

#include "double_bucket.h"



int main(int argc, char const *argv[])
{
	std::cout << "The bucket is " << (isEmpty() ? "" : "not ") << "empty\n";
    std::cout << "Adding the value 20\n";
    add(20);
	std::cout << "The bucket is " << (isEmpty() ? "" : "not ") << "empty\n";

    std::cout << "There are " << count() << " entries in the bucket\n";

    std::cout << "The bucket " << (contains(20) ? "" : "does not ") << "contains 20\n";

    std::cout << "Removing the value 20\n";
    remove(20);

    std::cout << "The bucket is " << (isEmpty() ? "" : "not ") << "empty\n";

    std::cout << "There are " << count() << " entries in the bucket\n";

    std::cout << "The bucket " << (contains(20) ? "" : "does not ") << "contains 20\n";

    std::cout << "Adding values 0 - 9\n";
    for (int i = 0; i < 10; i++)
        add(i);
    
    std::cout << "There are " << count() << " entries in the bucket\n";
    while (!isEmpty())
        std::cout << remove() << std::endl;
    
    std::cout << "There are " << count() << " entries in the bucket\n";

    std::cout << "Adding values [0 - 9], 9\n";
    for (int i = 0; i < 10; i++)
        add(i);

    add(9);

    std::cout << "Removing the value 9\n";
    remove(9);

    while (!isEmpty())
        std::cout << remove() << std::endl;
    
	return 0;
}
