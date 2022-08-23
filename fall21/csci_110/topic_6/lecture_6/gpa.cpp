// who: emorcos
// what: Collect student IDs and corresponding GPAs
// why: Lecture 6
// when: 2021-10-28

// includes go here
#include <iostream>
#include <fstream>
#include "utilities.h"
#include <cmath>
#include <sstream>
#include <string>

const size_t MAX_ENTRIES = 100;
const std::string FILENAME = "gpa.dat";



int main(int argc, char const *argv[])
{
	std::stringstream ss;
	std::string id;
	float gpa;

	std::string students[MAX_ENTRIES];
	size_t count{0};

	//std::ofstream file;

	//file.open(FILENAME);

	std::cout << "Please enter up to 100 students\n";
	for (int counter = 0; counter < MAX_ENTRIES; ++counter)
	{
		ss.clear();
		std::cout << "Enter student ID or 'exit' to Exit: ";
		std:: cin >> id;

		id = toUpper(id);

		if (id == "EXIT")
			break;
		
		std::cout << "Enter GPA: ";
		std::cin >> gpa;

		ss << id << ' ' << gpa;
		students[count] = ss.str();


		++count;


		//file << id << ' ' << gpa << std::endl;
	}
	
	store(students, count, FILENAME, '#');
	
	return 0;
}
