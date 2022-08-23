// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

int random(int, int);
int getWordCount();
bool getSeperatorChoice();
bool getUppercaseChoice();
std::string getPassword(int, bool, bool);
int loadArray(std::string[], int size, const std::string&);
void setRandomUppercase(std::string&);
bool contains(const std::string& haystack, const std::string& needle);

//globals
const int WORDS_SIZE{10000};
const std::string WORDS_FILENAME{"wordlist.txt"};
const std::string CHARS_FILENAME{"special_chars.txt"};
const int CHARS_SIZE{100};

int main(int argc, char const *argv[])
{
	srand(time(NULL));
    int wordCount{getWordCount()};
    bool wantsSeperator{getSeperatorChoice()};
    bool wantsUppercase{getUppercaseChoice()};


    std::cout << "Your password is: " << getPassword(wordCount, wantsSeperator, wantsUppercase) << std::endl;
    /**
     * get word qty
     * get wants seperators
     * get want random uppercase char
     * 
     * return password
    */



	
	return 0;
}

int random(int start, int end)
{
    return (rand() % (end - start)) + start;
}

int getWordCount()
{
    int count;
    std::cout << "How many words? ";
    std::cin >> count;
    return count;
}

bool getSeperatorChoice()
{
    char choice;
    std::cout << "Do you want a random seperator character (y/n)? ";
    std::cin >> choice;
    return tolower(choice) == 'y';
}

bool getUppercaseChoice()
{
    char choice;
    std::cout << "Do you want a random uppercase character in each word (y/n)? ";
    std::cin >> choice;
    return tolower(choice) == 'y';
}

std::string getPassword(int wordCount, bool wantsSeperator, bool wantsUppercase)
{
    std::string password;
    std::string word;
    std::string noRep;
    std::string words[WORDS_SIZE];
    std::string chars[CHARS_SIZE];

    int wordsQty{loadArray(words, WORDS_SIZE, WORDS_FILENAME)};
    int charsQty{0};
    if(wantsSeperator)
        charsQty = loadArray(chars, CHARS_SIZE, CHARS_FILENAME);

    word = words[random(0, wordsQty)];
    noRep += word + " ";

    for (int i = 1; i < wordCount; i++)
    {
        
        if(wantsUppercase)
            setRandomUppercase(word);

        password += word + (wantsSeperator && i < wordCount -1 ? chars[random(0, charsQty)] : "");
        do
        {
             word = words[random(0, wordsQty)];
        } while (noRep.find(word) != std::string::npos);

        noRep += word + " ";
        
    }
    
    return password;
    
}

//returns number of strings loaded
int loadArray(std::string array[], int size, const std::string& filename)
{
    std::ifstream file;
    file.open(filename);
    int count {0};
    while(count < size && std::getline(file, array[count]))
        ++count;
    file.close();
    return count;
}

void setRandomUppercase(std::string& word)
{
    int index {random(0, word.length())};
    word[index] = toupper(word[index]);
}