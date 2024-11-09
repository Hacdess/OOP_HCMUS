#include "BaseDerived.h"

Base::Base() {
    cout << "Base constructor-0 param" << endl;
    t = 0;
}

Base::Base(int u) {
    cout << "Base constructor-1 param" << endl;
    t = u;
}

Base::Base(const Base& b) {
    t = b.t;
    cout << "Base copy constructor" << endl;
}

Base::~Base() {
    cout << "Base destructor" << endl;
}

DerivedA::DerivedA() {
    cout << "DerivedA constructor-0 param" << endl;
    a = 0;
}

DerivedA::DerivedA(int x) {
    cout << "DerivedA constructor-1 param" << endl;
    a = x;
}

DerivedA::DerivedA(int u, int x) {
    cout << "DerivedA constructor-2 params" << endl;
    a = x;
}

DerivedA::DerivedA(const DerivedA& da) {
    a = da.a;
}

DerivedA::~DerivedA() {
    cout << "DerivedA destructor" << endl;
}

void DerivedA::print() {
    cout << "DerivedA = " << a << endl;
}

DerivedB::DerivedB() {
    cout << "DerivedB constructor-0 param" << endl;
    b = 0;
}

DerivedB::DerivedB(float x) {
    cout << "DerivedB constructor-1 param" << endl;
    b = x;
}

DerivedB::DerivedB(int u, float x) : Base(u) {
    cout << "DerivedB constructor-2 params" << endl;
    b = x;
}

DerivedB::DerivedB(const DerivedB& db) : Base(db) {
    cout << "DerivedB copy constructor" << endl;
    b = db.b;
}

DerivedB::~DerivedB() {
    cout << "DerivedB destructor" << endl;
}

void DerivedB::print() {
    cout << "DerivedB = " << b << endl;
}

void f(Base b) {
    cout << "Function f" << endl;
}