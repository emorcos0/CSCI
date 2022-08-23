// who: emorcos
// what: Supercar Slot Machine
// why: Project 1
// when: 10/04/2021

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>

void displayGreeting(std:: string);
float inputBet(float);
void inputCredit( float&);
void newCredit( float&, float);
int wheelSpin();
int random(int, int);
int spinWheel (int);
std::string numberToCar(int);
void displayCars(std::string, std::string, std::string, std::string);
bool determineWin1(std::string, std::string, std::string, std::string, float);
bool determineWin2(std::string, std::string, std::string, std::string, float);
bool determineWin3(std::string, std::string, std::string, std::string, float);
void winThree(float&, float);
void winTwo(float&, float);
void winOne(float&, float);
void displayCredit(float);


int main(int argc, char const *argv[])
{

    float credit;
    displayGreeting("Welcome to Supercar Slots\n\n");
  inputCredit(credit);
  srand(time(NULL));
  
    do
    {
        
        displayCredit(credit);
        float bet{inputBet(credit)};
        newCredit(credit, bet);
        int wheelOneNum{wheelSpin()};
        int wheelTwoNum{wheelSpin()};
        int wheelThreeNum{wheelSpin()};
        int wheelFourNum{wheelSpin()};
        std::string carOne{numberToCar(wheelOneNum)};
        std::string carTwo{numberToCar(wheelTwoNum)};
        std::string carThree{numberToCar(wheelThreeNum)};
        std::string carFour{numberToCar(wheelFourNum)};
        displayCars(carOne, carTwo, carThree, carFour);
        while (true)
        {
            if (determineWin3(carOne, carTwo, carThree, carFour, bet))
            {
                winThree(credit, bet);
                break;
            }
            if (determineWin2(carOne, carTwo, carThree, carFour, bet))
            {
                winTwo(credit, bet);
                break;
            }
            if (determineWin1(carOne, carTwo, carThree, carFour, bet))
            {
                winOne(credit, bet);
                break;
            }
            break;
        }
    
    } while (true);
    
	
	return 0;
}

void displayGreeting(std::string greeting)
{
    std::cout << greeting;
}

void inputCredit( float& credit)
{
    while(true)
    {
    std::cout << "Enter your initial deposit: $";
    std::cin >> credit;
    if(credit > 0)
       break;
       std::cout << "Please enter a deposit greater than zero. \n";
       std::cout << "Enter your initial deposit: $";
       std::cin >> credit;
    }

}

void displayCredit (float credit)
{
    std::cout << "Your credit is $" << credit << std::endl;
}

float inputBet(float credit)
{
    float bet;

     if (credit == 0)
    {
        std::cout << "You have run out of credit. \nThanks for playing Supercar Slots.";
        exit(0);
    }

    while (true)
    {
    std::cout << "Enter your bet: $";
    std::cin >> bet;
     if(credit >= bet)
     break;

    std::cout << "Your bet must be less than or equal to your total amount of credits. \n";
    }

    if (bet < 0)
    {
        std::cout << "Returning  $" << credit << std::endl;
        std::cout << "Thanks for playing Supercar Slots";
        exit(0);
    }

    return bet;
    
}

void newCredit (float& credit, float bet)
{
    credit = credit - bet;
    

}

int wheelSpin()
{
    
    int spinCount{random (9, 1001)};
    int wheelNum{spinWheel(spinCount)};
    return wheelNum;


}



int random(int start, int end)
{
    int spinCount;
    spinCount = rand() % (end-start) + start;
    return spinCount;
}

int spinWheel (int spinCount)
{
    int randValue;
    for (size_t i = 0; i < spinCount; i++)
    {
        randValue = random(1, 7);
    }
    return randValue;
}

std::string numberToCar(int carNum)
{
    std::string carName;
    switch (carNum)
    {
    case 1:
        carName = "Ferrari";
        return carName;
        break;
    case 2: 
        carName = "Lamborghini";
        return carName;
        break;
    case 3: 
        carName = "Bugatti";
        return carName;
        break;
    case 4: 
        carName = "McLaren";
        return carName;
        break;
    case 5: 
        carName = "Koenigsegg";
        return carName;
        break;
    case 6: 
        carName = "Maserati";
        return carName;
        break;
    }
}

void displayCars(std::string first, std::string second, std::string third, std::string fourth)
{
    std::cout << "The machine rolled \n" << first << " - "  << second << " - " << third << " - " << fourth << std::endl;
}

bool determineWin3(std::string first, std::string second, std::string third, std::string fourth, float bet) 
{
    if (first == second && first == third && first == fourth)
    {
        std::cout << "You won $" << 10 * bet << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool determineWin2(std::string first, std::string second, std::string third, std::string fourth, float bet) 
{
    if (first == second && first == third || first == fourth && first == second || second == third && second == fourth || first == third && first == fourth)
    {
        std::cout << "You won $" << 1.5 * bet << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool determineWin1(std::string first, std::string second, std::string third, std::string fourth, float bet) 
{
 if (first == second || first == third || first == fourth || second == third || second == fourth || third == fourth)
    {
        std::cout << "You won $" <<  bet << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void winThree(float& credit, float bet)
{
    credit = credit + bet * 10;
}

void winTwo(float& credit, float bet)
{
    credit = credit + bet * 1.5;
}

void winOne(float& credit, float bet)
{
    credit = credit + bet;
}