#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string name;
    string socialID;
    double balance;

public:
    BankAccount();

    virtual void input();   
    virtual void print() const;
    virtual bool deposit(double money);
    virtual bool withdraw(double money);
    virtual double getBalance();
};

#endif