// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.


#include <iostream>
#include "bucket.h"



int main(int argc, char const *argv[])
{
    Bucket b;

    for (int i = 0; i < 10; i++)
        b.add(i);
    b.add(9);

    std::cout << " The value 9 appears " << b.getFreq(9) << " time(s)\n";
    
    b.remove(9);

    while(!b.isEmpty())
        std::cout << b.remove() << std::endl;
    
	
	
	return 0;
}
