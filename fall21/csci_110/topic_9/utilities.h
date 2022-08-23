#include <ostream>

// Expect type T to have assignment operator overloaded
template <typename T>
void swap(T &a, T &b)
{
    T temp{a};
    a = b;
    b = temp;
}

template <typename T>
void arrayReverse(T array[], int start, int end)
{
    if (end <= start)
        return;

    swap<T>(array[start], array[end]);
    arrayReverse<T>(array, start + 1, end - 1);
}

//Expect type T to have greater-than operator overloaded
template <typename T, size_t N>
void insertionSort(T array[])
{
    T val;
    int i, j;
    for (i = 1; i < N; ++i)
    {
        val = array[i];
        for (j = i - 1; j >= 0 && array[j] > val; --j)
            array[j + 1] = array[j];

        array[j + 1] = val;
    }
}

template <typename T, size_t N>
void printArray(T array[], std::ostream &os)
{
    os << "[ ";
    for (int i = 0; i < N; i++)
    {
        os << array[i];
        os << (i < N - 1 ? ", " : " ]");
    }
}

// Expect type T to have assignment operator overloaded
template <typename T>
void arrayCopy(const T left[], size_t leftSz, T right[], size_t rightSz)
{
    size_t sz = (leftSz < rightSz) ? leftSz : rightSz;
    for (size_t i = 0; i < sz; i++)
        right[i] = left[i];
}

// Expect type T to have equality operator overloaded
// Expect type T to have greater-than operator overloaded
template <typename T>
int binarySearch(const T array[], const int start, const int end, const T& term)
{
    int mid;

    if(start > end) return -1;

    mid = (start + end) / 2;
    // can also do mid = (start + end) >> 1;
    if(array[mid] == term)
        return mid;

    if(array[mid] > term)
        return binarySearch<T>(array, start, mid - 1, term);

    return binarySearch<T>(array, mid + 1, end, term);
}
