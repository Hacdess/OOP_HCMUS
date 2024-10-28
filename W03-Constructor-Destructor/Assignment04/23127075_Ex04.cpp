#include "Student.h"

int main() {
    // Default constructor
    Student student1;
    cout << "Student 1:\n" << student1.toString() << "\n\n";

    // Parameterized constructor
    Student student2(1, "Nguyen Van A", "", 8.9);
    cout << "Student 2:\n" << student2.toString() << "\n\n";

    // Copy constructor
    Student student3(student2);
    cout << "Student 3:\n" << student3.toString() << "\n\n";

    // Move constructor
    Student student4 = move(student3);
    cout << "Student 4:\n" << student4.toString() << "\n\n";
    cout << "Student 3:\n" << student3.toString() << "\n\n";

    // String-extracting constructor
    string s = "1,Nguyen Van B,1 Green Street District 1,8.5";
    Student student5(s);
    cout << "Student 5:\n" << student5.toString() << "\n\n";

    // Clone
    Student* student6(student5.clone());
    cout << "Student 6:\n" << student5.toString() << "\n\n";
    delete student6;

    return 0;
}