#include "Castle.h"

Castle::~Castle()
{
    int n = gates.size();
    for (int i = 0; i < n; ++i)
        delete gates[i];
    gates.clear();
}

void Castle::input()
{
    cout << "=== Castle ===\n";
    int n, selection;
    do
    {
        cout << "Input the number of layers of gates (positive integer): ";
        cin >> n;
    } while (n <= 0);
    cout << endl;

    Gate* gate = nullptr;
    for (int i = 0; i < n; ++i)
    {
        do
        {
            cout << "Choose the gate " << i + 1 << "'s type:\n";
            cout << "1. Business Gate\n";
            cout << "2. Academic Gate\n";
            cout << "3. Power Gate\n";
            cout << "Your selection: ";
            cin >> selection;

            if (selection == 1)
            {
                gate = new BusinessGate;
                break;
            }

            else if (selection == 2)
            {
                gate = new AcademicGate;
                break;
            }

            else if (selection == 3)
            {
                gate = new PowerGate;
                break;
            }

            else
                cout << "Invalid selection!\n";
        } while (true);
        
        gate->input();
        gates.push_back(gate);
        cout << endl;
    }
}

vector<Gate *> Castle::getGates()
{
    return gates;
}
