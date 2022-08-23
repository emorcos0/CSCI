// who: emorcos
// what: Fantastic Five lottery program
// why: Lab 3b: Modules and Functions 
// when:  9/26


#include <iostream>
#include <cstdlib>

int inputMax(std::string);



int main()
{
	
	int max{inputMax("Enter the maximum allowed lottery number: ")};
	
	std::cout << "Your numbers are: ";

	for (size_t i = 0; i < 5; i++)

	std::cout << rand() % max << std::endl;


}

int inputMax(std::string msg)
{
	int max;
	std::cout << msg;
    std::cin >> max;
    return max;
}