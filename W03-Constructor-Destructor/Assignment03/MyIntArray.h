#ifndef _MY_INT_ARRAY_H_
#define _MY_INT_ARRAY_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class MyIntArray {
    private:
        int *a;
        int n;
    public:
        // Default constructor
        MyIntArray();

        // Parameterized constructor
        MyIntArray(int *array, int n);

        // Copy constructor
        MyIntArray(const MyIntArray &other);

        // Move constructor
        MyIntArray(MyIntArray &&other) noexcept;

        // String-extracting constructor
        MyIntArray(string s);

        // Destructor
        ~MyIntArray();

        string toString();
        MyIntArray* clone();
};

#endif