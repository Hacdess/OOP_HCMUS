#ifndef _WORKER_H_
#define _WORKER_H_

#include "Employee.h"

class Worker : public Employee {
private:
    int producedItems;
    const int payRatePerItem = 5000;

public:
    // Default constructor
    Worker();

    // Parameterized constructor
    Worker(const string& id, const string &fullName, const string &hireDate, const string &address, const int& producedItems);

    // Copy constructor
    Worker(const Worker &other);

    // Move constructor
    Worker(Worker &&other) noexcept;

    // String-extracting constructor
    Worker(const string &data);

    void input() override;
    void print() const override;
    long computeSalary() const override;
};

#endif