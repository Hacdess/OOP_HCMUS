#include "Prince.h"



Prince::Prince()
{
    money = IQLevel = strengthLevel = 0;
}

void Prince::input()
{
    cout << "=== Prince ===\n";
    
    do
    {
        cout << "Input money (non-negative integer): ";
        cin >> money;
    } while (money < 0);
    
    do
    {
        cout << "Input IQ level (non-negative integer): ";
        cin >> IQLevel;
    } while (IQLevel < 0); 

    do
    {
        cout << "Input strength level (non-negative integer): ";
        cin >> strengthLevel;
    } while (strengthLevel < 0); 
}

void Prince::output() const
{
    cout << "=== Prince ===\n";
    cout << "Money: " << money << endl;
    cout << "IQ: " << IQLevel << endl;
    cout << "Strength: " << strengthLevel << endl;
}

bool Prince::canRescue(int &gateCount, Castle castle)
{
    gateCount = 0;

    vector<Gate*> gates = castle.getGates();
    
    int numbGates = gates.size();

    if (numbGates < 1)
    {
        cout << "No gate!\n";
        return true;
    }

    for (gateCount; gateCount < numbGates; ++gateCount)
    {
        if (gates[gateCount]->canPass(money, IQLevel, strengthLevel))
            cout << "Prince passed gate " << gateCount + 1 << endl;

        else
        {
            cout << "Princed failed to pass gate " << gateCount + 1 << endl;
            return false;
        }
    }

    return true;
}
