#include "Employee.h"

// Default constructor
Employee::Employee() {
    id = fullName = hireDate = address = "";
}

// Parameterized constructor
Employee::Employee(const string& id, const string &fullName, const string &hireDate, const string &address) {
    this->id = id;
    this->fullName = fullName;
    this->hireDate = hireDate;
    this->address = address;
}

// Copy constructor
Employee::Employee(const Employee &other) {
    this->id = other.id;
    this->fullName = other.fullName;
    this->hireDate = other.hireDate;
    this->address = other.address;
}

// Move constructor
Employee::Employee(Employee &&other) noexcept {
    this->id = move(other.id);
    this->fullName = move(other.fullName);
    this->hireDate = move(other.hireDate);
    this->address = move(other.address);
}

// String-extracting constructor
Employee::Employee(const string &data) {
    stringstream ss(data);
    ss >> id >> fullName >> hireDate >> address;
}

void Employee::input() {
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Hire Date (string with format \"dd/mm/yyyy\"): ";
    cin >> hireDate;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
}

void Employee::print() const {
    cout << "ID: " << id << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Hire Date: " << hireDate << endl;
    cout << "Address: " << address << endl;
}
