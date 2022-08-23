// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
// Can include 8 into [] to initialize size
const std::string DAY_NAMES[]{"","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main(int argc, char const *argv[])
{
	for (size_t i = 1; i < 8; i++)
    {
        std::cout << DAY_NAMES[i] << std::endl;
    }
    
	return 0;
}

