#ifndef BASE_DERIVED_H
#define BASE_DERIVED_H

#include <iostream>
using namespace std;

class Base {
private:
    int t;
public:
    Base();
    Base(int u);
    Base(const Base& b);
    ~Base();
};

class DerivedA : public Base {
public:
    DerivedA();
    DerivedA(int x);
    DerivedA(int u, int x);
    DerivedA(const DerivedA& da);
    ~DerivedA();
    void print();
private:
    int a;
};

class DerivedB : public Base {
public:
    DerivedB();
    DerivedB(float x);
    DerivedB(int u, float x);
    DerivedB(const DerivedB& db);
    ~DerivedB();
    void print();
private:
    float b;
};

void f(Base b);

#endif // BASE_DERIVED_H