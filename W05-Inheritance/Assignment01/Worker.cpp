#include "Worker.h"

// Default constructor
Worker::Worker() : Employee(), itemsProduced(0) {}

// Parameterized constructor
Worker::Worker(int id, const string &fullName, const string &hireDate, const string &address, int itemsProduced)
    : Employee(id, fullName, hireDate, address), itemsProduced(itemsProduced) {}

// Copy constructor
Worker::Worker(const Worker &other)
    : Employee(other), itemsProduced(other.itemsProduced) {}

// Move constructor
Worker::Worker(Worker &&other) noexcept
    : Employee(move(other)), itemsProduced(other.itemsProduced) {
    other.itemsProduced = 0;
}

// String-extracting constructor
Worker::Worker(const string &data) : Employee(data) {
    istringstream iss(data);
    iss >> itemsProduced;
}

void Worker::input() {
    Employee::input();
    cout << "Enter Number of Items Produced: ";
    cin >> itemsProduced;
}

void Worker::print() const {
    Employee::print();
    cout << "Items Produced: " << itemsProduced << "\nMonthly Salary: " << computeSalary() << " VND" << endl;
}

int Worker::computeSalary() const {
    return itemsProduced * payRatePerItem;
}
