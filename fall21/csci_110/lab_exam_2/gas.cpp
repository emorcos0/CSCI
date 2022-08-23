#include <iostream>
#include <string>
#include <cstdlib>
#include "bucket.h"

void toLower(char &c);
std::string getCourse();

int main(int argc, char const *argv[])
{

    std::cout << "Welcome to the Grade Analysis System (GAS)\n\n";
    char again{'y'};
    double gradeInput;

    while (again == 'y')
    {
        std::string course{getCourse()};

        while (!(isFull()))
        {
            std::cout << "   Enter  grade: ";
            std::cin >> gradeInput;
            if (gradeInput >= 0)
                add(gradeInput);

            if (gradeInput == -1)
            {
                std::cout << "Enter the grade to remove: ";
                std::cin >> gradeInput;
                if (remove(gradeInput))
                    std::cout << "--- " << gradeInput << " removed"
                              << " ---\n";
                else
                    std::cout << "--- grade not found ---\n";
            }

            if (gradeInput == -2)
                break;
        }

        std::cout << "\nAnalysis for " << course << std::endl;
        std::cout << "  Grades entered: " << count() << std::endl;
        std::cout << "  Median grade: " << median() << std::endl;
        std::cout << "  Minimum grade: " << min() << std::endl;
        std::cout << "  Maximum grade: " << max() << std::endl;

        std::cout << "  \nThe letter grade distribution is as follows: \n";
        std::cout << "  A - " << qtyLetterGrade(90.0, 100000) << std::endl;
        std::cout << "  B - " << qtyLetterGrade(80.0, 90) << std::endl;
        std::cout << "  C - " << qtyLetterGrade(70.0, 80) << std::endl;
        std::cout << "  D - " << qtyLetterGrade(60.0, 70) << std::endl;
        std::cout << "  F - " << qtyLetterGrade(0.0, 60) << std::endl;

        std::cout << "Would you like to enter the grades for another class? (y/n) : ";
        std::cin >> again;
        toLower(again);
        clear();
    }
    return 0;
}

std::string getCourse()
{
    std::string course;
    std::cout << "Enter the course name: ";
    std::getline(std::cin, course);
    if (course == "")
        std::getline(std::cin, course);

    std::cout << "Enter the grades for this course.\n";
    std::cout << "(Enter -1 to remove a grade previously enetered or -2 when finished.) \n";
    return course;
}

void toLower(char &c)
{
    if (c == 'Y')
        c = 'y';
}


