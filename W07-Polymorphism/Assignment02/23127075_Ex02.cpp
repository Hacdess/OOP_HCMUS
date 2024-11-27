#include <iostream>
#include "header.h"

using namespace std;

void foo(A *obj1, A obj2) {
    obj1->display();
    obj2.display();
}

int main() {
    char s[] = "text";
    B obj1(s);
    A *obj2 = new B(obj1);
    foo(&obj1, *obj2);

    cout << "\nInput obj1: ";
    cin >> obj1;
    cout << "Obj1: " << obj1 << "\n\n";

    cout << "Input obj2: ";
    cin >> *obj2;
    cout << "Obj2: " << *obj2; 

    delete obj2;

    return 0;
}