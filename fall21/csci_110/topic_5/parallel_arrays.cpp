// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>

//prototypes go here
bool isLeapYear(int);

const std::string MONTH_NAMES[]{"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const int MONTH_DAYQTY[]{0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(int argc, char const *argv[])
{
	int year;
    std::cout << "Enter the Year: ";
    std::cin >> year;
	
    std::cout << "For year " << year << std::endl;
    for (int i = 0; i < 13; i++)
    {
        std::cout << MONTH_NAMES[i] << " has "
            << ((i == 2 && isLeapYear(year)) ? MONTH_DAYQTY[i] + 1 : MONTH_DAYQTY[i]) << " days\n";
    }
    
	return 0;
}

bool isLeapYear(int year)
{
    return(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0 ));
}