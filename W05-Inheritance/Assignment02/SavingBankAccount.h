#ifndef _SAVING_BANK_ACCOUNT_H_
#define _SAVING_BANK_ACCOUNT_H_

#include "BankAccount.h"
#include <cmath>

class SavingBankAccount : public BankAccount {
private:
    float annualInterestRate;
    int period;
    int currentSavingMonths;

public:
    SavingBankAccount();

    void input() override;
    void print() const override;
    bool deposit(double money) override;
    bool withdraw(double money) override;
    bool withdrawImmediately(double money);
    double getBalance() override;
    float getInterest();
};

#endif