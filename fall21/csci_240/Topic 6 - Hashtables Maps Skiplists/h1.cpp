#include <iostream>
#include <cstdint>

union U  // can use as either a double or uint64_t
{
    double d;
    uint64_t i;
};

int h1(int k) { return k; }

int h1(uint64_t k)
{
    return static_cast<int>((k >> 32) ^ k);
}

int h1(double k)
{
    U u;
    u.d = k;
    return h1(u.i); 
}

int h1(const std::string& k)
{
    int hash{0};
    const int factor{31};

    for(size_t i{0}; i < k.length(); ++i)
        hash = factor * hash + k[i]; // Horner's Method
    return hash;
}

    int main(int argc, char const *argv[])
{

    return 0;
}
