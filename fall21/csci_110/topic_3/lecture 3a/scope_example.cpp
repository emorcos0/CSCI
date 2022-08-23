#include <iostream>
#include <string>

void showMessage(std::string);
 std::string m;

int main(int argc, char const *argv[])
{
    
    {
     m = "War is hell";
    }

    showMessage(m);
    

    return 0;
}

void showMessage(std:: string msg)
{
    m = "macs are hell";
    std::cout << msg;
}