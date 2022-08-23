const int MAX_COUNT{1000};
int qtyGrades{0};
double grade[MAX_COUNT];

int count()
{
    return qtyGrades;
}

bool isEmpty()
{
    if (qtyGrades == 0)
    {
        return true;
    }
    return false;
}

bool add(double entry)
{
    if (qtyGrades >= MAX_COUNT)
        return false;
    else
    {
        grade[qtyGrades] = entry;
        ++qtyGrades;
        return true;
    }
}

double remove()
{
    double removed;
    removed = grade[qtyGrades - 1];
    qtyGrades--;
    return removed;
}

void swap(double &entry, double &end)
{
    double temp;
    temp = entry;
    entry = end;
    end = temp;
}

bool remove(double entry)
{
    for (int i = 0; i < qtyGrades; i++)
    {
        if (grade[i] == entry)
        {
            swap(grade[i], grade[qtyGrades - 1]);
            remove();
            return true;
        }
    }
    return false;
}

void clear()
{
    while (qtyGrades != 0)
        remove();
}

int getFreq(double entry)
{
    int freq{0};
    for (int i = 0; i < qtyGrades; i++)
    {
        if (grade[i] == entry)
            freq++;
    }
    return freq;
}

void insertionSort(double array[], int size)
{
    double val;
    int i, j;
    for (i = 1; i < size; ++i)
    {
        val = array[i];
        for (j = i - 1; j >= 0 && array[j] > val; --j)
            array[j + 1] = array[j];

        array[j + 1] = val;
    }
}

double max()
{
    insertionSort(grade, qtyGrades);

    return grade[qtyGrades - 1];
}

double min()
{
    insertionSort(grade, qtyGrades);

    return grade[0];
}

double median()
{
    insertionSort(grade, qtyGrades);
    double median{grade[qtyGrades / 2]};
    return median;
}

bool contains(double entry)
{
    for (int i = 0; i < qtyGrades; i++)
        if (grade[i] == entry)
            return true;
    return false;
}

int qtyLetterGrade(double min, double max)
{
    int Lgrade{0};
    for (int i = 0; i < qtyGrades; i++)
        if (max > grade[i] && grade[i] >= min)
            ++Lgrade;
    return Lgrade;
}

bool isFull()
{
    if (qtyGrades == MAX_COUNT)
    {
        return true;
    }
    return false;
}
