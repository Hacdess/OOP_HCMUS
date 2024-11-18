#include "OfficeEmployee.h"

// Default constructor
OfficeEmployee::OfficeEmployee() : Employee(), workingDays(0) {}

// Parameterized constructor
OfficeEmployee::OfficeEmployee(const string& id, const string &fullName, const string &hireDate, const string &address, int workingDays)
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
    do {
        cout << "Enter Working Days (0 <= working days <= 31): ";
        cin >> workingDays;
    } while (workingDays < 0 || workingDays > 31);
    

}

void OfficeEmployee::print() const {
    Employee::print();
    cout << "Type: Office employee\n";
    cout << "Working Days: " << workingDays << endl;
}

long OfficeEmployee::computeSalary() const {
    return workingDays * payRatePerDay;
}
