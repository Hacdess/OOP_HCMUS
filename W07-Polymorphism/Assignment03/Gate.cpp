#include "Gate.h"

void BusinessGate::input()
{
    merchant.input();
}

void BusinessGate::output()
{
    cout << "Merchant's products's cost: " << merchant.getCost() << endl;
}

bool BusinessGate::canPass(int &money, const int &IQ, int &strength)
{
    if (money >= merchant.getCost())
    {
        money -= merchant.getCost();
        return true;
    }
    return false;
}

void AcademicGate::input()
{
    sage.input();
}

void AcademicGate::output()
{
    cout << "Sage's intelligence level: " << sage.getIntelligenceLevel() << endl;
}

bool AcademicGate::canPass(int &money, const int &IQ, int &strength)
{
    return IQ > sage.getIntelligenceLevel();
}

void PowerGate::input()
{
    warrior.input();
}

void PowerGate::output()
{
    cout << "Warrior's strength level: " << warrior.getStrengthLevel() << endl;
}

bool PowerGate::canPass(int &money, const int &IQ, int &strength)
{
    if (strength > warrior.getStrengthLevel())
    {
        strength -= warrior.getStrengthLevel();
        return true;
    }
    return false;
}
