#ifndef _OFFICEEMPLOYEE_H_
#define _OFFICEEMPLOYEE_H_

#include "Employee.h"

class OfficeEmployee : public Employee {
private:
    int workingDays;
    const int payRatePerDay = 300000;

public:
    // Default constructor
    OfficeEmployee();

    // Parameterized constructor
    OfficeEmployee(const string& id, const string &fullName, const string &hireDate, const string &address, int workingDays);

    // Copy constructor
    OfficeEmployee(const OfficeEmployee &other);

    // Move constructor
    OfficeEmployee(OfficeEmployee &&other) noexcept;

    // String-extracting constructor
    OfficeEmployee(const string &data);

    void input() override;
    void print() const override;
    long computeSalary() const override;
};

#endif
