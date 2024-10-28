#include "Student.h"

Student::Student() {
    cout << "Student::Default constructor" << endl;

    id = 0;
    fullname = address = nullptr;
    gpa = 0;
}

string Student::formatGPA() {
    int rounded = round(gpa * 100);
    return to_string(rounded / 100) + '.' + to_string(rounded % 100);
}

Student::Student(int id, string fullname, string address, double gpa) {
    cout << "Student::Parameterized constructor" << endl;

    this->id = id;
    this->gpa = gpa;

    if (fullname == "")
        this->fullname = nullptr;
    else {
        this->fullname = new char[strlen(fullname.c_str()) + 1];
        strcpy(this->fullname, fullname.c_str());
    }

    if (address == "")
        this->address = nullptr;
    else {
        this->address = new char[strlen(address.c_str()) + 1];
        strcpy(this->address, address.c_str());
    }
}

Student::Student(const Student &other) {
    cout << "Student::Copy constructor" << endl;

    this->id = other.id;
    this->gpa = other.gpa;
    
    if (other.fullname == nullptr)
        this->fullname = nullptr;
    else {
        this->fullname = new char[strlen(other.fullname) + 1];
        strcpy(this->fullname, other.fullname);
    }

    if (other.address == nullptr)
        this->address = nullptr;
    else {
        this->address = new char[strlen(other.address) + 1];
        strcpy(this->address, other.address);
    }
}

Student::Student(Student &&other) noexcept {
    cout << "Student::Move constructor" << endl;

    this->id = other.id;
    other.id = 0;

    this->gpa = other.gpa;
    other.gpa = 0;

    if (other.fullname == nullptr)
        this->fullname = nullptr;
    else {
        this->fullname = new char[strlen(other.fullname) + 1];
        strcpy(this->fullname, other.fullname);
    }

    if (other.address == nullptr)
        this->address = nullptr;
    else {
        this->address = new char[strlen(other.address) + 1];
        strcpy(this->address, other.address);
    }

    other.fullname = other.address = nullptr;
}

Student::Student(string s)  {
    cout << "Student::String-extracting constructor" << endl;

    string token = "";
    int i = 0, len = s.length();
    
    while (i < len && s[i] != ',')
        token += s[i++];
    int lenToken = token.length();
    if (lenToken < 1)
        id = 0;
    else
        id = stoi(token);
    i++;
    token = "";

    while (i < len && s[i] != ',')
        token += s[i++];
    lenToken = token.length();
    if (lenToken < 1)
        this->fullname = nullptr;
    else {
        this->fullname = new char[lenToken + 1];
        strcpy(this->fullname, token.c_str());
    }
    i++;
    token = "";
    
    while (i < len && s[i] != ',')
        token += s[i++];
    lenToken = token.length();
    if (lenToken < 1)
        this->address = nullptr;
    else {
        this->address = new char[lenToken + 1];
        strcpy(this->address, token.c_str());
    }
    i++;
    token = "";

    while (i < len && s[i] != ',')
        token += s[i++];
    lenToken = token.length();
    if (lenToken < 1)
        gpa = 0;
    else
        gpa = stod(token);
}

Student::~Student() {
    cout << "Student::Destructor" << endl;

    id = 0;
    delete fullname;
    delete address;
    fullname = address = nullptr;
    gpa = 0;

}

string Student::toString() {
    return (fullname) ? 
        ("ID: " + to_string(id) + 
        "\nFullname: " + fullname +
        "\nAddress: " + ((address == nullptr) ? "No address" : address) +
        "\nGPA: " + formatGPA()) : 
        "No data";
}

Student *Student::clone() {
    return new Student(*this);
}
