#include "Company.h"

int main() {
    Company company;

    cout << "===== Input a list of employees =====\n\n";
    company.inputEmployees();
    cout << endl;

    cout << "===== Print out the info of all employees in the company =====\n\n";
    company.printAllEmployees();
    cout << endl;

    cout << "===== Print out the total salary the company has to pay in a month =====\n\n";
    cout << "The total salary the company has to pay in a month: " << company.computeTotalSalary() << " VND\n\n";

    cout << "===== Print out all employees whose salaries are the biggest value in the company =====\n\n";
    company.printHighestSalaryEmployees();
}