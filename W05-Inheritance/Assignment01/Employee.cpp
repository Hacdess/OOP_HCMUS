#include "Employee.h"

// Default constructor
Employee::Employee() {
    id = 0;
    fullName = hireDate = address = "";
}

// Parameterized constructor
Employee::Employee(int id, const string &fullName, const string &hireDate, const string &address) {
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
    this->id = other.id;
    other.id = 0;
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
    do {
        cout << "Enter ID (positive integer): ";
        cin >> id;
    } while (id < 1);

    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Hire Date (string with format \"dd/mm/yyyy\"): ";
    getline(cin, hireDate);
    cout << "Enter Address: ";
    getline(cin, address);
}

void Employee::print() const {
    cout << "ID: " << id << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Hire Date: " << hireDate << endl;
    cout << "Address: " << address << endl;
}
