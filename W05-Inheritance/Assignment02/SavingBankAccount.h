#ifndef _SAVING_BANK_ACCOUNT_H_
#define _SAVING_BANK_ACCOUNT_H_

#include "BankAccount.h"
#include <cmath>

class SavingBankAccount : public BankAccount {
private:
    double annualInterestRate;
    int period;
    int currentSavingMonths;
    double initBalance;

public:
    SavingBankAccount();
    
    void input() override;
    void print() const override;
    void createNew(const SavingBankAccount &oldAccount, double money);
    bool deposit(double money) override;
    bool withdraw(double money) override;
    double withdrawImmediately();
    double getBalance() override;
    double getInterest();
};

#endif