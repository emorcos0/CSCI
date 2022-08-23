

const int MAX_COUNT {1000};
double entries[MAX_COUNT];
int entryCount{0};

int count() {return entryCount;}

bool isEmpty() { return count() == 0; }

bool add(double entry)
{
    if(entryCount == MAX_COUNT)
        return false;

    entries[entryCount++] = entry;
    return true;
}

double remove()
{
    if(isEmpty())
        return 0;
    
    return entries[--entryCount];
}

bool remove(double entry)
{
    bool found{false};
    for (int i = 0; i < entryCount; ++i)
    {
        if(entries[i] == entry)
        {
            entries[i] = remove();
            found = true;
            --i;
        }

    }

    return found;
}

void clear(){entryCount = 0;}

int getFreq(double entry)
{
    int count{0};
    for (int i = 0; i < entryCount; ++i)
        if(entries[i] == entry)
            ++count;
    
    return count;
}

bool contains(double entry)
{
    for (int i = 0; i < entryCount; ++i)
        if(entries[i] == entry)
            return true;

    return false;
}

double max()
{
    double max{entries[0]};
    if(isEmpty())
        return 0;

    for (int i = 1; i < entryCount; ++i)
        if(entries[i] > max)
            max = entries[i];

    return max;
}

double min()
{
  double min{entries[0]};
    if(isEmpty())
        return 0;

    for (int i = 1; i < entryCount; ++i)
        if(entries[i] < min)
            min = entries[i];

    return min;
}

void insertionSort()
{
    double val;
    int i, j;
    for (i = 1; i < entryCount; ++i)
    {
        val = entries[i];
        for (j = i - 1; j >= 0 && entries[j] > val; --j)
            entries[j + 1] = entries[j];

        entries[j + 1] = val;
    }
}

double median()
{
    insertionSort();

    return entries[(entryCount - 1) / 2];
}