#include "Worker.h"

// Default constructor
Worker::Worker() : Employee(), producedItems(0) {}

// Parameterized constructor
Worker::Worker(const string& id, const string &fullName, const string &hireDate, const string &address, const int& producedItems)
    : Employee(id, fullName, hireDate, address), producedItems(producedItems) {}

// Copy constructor
Worker::Worker(const Worker &other)
    : Employee(other), producedItems(other.producedItems) {}

// Move constructor
Worker::Worker(Worker &&other) noexcept
    : Employee(move(other)), producedItems(other.producedItems) {
    other.producedItems = 0;
}

// String-extracting constructor
Worker::Worker(const string &data) : Employee(data) {
    istringstream iss(data);
    iss >> producedItems;
}

void Worker::input() {
    Employee::input();
    do {
        cout << "Enter number of produced items (non-negative integer): ";
        cin >> producedItems;
    } while (producedItems < 0);
}

void Worker::print() const {
    Employee::print();
    cout << "Type: Worker\n";
    cout << "Number of produced items: " << producedItems << endl;
}

long Worker::computeSalary() const {
    return producedItems * payRatePerItem;
}
