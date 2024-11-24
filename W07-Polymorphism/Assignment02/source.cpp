#include "header.h"

// Default constructor
A:: A() {
    m_s = strdup("default");
}

// Copy string only!
A::A(char *s) {
    m_s = strdup(s);
}

A::A(const A &other) {
    this->m_s = strdup(other.m_s);
}

A::~A()
{
    delete[] m_s;
    m_s = nullptr;
}

void A::prepare() {
    cout << "A ";
}

void A::display() {
    prepare();
    cout << m_s << endl;
}

// need to call A's parameterized constructor
B::B(char *s) : A(s) { }

// need to call A's copy constructor
B::B(const B& b) : A(b) { }

void B::prepare() {
    cout << "B ";
}

void foo(A *obj1, A obj2) {
    obj1->display();
    obj2.display();
}