// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include <ctime>
#include <cstdlib>

int random(int start, int end);
int spin();
void printGreeting();
float getValidDeposit();
float getValidBet(float);
void printPayout(float);
void printGoodbye();
float getWinningsFactor(int, int, int, int);
void printCredit(float);
float getFloat(std::string);
void printWheels(int, int, int, int);
std::string wheelToCar(int );

int main(int argc, char const *argv[])
{
    float credit;
    float bet;
    float winnings;
    int wheel1,
        wheel2, 
        wheel3, 
        wheel4;

    srand(time(NULL));

    printGreeting();
    credit = getValidDeposit();
    printCredit(credit);

   
	do
    {
        bet = getValidBet(credit);
        if(bet <= 0)
            break;
        credit = credit - bet;
        printCredit(credit);
       
        wheel1 = spin();
        wheel2 = spin();
        wheel3 = spin();
        wheel4 = spin();

        printWheels(wheel1, wheel2, wheel3, wheel4);
    
        winnings = bet * getWinningsFactor(wheel1, wheel2, wheel3, wheel4);
        std::cout << "You won $" << winnings << std::endl;
        credit = credit + winnings;
        printCredit(credit);
    } while (true);
    
	printPayout(credit);
    printGoodbye();

	return 0;
}

int random(int start, int end)
{
   return rand() % (end - start) + start;
}

int spin ()
{
    int qtySpin = random(1, 1001);
    int spinValue;
    for (int i = 0; i < qtySpin; i++)
    {
        spinValue = random(1, 7);
        return spinValue;
    }
    
}

void printGreeting()
{
    std::cout << "Welcome to Supercar Slots\n\n";
}

float getValidDeposit()
{
    float deposit;
    do
    {
        deposit = getFloat("Enter your depost: $");
        if (deposit > 0)
            return deposit;

        std::cout << "Invalid value!\nPlease try again\n\n";
    } while (true);
    
}

float getValidBet(float credit)
{
    float bet;
    do
    {
        bet = getFloat("Place you bet: $");
        if (bet <= credit)
            return bet;

        std::cout << "Invalid value!\nPlease try again\n\n";
    } while (true);
    
}

void printPayout(float credit)
{
    std::cout << "Returning $" << credit << std::endl;
}

void printGoodbye()
{
    std::cout << "Thanks for playing Supercar Slots. \n\n";
}

float getWinningsFactor(int w1, int w2, int w3, int w4)
{
    if(w1 == w2 && w1 == w3 && w1 == w4)
        return 10.0;

    if(
        (w1 == w2 && w1 == w3)
        || (w1 == w2 && w1 == w4)
        || (w1 == w3 && w1 == w4)
        || (w2 == w3 && w2 == w4))
        return 1.5;

    if (w1 == w2 || w1 == w3 || w1 == w4 || w2 == w3 || w2 == w4 || w3 == w4)
    return 1.0;
    
    return 0;
}

void printCredit(float credit)
{
    std::cout << "Your credit is $" << credit << std::endl;
}

float getFloat(std::string prompt)
{
    float value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}

std::string wheelToCar(int w)
{
    switch (w)
    {
    case 1: return "Ferrari";
    case 2: return "Lamborghini";
    case 3: return "Bugatti";
    case 4: return "McLaren";
    case 5: return "Koenigsegg";
    default: return "Maserati";
    }
}

void printWheels(int w1, int w2, int w3, int w4)
{
    std::cout << wheelToCar(w1) << " - " << wheelToCar(w2) << " - " << wheelToCar(w3) << " - " << wheelToCar(w4) << std::endl; 
}