#include <iostream>
#include <cstring>
using namespace std;

class A {
private:
    char *m_s;
public:
    A();
    A(char *s);
    A(const A& other); // must add copy constructor
    ~A(); // must add destructor
    virtual void prepare();
    void display();
};

class B : public A {
public: 
    B(char *s);
    B(const B& b);
    void prepare() override; // add keyword override
};

void foo(A *obj1, A obj2);