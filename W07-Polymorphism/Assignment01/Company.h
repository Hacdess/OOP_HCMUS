#pragma once
#include "OfficeEmployee.h"
#include "Worker.h"
#include <vector>

class Company {
private:
    vector<Employee*> employees;

public:
    ~Company();

    void inputEmployees();

    void printAllEmployees() const;

    long computeTotalSalary() const;

    void printHighestSalaryEmployees() const;
};
