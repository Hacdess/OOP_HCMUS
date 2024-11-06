#include "OfficeEmployee.h"

// Default constructor
OfficeEmployee::OfficeEmployee() : Employee(), workingDays(0) {}

// Parameterized constructor
OfficeEmployee::OfficeEmployee(int id, const string &fullName, const string &hireDate, const string &address, int workingDays)
    : Employee(id, fullName, hireDate, address), workingDays(workingDays) {}

// Copy constructor
OfficeEmployee::OfficeEmployee(const OfficeEmployee &other)
    : Employee(other), workingDays(other.workingDays) {}

// Move constructor
OfficeEmployee::OfficeEmployee(OfficeEmployee &&other) noexcept
    : Employee(move(other)), workingDays(other.workingDays) {
    other.workingDays = 0;
}

// String-extracting constructor
OfficeEmployee::OfficeEmployee(const string &data) : Employee(data) {
    stringstream ss(data);
    ss >> workingDays;
}

void OfficeEmployee::input() {
    Employee::input();
    cout << "Enter Working Days: ";
    cin >> workingDays;
}

void OfficeEmployee::print() const {
    Employee::print();
    cout << "Working Days: " << workingDays << "\nMonthly Salary: " << computeSalary() << " VND" << endl;
}

int OfficeEmployee::computeSalary() const {
    return workingDays * payRatePerDay;
}
