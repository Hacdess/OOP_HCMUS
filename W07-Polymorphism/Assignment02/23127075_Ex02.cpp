#include "header.h"

// error: '::main' must return 'int'
int main() {
    // ISO C++ forbids converting a string constant to 'char*' 
    char s[] = "text";
    B obj1(s);

    A *obj2 = new B(obj1);

    foo(&obj1, *obj2);


    // deallocate obj2
    delete obj2;
    return 0;
}