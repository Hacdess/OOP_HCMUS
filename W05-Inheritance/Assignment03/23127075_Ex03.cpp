#include "BaseDerived.h"

int main() {
    Base b1;
    Base b2(3);
    Base* pb = new Base(1);
    DerivedA da1;
    DerivedA da2(2);
    DerivedA da3(2, 3);
    DerivedA da4(da2);
    pb = new DerivedA(4, 5);
    DerivedB db1;
    DerivedB db2(2.7);
    DerivedB db3(3, 2.7);
    DerivedB db4(db2);
    pb = new DerivedB(4, 5);
    f(b1);
    f(da1);
    f(db1);
    delete pb;
    return 0;
}