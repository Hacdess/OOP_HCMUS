#ifndef _GATEKEEPER_H_
#define _GATEKEEPER_H_

#include <iostream>
using namespace std;

class Gatekeeper
{
public:
    virtual void input() = 0;
};

class Merchant : public Gatekeeper
{
private:
    int unitPrice;
    int quantity;

public:
    Merchant();

    void input() override;
    int getCost();
};

class Sage : public Gatekeeper
{
private:
    int intelligenceLevel;

public:
    Sage();

    void input() override;
    int getIntelligenceLevel();
};

class Warrior : public Gatekeeper
{
private:
    int strengthLevel;

public:
    Warrior();

    void input() override;
    int getStrengthLevel();
};

#endif