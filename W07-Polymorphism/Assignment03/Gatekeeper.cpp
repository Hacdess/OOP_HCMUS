#include "Gatekeeper.h"

Merchant::Merchant()
{
    unitPrice = quantity = 0;
}

void Merchant::input()
{
    cout << "=== Merchant ===\n";

    do
    {
        cout << "Input unit price (non-negative integer): ";
        cin >> unitPrice;
    } while (unitPrice < 0);
    
    do
    {
        cout << "Input quantity (non-negative integer): ";
        cin >> quantity;
    } while (quantity < 0);    
}

int Merchant::getCost()
{
    return unitPrice * quantity;
}

Sage::Sage()
{
    intelligenceLevel = 0;
}

void Sage::input()
{
    cout << "=== Sage ===\n";

    do
    {
        cout << "Input intelligence level (non-negative integer): ";
        cin >> intelligenceLevel;
    } while (intelligenceLevel < 0); 
}

int Sage::getIntelligenceLevel()
{
    return intelligenceLevel;
}

Warrior::Warrior()
{
    strengthLevel = 0;
}

void Warrior::input()
{
    cout << "=== Warrior ===\n";

    do
    {
        cout << "Input strength level (non-negative integer): ";
        cin >> strengthLevel;
    } while (strengthLevel < 0); 
}

int Warrior::getStrengthLevel()
{
    return strengthLevel;
}
