#include <iostream>
#include <tuple>

#include "test.h"
#include "keyvalue_pair.h"

int main(int argc, char const *argv[])
{
    KVPair<int,int> p1 {5,55};
    KVPair<int,int> p2{10,20};

    Tester<KVPair<int,int>> t(
        [] (KVPair<int,int> l, KVPair <int,int> r) {return l.key > r.key;} //anonymous lambda function
        );

    // tuple provided as a replacement for KV
    // Tester<std::tuple<int,int>> t(
    //     [] (std::tuple<int,int> l, std::tuple <int,int> r) {return l. > r.; } 
    //     );

        std::cout << std::boolalpha;

    //    std::cout << t.compare( {5,55}, {10,20} ) << std::endl;
        std::cout << (p1 < p2) << std::endl;

    return 0;
}
