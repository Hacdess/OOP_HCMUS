#ifndef _WORKER_H_
#define _WORKER_H_

#include "Employee.h"

class Worker : public Employee {
private:
    int itemsProduced;
    const int payRatePerItem = 20000;

public:
    // Default constructor
    Worker();

    // Parameterized constructor
    Worker(int id, const std::string &fullName, const std::string &hireDate, const std::string &address, int itemsProduced);

    // Copy constructor
    Worker(const Worker &other);

    // Move constructor
    Worker(Worker &&other) noexcept;

    // String-extracting constructor
    Worker(const std::string &data);

    void input() override;
    void print() const override;
    int computeSalary() const override;
};

#endif