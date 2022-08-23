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

	std::string id;
	float gpa;
	std::ifstream file;

	file.open(FILENAME);

	std::cout << std::setprecision(2) << std::fixed;

	while(file >> id >> gpa)
	{
		std::cout << "ID: " << std::left << std::setw(9) << id << "  GPA: " << gpa << '\n';
	}
	
	
	file.close();
	
	return 0;
}
