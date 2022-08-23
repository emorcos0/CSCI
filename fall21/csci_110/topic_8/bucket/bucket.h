#include <stdexcept>

const int MAX_COUNT {1000};

#ifndef BUCKET_H
#define BUCKET_H

class Bucket
{

public: 

    int count(); 

    bool isEmpty(); 

    bool add(double entry);

    double remove();
    int getFreq(double entry);
    bool contains(double entry);

    bool remove(double entry);
 

    void clear();

    


    

private: 
    double entries[MAX_COUNT];
    int entryCount{0};

    bool remove(double entry, int, int);
 
  
    bool remove(double entry, int);
    int getFreq(double entry, int);
   
    bool contains(double, int);

};

#endif

