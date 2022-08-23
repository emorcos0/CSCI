// who: emorcos
// what: generates a password
// why: files and file I/O
// when: 11/8/2021

// includes go here
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <ctime>


const int SIZE = 7779;
const int SPEC = 43;
const std::string FILENAME = "password.dat";
int getSize();
void wordsFile(std::string[], int);
int random(int start, int end);
void swap(std::string &, std::string &);
void randomChoose(std::string[], std::string[], int, int);
bool askChar();
void charsFile(char[], const int);
void swap(char &left, char &right);
void randomChoose(char spec[], char special[], int size, int SPEC);
bool askUpper();
void randomUp(std::string &);
void displayPass(char[], std::string[], int);
void displayPass(std::string[], int);
void store(std::string[], std::string, int);
void store(std::string[], char[], int, std::string);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    std::string words[SIZE];
    wordsFile(words, SIZE);
    
    
    
        while (true)
        {
            int size{getSize()};
            std::string password[size];
            randomChoose(words, password, size, SIZE);
            if (askChar())
            {
                char spec[SPEC];
                char special[size - 1];
                charsFile(spec, SPEC);
                randomChoose(spec, special, size, SPEC);
                if (askUpper())
                {
                    for (int i = 0; i < size; i++)
                        randomUp(password[i]);
                }
                displayPass(special, password, size);
                store (password, special, size, FILENAME);
                break;
            }

            if (askUpper())
            {
                for (int i = 0; i < size; i++)
                    randomUp(password[i]);
            }
            displayPass(password, size);
            store(password, FILENAME, size);
            break;
        }

      
    

    return 0;
}

int getSize()
{
    int size;
    while (true)
    {
        std::cout << "Enter the number of words you want in your password: ";
        std::cin >> size;
        if (size >= 1)
            break;

        std::cout << "Enter a size greater than 0" << std::endl;
    }
    return size;
}

void wordsFile(std::string words[], int SIZE)
{
    std::ifstream Wfile;
    Wfile.open("wordlist.txt");
    for (int i = 0; i < SIZE; i++)
    {
        Wfile >> words[i];
    }
    Wfile.close();
}

void randomChoose(std::string words[], std::string password[], int size, int SIZE)
{

    for (int i = 0; i < size; i++)
    {
       // if (SIZE == 0)
       //     SIZE = 7776;
        int rand{random(0, SIZE)};
        password[i] = words[rand];
        swap(words[rand], words[SIZE - 1]);
        SIZE--;
    }
}

void randomChoose(char spec[], char special[], int size, int SPEC)
{

    for (int i = 0; i < size - 1; i++)
    {
        //if (SPEC == 0)
        //    SPEC = 43;
        int rand{random(0, SPEC)};
        special[i] = spec[rand];
        swap(spec[rand], spec[SPEC - 1]);
        SPEC--;
    }
}

void swap(std::string &left, std::string &right)
{
    std::string temp = left;
    left = right;
    right = temp;
}

void swap(char &left, char &right)
{
    char temp = left;
    left = right;
    right = temp;
}

int random(int start, int end)
{
    return rand() % (end - start) + start;
}

bool askChar()
{
    char resp;
    while (true)
    {
        std::cout << "Would you like the words seperated by randomly chosen special characters? (y/n): ";
        std::cin >> resp;
        tolower(resp);
        if (resp == 'y' || resp == 'n')
            return resp == 'y';

        std::cout << "Invalid choice!!\n";
    }
}

void charsFile(char spec[], const int SPEC)
{
    spec[0] = ' ';
    std::ifstream Cfile;
    Cfile.open("special_chars.txt");
    for (int i = 1; i < SPEC; i++)
    {
        Cfile >> spec[i];
    }
    Cfile.close();
}

bool askUpper()
{
    char resp;
    while (true)
    {
        std::cout << "Would you like a random character from each word to be capitalized? (y/n): ";
        std::cin >> resp;
        tolower(resp);
        if (resp == 'y' || resp == 'n')
            return resp == 'y';

        std::cout << "Invalid choice!!\n";
    }
}

void randomUp(std::string &word)
{
    int ind{random(0, word.length())};

    word[ind] = word[ind] - 32;
}

void displayPass(char special[], std::string password[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << password[i] << special[i];
    }
}

void displayPass(std::string password[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << password[i];
    }
}

void store(std::string password[], std::string File, int size)
{
    char ag;
    std::cout << "\nWould you like to save this password? (y/n): ";
    std::cin >> ag;
    if ('A' < ag && ag < 'Z')
        ag = ag + 32;

    if (ag == 'y')
    {
        std::fstream file;

        file.open(File, std::ios::app);

        std::cout << "What is this password for?: ";
        std::string pS;
        std::cin >> pS;

        file << pS << ": ";

        for (int index = 0; index < size; ++index)
        {
            file << password[index];
        }
        file << std::endl;

        file.close();
    }
}

void store(std::string password[], char special[], int size, std::string File)
{
    char ag;
    std::cout << "\nWould you like to save this password? (y/n): ";
    std::cin >> ag;
    if ('A' < ag && ag < 'Z')
        ag = ag + 32;

    if (ag == 'y')
    {
        std::fstream file;

        file.open(File, std::ios::app);

        std::cout << "What is this password for?: ";
        std::string pS;
        std::cin >> pS;

        file << pS << ": ";

        for (int index = 0; index < size; ++index)
        {
            file << password[index] << special[index];
        }
        file << std::endl;

        file.close();
    }
}
