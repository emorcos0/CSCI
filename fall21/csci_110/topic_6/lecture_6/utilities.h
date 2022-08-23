#include <string>
#include <fstream>

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
            str[i] -= 'a' - 'A';
    // can also do follow instead
    // str[i] = str[i]  ('a' - 'A');

    return str;
}

void insertionSort(int array[], int size)
{
    int val;
    int i, j;
    for (i = 1; i < size; ++i)
    {
        val = array[i];
        for (j = i - 1; j >= 0 && array[j] > val; --j)
            array[j + 1] = array[j];

        array[j + 1] = val;
    }
}

int random(int start, int end)
{
    return rand() % (end - start) + start;
}

template <typename T>
void swap(T &left, T &right)
{
    T temp = left;
    left = right;
    right = temp;
}


void swap(int &left, int &right)
{
    int temp = left;
    left = right;
    right = temp;
}

void swap(char& left, char& right)
 {
     char temp = left;
     left = right;
     right = temp;
 }


int binarySearch(int array[], int size, int term)
{
    int start{0};
    int end{size - 1};
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        // can also do mid = (start + end) >> 1;
        // >> means shift to the right. >> n, we divide by 2^n
        // << n, we multiply by 2^n

        if (array[mid] == term)
            return mid;

        if (array[mid] > term)
            end = mid - 1;

        if (array[mid] < term)
            start = mid + 1;
    }
    return -1;
}

// Two Functions
// read from a file records as strings into an array

size_t load(std::string array[], size_t size, std::string filename, char recordDelim)
{
    size_t index{0};
    std::ifstream file;

    file.open(filename);

    for (index = 0; index < size; ++index)
        if (!(std::getline(file, array[index], recordDelim)))
            break;

    file.close();
    return index;
}

size_t load(std::string array[], size_t size, std::string filename)
{
    load(array, size, filename, '\n');
}
// write two a file records as strings from an array

void store(std::string array[], size_t size, std::string filename, char recordDelim)
{
    std::ofstream file;
    
    file.open(filename);

    for (int index = 0; index < size; ++index)
    {
        file << array[index] << recordDelim;
    }
    
    file.close();
}

void store(std::string array[], size_t size, std::string filename)
{
    store(array, size, filename, '\n');
}