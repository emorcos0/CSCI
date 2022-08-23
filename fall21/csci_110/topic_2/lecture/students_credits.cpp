

// who: Edward Morcos emorcos
// what: Calculate the amount of credits left to finish a degree
// why: Lab 2: Input <<  Processing <<  and Output
// when: 9/12/2021


#include <iostream>
#include <string>

int main()
{
	float creditsTaken;
	float creditsDegree;
	float creditsLeft;

	std::string studentName;
	std::string degreeName;

	std::cout << "Enter student's first name: ";
	std:: getline(std::cin, studentName);

	std::cout << "Enter the degree name: ";
	std:: getline(std::cin, degreeName);

	std::cout << "How many credits does this degree need? ";
	std::cin >> creditsDegree;

	std::cout << "How many credits has the student taken? ";
	std::cin >> creditsTaken;
	
	creditsLeft = creditsDegree - creditsTaken;
	std::cout << studentName << " is earning a " <<  creditsDegree << " degree and has " <<  creditsLeft <<  " credits left.\n"; 





	
	return 0;
}
