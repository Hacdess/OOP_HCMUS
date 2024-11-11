#include "BaseDerived.h"

int main() {
    Base b1;
    cout << endl;
    Base b2(3);
    cout << endl;

    Base* pb = new Base(1);
    cout << endl;

    DerivedA da1;
    cout << endl;

    DerivedA da2(2);
    cout << endl;

    DerivedA da3(2, 3);
    cout << endl;

    DerivedA da4(da2);
    cout << endl;

    pb = new DerivedA(4, 5);
    cout << endl;
    cout << endl;

    DerivedB db1;
    cout << endl;

    DerivedB db2(2.7);
    cout << endl;

    DerivedB db3(3, 2.7);
    cout << endl;

    DerivedB db4(db2);
    cout << endl;

    pb = new DerivedB(4, 5);
    cout << endl;
    cout << endl;

    f(b1);
    cout << endl;

    f(da1);
    cout << endl;

    f(db1);
    cout << endl;
    cout << endl;

    delete pb;
    cout << endl;

    return 0;
    cout << endl;

}