#include "Prince.h"
#include "Castle.h"

int main()
{
    Prince prince;
    prince.input();
    cout << endl;

    Castle castle;
    castle.input();
    cout << endl;

    int gateCount;

    if (prince.canRescue(gateCount, castle.getGates()))
    {
        cout << "Princed rescued the princess successfully!\n";
        prince.output();
    }
    else
    {
        cout << "Prince failed to rescue the princess! Remaining gates:\n";
        int numbGates = castle.getGates().size();
        for (gateCount; gateCount < numbGates; ++gateCount)
        {
            cout << "Gate " << gateCount + 1 << ": ";
            castle.getGates()[gateCount]->output(); 
        }
    }
}