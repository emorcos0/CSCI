// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include <string>



//prototypes go here
std::string toLower(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
       if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + ('a' - 'A');
            // can also do following instead
            //str[i] += 'a' - 'A'

    return str;
}

std::string toUpper(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
       if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -=  'a' - 'A';
            // can also do follow instead
            // str[i] = str[i]  ('a' - 'A'); 

    return str;
}

int upperCharToIndex(char c)
{
    return c - 'A';
}

//this contains function is case sensitive
bool contains(std::string str, std::string subStr)
{
    int size {subStr.length()};
    bool found;
    for (size_t i = 0; i <= str.length() - size; i++)
    {
        if(str[i] == subStr[0])
        {
            found = true;
            for (size_t j = 0; j < size && found; j++)
            {
                if(str[i + j] != subStr[j])
                    found = false;
            }

         if(found) return true;   
        }
    }
    



    return false;
}

int main(int argc, char const *argv[])
{
	std::string str{"1) Foul deeds will RISE!"};

    //std::cout << toLower(str) << std::endl;
    //std::cout << toUpper(str) << std::endl;
    //std::cout << contains(str, "!") << std::endl;
    char c{'a' - 32};
    std::cout << c;
	
	return 0;
}

