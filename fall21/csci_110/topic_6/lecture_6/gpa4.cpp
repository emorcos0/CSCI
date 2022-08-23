// who: emorcos
// what: Collect student IDs and corresponding GPAs
// why: Lecture 6
// when: 2021-10-28

// includes go here
#include <iostream>
#include <fstream>
#include "utilities.h"

const size_t MAX_ENTRIES = 100;

const char IN = 0b00000;
const char OUT = 0b00001;
const char BINARY = 0b00010;
const char ATE = 0b00100;
const char APP = 0b01000;
const char TRUNC = 0b10000;

int main(int argc, char const *argv[])
{

	std::string id;
	float gpa;
	std::ofstream file;
	std::string filename;
	std::cout << "Enter data filename: ";
	std::cin >> filename;

	file.open(filename);

	std::cout << "Please enter up to 100 students\n";
	for (int counter = 0; counter < MAX_ENTRIES; ++counter)
	{
		std::cout << "Enter student ID or 'exit' to Exit: ";
		std:: cin >> id;

		id = toUpper(id);

		if (id == "EXIT")
			break;

		std::cout << "Enter GPA: ";
		std::cin >> gpa;

		file << id << ' ' << gpa << std::endl;
	}
	
	file.close();
	
	return 0;
}

