#include "bucket.h"



int Bucket::count()
{
    return entryCount;
}

bool Bucket::isEmpty()
{
    if (entryCount == 0)
    {
        return true;
    }
    return false;
}

bool Bucket::add(double entry)
{
    if (entryCount >= MAX_COUNT)
        return false;
    else
    {
        entries[entryCount] = entry;
        ++entryCount;
        return true;
    }
}

void Bucket::clear()
{
    entryCount = 0;
}

int Bucket::getFreq(double entry)
{
    int freq{0};
    for (int i = 0; i < entryCount; i++)
    {
        if (entries[i] == entry)
            freq++;
    }
    return freq;
}

bool Bucket::contains(double entry)
{
      for (int i = 0; i < entryCount; i++)
        if (entries[i] == entry)
            return true;
    return false;
}

void swap(double &entry, double &end)
{
    double temp;
    temp = entry;
    entry = end;
    end = temp;
}

bool Bucket::remove(double entry, int start, int end)
{
    if (start == end)
        return false;

    if (entries[start] == entry)
    {
        swap(entries[start], entries[end]);
        --entryCount;
        return true;
    }
    else
        remove(entry, ++start, end);
}
