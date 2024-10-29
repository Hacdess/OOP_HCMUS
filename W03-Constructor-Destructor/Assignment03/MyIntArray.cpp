#include "MyIntArray.h"

MyIntArray::MyIntArray() {
    cout << "MyIntArray::Default constructor" << endl;
    n = 0;
    a = nullptr;
}

MyIntArray::MyIntArray(int *a, int n) {
    cout << "MyIntArray::Parameterized constructor" << endl;

    if (n < 1) {
        this->n = 0;
        a = nullptr;
    }
    else {
        this->n = n;
        this->a = new int[n];
        for (int i = 0; i <= n; ++i)
            this->a[i] = a[i];
    }
}

MyIntArray::MyIntArray(const MyIntArray &other) {
    cout << "MyIntArray::Copy constructor" << endl;

    this->n = other.n;
    if (n < 1)
        a = nullptr;
    else {
        a = new int[n];
        for (int i = 0; i < n; ++i)
            this->a[i] = other.a[i];
    }
}

MyIntArray::MyIntArray(MyIntArray &&other) noexcept {
    cout << "MyIntArray::Move constructor" << endl;

    this->n = other.n;
    this->a = other.a;
    other.n = 0;
    other.a = nullptr;
}

MyIntArray::MyIntArray(string s) {
    cout << "MyIntArray::String-extracting constructor" << endl;

    stringstream ss(s);
    ss >> n;
    char c;
    ss >> c;
    if (n < 1)
        a = nullptr;
    else {
        a = new int[n];
        for (int i = 0; i < n; ++i)
            ss >> a[i];
    }
}

MyIntArray::~MyIntArray() {
    cout << "MyIntArray::Destructor" << endl;

    n = 0;
    delete[] a;
    a = nullptr;
}

string MyIntArray::toString() {
    if (n < 1)
        return "Empty";
    
    string res = "";
    for (int i = 0; i < n; ++i)
        res += (to_string(a[i]) + ' ');

    return res;
}

MyIntArray *MyIntArray::clone() {
    cout << "Cloning...\n";
    return new MyIntArray(*this);
}
