// who: emorcos
// what: Turn bucket header into a class
// why: Object-oriented Design
// when: 11/21/2021

#include "bucket.h"
#include <iostream>



int main(int argc, char const *argv[])
{
	Bucket test;
    
    std::cout << "Now testing isEmpty: " << "The bucket is initially " << (test.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "Now testing to see if it is not empty and add function. \n";
    std::cout << "We are now adding the value 11.5 to the bucket: " << (test.add(11.5) ? "Added double, " : "Didn't add double, ") 
              << "The bucket is now " << (test.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "Now adding the values 12.5, 11.5, 11.5, 4.0, and 27.8 to test other functions. " << std::endl; 
    test.add(12.5);
    test.add(11.5);
    test.add(11.5);
    test.add(4.0);
    test.add(27.8);
    std::cout << "Now testing the contains function: " << (test.contains(27.8) ? "Contains 27.8" : "Doesn't contain 27.8") << std::endl; 
    std::cout << "Now testing the contains function: " << (test.contains(25.8) ? "Contains 25.8" : "Doesn't contain 25.8") << std::endl;
    std::cout << "Now testing the frequency function on 11.5: There are " << test.getFreq(11.5) << " entries equal to 11.5" << std::endl;
	std::cout << "Now testing the frequency function on 4.0 : There are " << test.getFreq(4.0) << " entries equal to 4.0" << std::endl;
    std::cout << "Now testing the frequency function on 0.0 : There are " << test.getFreq(0.0) << " entries equal to 0.0" << std::endl;
    std::cout << "Now testing the count function: There are " << test.count() << " entries" << std::endl;
    std::cout << "Now testing the remove function : Removing " << test.remove(27.8) << std::endl;
    std::cout << "The bucket now: " << (test.contains(27.8) ? "Contains 27.8" : "Doesn't contain 27.8") << std::endl;
    std::cout << "Now testing the remove function : Removing " << test.remove(11.5) << std::endl;
    std::cout << "The frequecy of the value 11.5 : There are " << test.getFreq(11.5) << " entries equal to 11.5" << std::endl;
    std::cout << "Now testing the clear function \n" ;
    test.clear();
    std::cout << "Now seeing if empty: " << "The bucket is now " << (test.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "Now seeing the count: There are " << test.count() << " entries" << std::endl;


	return 0;
}
