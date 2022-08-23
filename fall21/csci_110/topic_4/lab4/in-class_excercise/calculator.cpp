// who: emorcos
// what: Implement a menu driven calculator
// why: Lecture 4 in-class exercise
// when: 2021-09-30

// includes go here
#include <iostream>
#include <cmath>
#include <cctype>

void displayGreeting();
void displayMenu();
char getMenuChoice();
bool isValid(char);
void executeOperation(char);
void add();
void sub();
void mult();
void div();
void mod();
void sqrt();
double getDouble(std::string);

int main(int argc, char const *argv[])
{
    char choice;
    displayGreeting();

    do
    {
        while(true)
        {
         displayMenu();
         choice = tolower(getMenuChoice());
         if(isValid(choice))
            break;
        
        }
         executeOperation(choice);
         std::cout << std::endl;
    } while (true);
    
    
    
	return 0;
}

void displayGreeting()
{
    system("cls");
    std::cout <<"Welcome to the commandline Calculator (CLC).\n\n";
}

void displayMenu()
{
   std::cout << "Main Menu\n"
             << "  (A)ddition\n"
             << "  (S)ubtraction\n"
             << "  (M)ultiplication\n"
             << "  (D)ivision\n"
             << "  M(o)dulo\n"
             << "  S(q)uare Root\n"
             << "  (E)xit\n\n";
}

bool isValid(char c)
{
    switch (c)
    {
    case 'a':
    case 's':
    case 'm':
    case 'd':
    case 'o':
    case 'q':
    case 'e':
       return true;
    
    }

    return false;
}

char getMenuChoice()
{
    char c;
    std::cout << "Enter choice: ";
    std:: cin >> c;
    return c;
}

void executeOperation(char c)
{
    switch (c)
    {
       case 'a':
            add();
            break;
       case 's':
            sub();
            break;
       case 'm':
            mult();
            break;
       case 'd':
            div();
            break;
       case 'o':
            mod();
            break;
       case 'q':
            sqrt();
            break;
       case 'e':
            exit(0);
    }
}

void add()
{
    double o1{getDouble("Enter the first addend: ")};
    double o2{getDouble("Enter the second addend: ")};
    std::cout << "The sum is: " << o1 + o2 << std::endl;

}

void sub()
{
    double o1{getDouble("Enter the minuend: ")};
    double o2{getDouble("Enter the subtrahend: ")};
    std::cout << "The difference is: " << o1 - o2 << std::endl;
}

void mult()
{
    double o1{getDouble("Enter the multiplier: ")};
    double o2{getDouble("Enter the multiplicand: ")};
    std::cout << "The product is: " << o1 * o2 << std::endl;
}

void div()
{
    double o1{getDouble("Enter the dividend: ")};
    double o2{getDouble("Enter the divisor: ")};
    std::cout << "The quotient is: " << o1 / o2 << std::endl;
}

void mod()
{
    double o1{getDouble("Enter the dividend: ")};
    double o2{getDouble("Enter the modulus: ")};
    std::cout << "The remainder is: " << fmod(o1, o2) << std::endl;
}

void sqrt()
{
    double o1;
    while(true)
    {
     o1 = getDouble("Enter the radicand: ");
    if(o1 >= 0)
        break;

    std::cout << "Invalid value!\nRadicand must be greater than or equal to zero.\n\n";
    }
    std::cout << "The square root is: " << sqrt(o1) << std::endl;
}

double getDouble(std::string prompt)
{
    double v;
    std::cout << prompt;
    std::cin >> v;
    return v;
}