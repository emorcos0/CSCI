// who: emorcos
// what: Test Bucket Template
// why: C++ Custom Templates
// when: 11/29/2021

// includes go here
#include <iostream>
#include <string>
#include "bucket.h"
#include "widget.h"

template<typename T, size_t N>
void testIsEmpty(Bucket<T,N>& c)
{
    std::cout << "The bucket is currently: " << (c.isEmpty() ? "empty" : "not empty") << std::endl; 
}

template<typename T, size_t N >
void testAdd(Bucket<T,N>& c, T add1)
{
    std::cout << "We are now going to test 'add' on  " << add1 << ": " << (c.add(add1) ? "Was successful" : "Wasn't succesful") << std::endl;
}

template<typename T, size_t N>
void testCount(Bucket<T,N>& c)
{
    std::cout << "We are now going to test count: The count is " << c.count() << std::endl;
}

template<typename T, size_t N>
void testFreq(Bucket<T,N>& c, T var1)
{
    std::cout << "We are now testing frequency for: " << var1 << " which is " << c.getFreq(var1) << std::endl;
}

template<typename T, size_t N>
void testRemove (Bucket<T,N>& c, T var1)
{
    std::cout << "We are now test remove on: " << var1 << (c.remove(var1) == var1 ? " Succesful" : " Not successful") << std::endl;
    
}

template<typename T, size_t N>
void testContains (Bucket<T,N>& c, T var1)
{
    std::cout << "We are now testing contains on: " << var1 << (c.contains(var1) ? " Is contained" : " Not contained") << std::endl;
}

template<typename T, size_t N>
void testClear (Bucket<T,N>& c)
{
    std::cout << "We are now clearing the bucket" << std::endl; 
    c.clear();
}

int main(int argc, char const *argv[])
{
    Bucket<int, 1000> intgr;
    Bucket<double, 1001> dble;
    Bucket<Widget, 10> wdgt;

    std::cout << "Testing functions for Integer bucket: " << std::endl;
    testIsEmpty(intgr);
    testAdd(intgr, 3);
    testAdd(intgr, 4);
    testAdd(intgr, 4);
    testAdd(intgr, 8);
    testContains(intgr, 8);
    testContains(intgr, 9);
    testFreq(intgr, 4);
    testFreq(intgr, 3);
    testCount(intgr);
    testRemove(intgr, 3);
    testContains(intgr, 3);
    testCount(intgr);
    testClear(intgr);
    testIsEmpty(intgr);

    std::cout << "\n\nTesting functions for Double bucket: " << std::endl;
    testIsEmpty(dble);
    testAdd(dble, 3.0);
    testAdd(dble, 4.5);
    testAdd(dble, 4.5);
    testAdd(dble, 9.6);
    testAdd(dble, 4.5);
    testContains(dble, 8.0);
    testContains(dble, 9.6);
    testFreq(dble, 4.5);
    testFreq(dble, 3.0);
    testCount(dble);
    testRemove(dble, 3.0);
    testContains(dble, 3.0);
    testCount(dble);
    testClear(dble);
    testIsEmpty(dble);
    

    std::cout << "\n\nTesting functions for Widget bucket: " << std::endl;
    
    Widget w0{1, "B"};
    Widget w1 {2, "A"};
    Widget w2{3, "C"};
    Widget w3{5, "F"};
    Widget w;
    testIsEmpty(wdgt);
    testAdd(wdgt, w0);
    testAdd(wdgt, w1);
    testAdd(wdgt, w2);
    testAdd(wdgt, w3);
    testContains(wdgt, w2);
    testContains(wdgt, w1);
    testContains(wdgt, w);
    testFreq(wdgt, w1);
    testCount(wdgt);
    testRemove(wdgt, w1);
    testContains(wdgt, w1);
    testFreq(wdgt, w1);
    testCount(wdgt);
    testClear(wdgt);
    testIsEmpty(wdgt);

	
	
	return 0;
}


