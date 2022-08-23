#ifndef BUCKET_H
#define BUCKET_H

const int MAX_COUNT {1000};

class Bucket
{
public: 
    double remove(double entry)
    {
        if(remove(entry, 0, entryCount))
        return entry;
    }
    int count();
    bool isEmpty();
    bool add(double entry);
    void clear();
    int getFreq(double entry);
    bool contains(double entry);

private:
    double entries[MAX_COUNT];
    int entryCount{0};
    bool remove(double entry, int start, int end);

};



#endif