#ifndef BUCKET_H
#define BUCKET_H
#include <stdexcept>

template <typename B, size_t S>

class Bucket
{
public:
    B remove(B entry)
    {
        if (remove(entry, 0, entryCount ))
            return entry;
        else
            throw std::runtime_error("value not contained");
    }

    int count() { return entryCount; }

    bool isEmpty()
    {
        if (entryCount == 0)
        {
            return true;
        }
        return false;
    }

    bool add(B entry)
    {
        if (entryCount >= S)
            return false;
        else
        {
            entries[entryCount] = entry;
            ++entryCount;
            return true;
        }
    }

    void clear()
    {
        entryCount = 0;
    }

    int getFreq(B entry)
    {
        int freq{0};
        for (int i = 0; i < entryCount; i++)
        {
            if (entries[i] == entry)
                freq++;
        }
        return freq;
    }

    bool contains(B entry)
    {
        for (int i = 0; i < entryCount; i++)
            if (entries[i] == entry)
                return true;
        return false;
    }

private:
    B entries[S];
    int entryCount{0};
    bool remove(B entry, int start, int end)
    {
        if (start == end)
            return false;
        for (int i = 0; i < end; i++)
        {
            if (entries[i] == entry)
            {
                swap(entries[i], entries[end]);
                --entryCount;
                return true;
            }
        }
        return false;
    }

    void swap(B &entry, B &end)
    {
        B temp;
        temp = entry;
        entry = end;
        end = temp;
    }
};

#endif
