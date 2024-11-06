#include "OfficeEmployee.h"
#include "Worker.h"

int main() {
    OfficeEmployee officeEmployee;
    officeEmployee.input();
    cout << endl;
    cout << "Office Employee:\n";
    officeEmployee.print();

    cout << endl;

    Worker worker;
    worker.input();
    cout << endl;
    cout << "Office Employee:\n";
    worker.print();
}