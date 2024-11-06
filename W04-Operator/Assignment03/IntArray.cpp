#include "IntArray.h"

IntArray::IntArray() {
    arr = nullptr;
    size = 0;
}

IntArray::~IntArray() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

void IntArray::Input() {
    do {
        cout << "Enter the size of the array (positive integer): ";
        cin >> size;
    } while (size < 0);
    
    arr = new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

IntArray& IntArray::operator=(const IntArray& other) {
    if (this != &other) {
        delete[] this->arr;
        this->size = other.size;
        this->arr = new int[size];
        for (int i = 0; i < this->size; ++i) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const IntArray& intArray) {
    for (int i = 0; i < intArray.size; ++i) {
        os << intArray.arr[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, IntArray& intArray) {
    cout << "Enter " << intArray.size << " elementes: ";
    for (int i = 0; i < intArray.size; ++i) {
        is >> intArray.arr[i];
    }
    return is;
}

int& IntArray::operator[](int index) {
    return arr[index];
}

IntArray::operator int() const {
    return size;
}