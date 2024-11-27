#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class A {
private:
    char *m_s;

public:
    A();
    A(char *s);
    A(const A& other);
    virtual ~A();
    virtual void prepare();
    void display();
    friend istream& operator>>(istream& is, A& a);
    friend ostream& operator<<(ostream& os, const A& a);
};

class B : public A {
public: 
    B(char *s);
    B(const B& b);
    void prepare() override;
    friend istream& operator>>(istream& is, B& b);
    friend ostream& operator<<(ostream& os, const B& b);
};

#endif
