#include "Company.h"

Company::~Company()
{
    int n = employees.size();
    for (int i = 0; i < n; ++i)
        delete employees[i];
    employees.clear();
}

void Company::inputEmployees()
{
    int n, type;
    do {
        cout << "Input the number of employees to input (non-negative integer): ";
        cin >> n;
    } while (n < 0);

    for (int i = 0; i < n; ++i) {
        cout << "\nInput employee's type (1: Office Employee, 2: Worker): ";
        cin >> type;
        Employee* employee = nullptr;

        if (type == 1) employee = new OfficeEmployee();
        else if (type == 2) employee = new Worker();
        else {
            cout << "Invalid type!\n";
            continue;
        }

        employee->input();
        employees.push_back(employee);
    }
}

void Company::printAllEmployees() const
{
    int n = employees.size();

    for (int i = 0; i < n; ++i)
    {
        employees[i]->print();
        cout << "Monthly salary: " << employees[i]->computeSalary() << " VND\n\n";
    }
}

long Company::computeTotalSalary() const
{
    long total = 0;
    int n = employees.size();
    for (int i = 0; i < n; ++i)
        total += employees[i]->computeSalary();
    return total;
}

void Company::printHighestSalaryEmployees() const
 {
    long maxSalary = 0;
    int n = employees.size();

    for (int i = 0; i < n; ++i)
        if (employees[i]->computeSalary() > maxSalary)
            maxSalary = employees[i]->computeSalary();


    cout << "Employees whose salaries are the biggest value in the company:\n";
    for (int i = 0; i < n; ++i)
        if (employees[i]->computeSalary() == maxSalary) {
            employees[i]->print();
            cout << "Monthly salary: " << maxSalary << " VND\n\n";
        }
}
