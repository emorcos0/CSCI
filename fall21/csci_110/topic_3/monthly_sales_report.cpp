#include <iostream>
#include <string>

float inputData(std::string);
float calcState(float);
float calcCounty(float);
float calcTotal(float,float);
void printTotals(std::string, float);

int main()
{

    float totalSales{inputData("What are your total sales: ")};
    float stateTax{calcState(totalSales)};
    float countyTax{calcCounty(totalSales)};
    float totalTax{calcTotal(countyTax, stateTax)};
    printTotals("The state tax is ", stateTax);
    printTotals("The county tax is ", countyTax);
    printTotals("The total tax is ", totalTax);

    return 0;

}


float inputData(std::string msg)
{
    float totalSales;
    std::cout << msg;
    std::cin >> totalSales;
    return totalSales;
}


float calcState(float sales)
{
    float stateTax;
    stateTax = sales * .04;
    return stateTax;
}

float calcCounty(float sales)
{
    float countyTax;
    countyTax = sales * .02;
    return countyTax;
}

float calcTotal(float county, float state)
{
    float totalTax;
    totalTax = county + state; 
    return totalTax;
}

void printTotals(std::string total, float tax)
{
    std::cout << total << tax << std::endl;

}