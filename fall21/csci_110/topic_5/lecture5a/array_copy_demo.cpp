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

bool contains(const int[], int SIZE, int);
int min(const int[], int SIZE);
int max(const int[], int SIZE);
void arrayCopy(const int[], int, int[], int);


int main(int argc, char const *argv[])
{
    
	  int values[SIZE];
    int copy[SIZE*2];
    

 
    for (int i = 0; i < SIZE; i++)
    {
 
     values[i] = rand();
    }

    std::cout << "The smallest value in the array is "
              << min(values, SIZE) << " and the largest value is "
              << max(values, SIZE) << std::endl;
    
    
	
	return 0;
}

bool contains(const int haystack[], int SIZE, int needle)
{
    for (int i = 1; i < SIZE; i++)
      if(haystack[i] == needle)
      return true;
  return false;
}

int min(const int values[], int SIZE)
{
    int min{values[0]};
    for (int i = 1; i < SIZE; i++)
      {  if(values[i] < min)
        min = values[i];
      }
    return min;
}

int max(const int values[], int SIZE)
{
    int max{values[0]};
    for (int i = 1; i < SIZE; i++)
      {  if(values[i] > max)
        max = values[i];
      }
    return max;
}

void arrayCopy(const int left[], int leftSz, int right[], int rightSz)
{
  int sz = (leftSz < rightSz) ? leftSz : rightSz;
  for (int i = 0; i < sz; i++)
  right[i] = left[i];
   
}