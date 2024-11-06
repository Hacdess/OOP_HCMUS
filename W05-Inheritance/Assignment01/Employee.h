#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Employee {
protected:
    int id;
    string fullName;
    string hireDate;
    string address;

public:
    // 1. Default constructor
    Employee();

    // 2. Parameterized constructor
    Employee(int id, const string &fullName, const string &hireDate, const string &address);

    // 3. Copy constructor
    Employee(const Employee &other);

    // 4. Move constructor
    Employee(Employee &&other) noexcept;

    // 5. String-extracting constructor
    Employee(const string &data);

    virtual void input();
    virtual void print() const;
    virtual int computeSalary() const = 0;
};

#endif
