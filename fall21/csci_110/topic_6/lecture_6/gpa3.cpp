// who: emorcos
// what: Collect student IDs and corresponding GPAs
// why: Lecture 6
// when: 2021-10-28

// includes go here
#include <iostream>
#include <fstream>
#include <iomanip>
#include "utilities.h"

const size_t MAX_ENTRIES = 100;
const std::string FILENAME = "gpa.dat";



int main(int argc, char const *argv[])
{

	std::string record;
	std::ifstream file;

	file.open(FILENAME);

	

	while(std::getline(file, record))
		std::cout << record << '\n';

	
	file.close();
	
	return 0;
}
