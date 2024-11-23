#ifndef _GATE_H_
#define _GATE_H_

#include "Gatekeeper.h"

class Gate
{
public:
    virtual void input() = 0;
    virtual void output() = 0;

    virtual bool canPass(int &money, const int &IQ, int &strength) = 0;
};

class BusinessGate : public Gate
{
private:
    Merchant merchant;

public:
    void input() override;
    void output() override;

    virtual bool canPass(int &money, const int &IQ, int &strength);
};

class AcademicGate : public Gate
{
private:
    Sage sage;

public:
    void input() override;
    void output() override;

    virtual bool canPass(int &money, const int &IQ, int &strength);
};

class PowerGate : public Gate
{
private:
    Warrior warrior;

public:
    void input() override;
    void output() override;

    virtual bool canPass(int &money, const int &IQ, int &strength);
};

#endif