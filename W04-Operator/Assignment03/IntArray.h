#ifndef _INT_ARRAY_H_
#define _INT_ARRAY_H_

#include <iostream>
using namespace std;

class IntArray {
private:
    int* arr;
    int size;
public:
    IntArray();
    ~IntArray();
    
    void Input();
    IntArray& operator=(const IntArray& other);
    friend ostream& operator<<(ostream& os, const IntArray& intArray);
    friend istream& operator>>(istream& is, IntArray& intArray);
    int& operator[](int index);
    operator int() const;

};


#endif