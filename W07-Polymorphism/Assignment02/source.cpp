#include "header.h"

A::A() {
    m_s = strdup("default");
}

A::A(char *s) {
    m_s = strdup(s);
}

A::A(const A& other) {
    this->m_s = strdup(other.m_s);
}

A::~A() {
    free(m_s);
}

void A::prepare() {
    cout << "A ";
}

void A::display() {
    prepare();
    cout << m_s << endl;
}

istream& operator>>(istream& is, A& a) {
    string input;
    getline(is, input);

    if (a.m_s)
        free(a.m_s);

    a.m_s = strdup(input.c_str());
    return is;
}

ostream& operator<<(ostream& os, const A& a) {
    os << a.m_s;
    return os;
}

B::B(char *s) : A(s) { }

B::B(const B& b) : A(b) { }

void B::prepare() {
    cout << "B ";
}

istream &operator>>(istream &is, B &b) {
    return operator>>(is, (A&)b);
}

ostream &operator<<(ostream &os, const B &b) {
    os << (const A&)b;
    return os;
}
