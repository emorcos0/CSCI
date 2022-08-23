// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include <array>
#include <cstdlib>

const int SIZE = 10000;

//prototypes go here

bool contains(const std::array<int, SIZE>&, int);
int min(const std::array<int, SIZE>&);
int max(const std::array<int, SIZE>&);




int main(int argc, char const *argv[])
{
    //parameter type is std::array<int, 100> if you want to pass it. usually pass by reference.
	std::array<int, SIZE> values;
    int evenNums{0};
    int sum{0};
    int num{1};
    for (int i = 0; i < values.size(); i++)
    {
      //  values[i] = num++;
      //  values[i-1] = i;
     //   evenNums += 2;
     values[i] = rand();
    }

    std::cout << "The smallest value in the array is "
              << min(values) << " and the largest value is "
              << max(values) << std::endl;
    
    //for each format on next line
//    for (int i = 0; i < values.size(); i++)
//         sum += values[i];
//     //  std::cout << val << std::endl;
//     std::cout << "The average value is " << sum/values.size() << std::endl;
  //  std::cout << contains(values, 33) << std::endl;
  //  std::cout << contains(values, 200) << std::endl;
  //  std::cout << contains(values, -3) << std::endl;
  //  std::cout << contains(values, 58) << std::endl;
  //  std::cout << contains(values, 5537) << std::endl;
	
	return 0;
}

bool contains(const std::array<int, SIZE>& haystack, int needle)
{
    for(int val : haystack)
        if(val == needle)
        return true;
     
    return false;
}

int min(const std::array<int, SIZE>& values)
{
    int min{values[0]};
    for (int i = 1; i < values.size(); i++)
      {  if(values[i] < min)
        min = values[i];
      }
    return min;
}

int max(const std::array<int, SIZE>& values)
{
    int max{values[0]};
    for (int i = 1; i < values.size(); i++)
      {  if(values[i] > max)
        max = values[i];
      }
    return max;
}