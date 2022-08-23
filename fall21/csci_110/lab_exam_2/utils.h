

#include <string>
#include <cstdlib>
#include <ctime>

#define RANDOMIZE_COUNT 600000

void swap(int &, int &);
int minIndex(int[], int, int);  //finds the index of the minimum value between start and end
void bubbleSort(int[], int);    // sorts array using bubble sort
void selectionSort(int[], int); //sorts array using selection sort algorithm
void insertionSort(std::string &);
void insertionSort(int[], int); // sorts array using insertion sort algorithm
int binarySearch(int array[], int size, int term);
int binarySearch(int array[], int start, int end, int term);
std::string randomizeString(std::string);
int random(int, int);
char medianString(std::string);
//void swap(char&, char&);

template <typename T>
void swap(T &left, T &right)
{
    T temp = left;
    left = right;
    right = temp;
}

std::string randomizeString(std::string str)
{
    for (size_t i = 0; i < RANDOMIZE_COUNT; i++)
        swap<char>(str[random(0, str.length())], str[random(0, str.length())]);

    return str;
}

char medianString(std::string str)
{
    insertionSort(str);
    return str[str.length() / 2];
}

void swap(int &left, int &right)
{
    int temp = left;
    left = right;
    right = temp;
}

// void swap(char& left, char& right)
// {
//     char temp = left;
//     left = right;
//     right = temp;
// }

void bubbleSort(int array[], int size)
{
    for (int sorted = size; sorted >= 2; --sorted)
    {
        for (int ptr = 0; ptr <= sorted - 2; ptr++)
            if (array[ptr] > array[ptr + 1])
                swap(array[ptr], array[ptr + 1]);
    }
}

int minIndex(int array[], int start, int end)
{
    int minIndex{start};
    for (int i = start + 1; i <= end; ++i)
        if (array[minIndex] > array[i])
            minIndex = i;
    return minIndex;
}

void selectionSort(int array[], int size)
{
    int minIdx;
    for (int sorted = -1; sorted <= size - 2; sorted++)
    {
        minIdx = minIndex(array, sorted + 1, size - 1);
        if (minIdx != sorted + 1)
            swap(array[minIdx], array[sorted + 1]);
    }
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

void insertionSort(std::string &str)
{
    char c;
    int i, j;
    for (i = 1; i < str.length(); ++i)
    {
        c = str[i];
        for (j = i - 1; j >= 0 && str[j] > c; --j)
            str[j + 1] = str[j];

        str[j + 1] = c;
    }
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

int binarySearch(int array[], int start, int end, int term)
{
    int mid;

    if (start > end)
        return -1;

    mid = (start + end) / 2;
    // can also do mid = (start + end) >> 1;
    if (array[mid] == term)
        return mid;

    if (array[mid] > term)
        return binarySearch(array, start, mid - 1, term);

    return binarySearch(array, mid + 1, end, term);
}

int random(int start, int end)
{
    return rand() % (end - start) + start;
}