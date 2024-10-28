#include "MyIntArray.h"

int main() {
    // Default constructor
    MyIntArray A;
    cout << "Array A: " << A.toString() << "\n\n";

    // Parameterized constructor
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;
    MyIntArray B(array, n);
    cout << "Array B: " << B.toString() << "\n\n";

    // Copy constructor
    MyIntArray C(B);
    cout << "Array C: " << C.toString() << "\n\n";

    // Move constructor
    MyIntArray D = move(C);
    cout << "Array D: " << D.toString() << "\n";
    cout << "Array C: " << C.toString() << "\n\n";

    // String-extracting constructor
    string s = "10, -4 -3 -2 -1 0 1 2 3 4 5";
    MyIntArray E(s);
    cout << "Array E: " << E.toString() << "\n\n";

    // Clone
    MyIntArray* F(E.clone());
    cout << "Array F: " << F->toString() << "\n\n";
    delete F;

    return 0;
}