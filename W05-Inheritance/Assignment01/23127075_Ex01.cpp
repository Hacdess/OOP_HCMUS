#include "OfficeEmployee.h"
#include "Worker.h"

int main() {
    // Because the assignment only asked to create 3 classes so I didn't create the class Company

    int select;
    vector <OfficeEmployee> officers;
    vector <Worker> workers;

    while (true) {
        cout << "\n===== Company ABC =====\n";
        cout << "Select an option:\n";
        cout << "1. Add an office employee\n";
        cout << "2. Print office employees' information\n";
        cout << "3. Add an worker\n";
        cout << "4. Print office employees' information\n";
        cout << "5. Exit\n";
        cout << "Your selection: ";
        cin >> select;

        OfficeEmployee officer;
        Worker worker;

        switch (select) {
            case 1:
                cout << endl;
                officer.input();
                officers.push_back(officer);
                break;

            case 2:
                cout << "\n### Office employees:\n\n";
                for (OfficeEmployee officer : officers) {
                    officer.print();
                    cout << endl;
                }
                break;

            case 3:
                cout << endl;
                worker.input();
                workers.push_back(worker);
                break;

            case 4:
                cout << "\n### Workers:\n\n";
                for (Worker worker : workers) {
                    worker.print();
                    cout << endl;
                }
                break;

            case 5:
                cout << "\nClosing Program...\n";
                return 0;
                break;
            
            default:
                cout << "Invalid selection!\n";
                break;
        }
    }
}