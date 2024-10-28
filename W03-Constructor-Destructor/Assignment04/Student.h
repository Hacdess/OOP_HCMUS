#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;

class Student {
    private:
        int id;
        char* fullname;
        char* address;
        double gpa;
    public:
        // Default constructor
        Student();

        // Parameterized constructor
        string formatGPA();
        Student(int id, string fullname, string address, double gpa);

        // Copy constructor
        Student(const Student &other);

        // Move constructor
        Student(Student &&other) noexcept;

        // String-extracting constructor
        Student(string s);

        // Destructor
        ~Student();

        string toString();
        Student* clone();
};


#endif