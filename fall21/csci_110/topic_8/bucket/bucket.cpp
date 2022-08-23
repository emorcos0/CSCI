#include "bucket.h"
#include <stdexcept>

int Bucket::count() {return entryCount;}

bool Bucket::isEmpty() { return count() == 0; }

bool Bucket::add(double entry)
{
    if(entryCount == MAX_COUNT)
        throw std::runtime_error("Bucket is full");

    entries[entryCount++] = entry;
    return true;
}

double Bucket::remove()
{
    if(isEmpty())
        throw std::runtime_error("Bucket is empty");
    
    return entries[--entryCount];
}

bool Bucket::remove(double entry)
 {
     return remove(entry, 0, entryCount);
 }

bool Bucket::remove(double entry, int start)
{
     if(start > entryCount)
        return false;
    if(entry == entries[start])
        {
            entries[start] = remove();
            return true;
        }

    return remove(entry, start + 1);
}

bool Bucket::remove(double entry, int start, int end)
{
    if(start > end)
        return false;
    if(entry == entries[start])
        {
            entries[start] = remove();
            return true;
        }

    return remove(entry, start + 1, end);
 
}

void Bucket::clear(){entryCount = 0;}

int Bucket::getFreq(double entry, int start)
{
    if(start >= entryCount)
        return 0; 

    return(entries[start] == entry ? 1 : 0) + getFreq(entry, start + 1);

}

bool Bucket:: contains(double entry, int start )
{
       if(start >= entryCount)
        return false;

        if(entries[start] == entry)
            return true;

        return entries[start] == entry ? true : contains(entry, start + 1); 

}

bool Bucket:: contains(double entry)
{
    return contains(entry, 0);
}

int Bucket::getFreq(double entry)
{
    return getFreq(entry, 0);
}





