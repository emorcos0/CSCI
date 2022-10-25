#include <iostream>
#include <vector>
#include <string>
#define VAL 10

int main(int argc, char const *argv[])
{
    int i{};
    std::string s{};

    //std::cout << "Enter an integer greater than 0: ";
   // std::cin >> i;

    std::cout << "Enter a string: ";
    std::cin >> s;

    i <<= 1;

    std::vector<int> v {1,2,3,4,5,i};

    std::cout << s << std::endl;

    //for (int &i: v) i = 20;

    //v.push_back(55);

    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << std::endl;
    

    for(int i: v) std::cout << i << std::endl;

    // do
    // {
    //    std::cout << i << std::endl;
    //   //  if(i <= 0) break;
    // } while(i-- > 0);
    
    //std::cout << VAL << std::endl;
    return 0;
}
