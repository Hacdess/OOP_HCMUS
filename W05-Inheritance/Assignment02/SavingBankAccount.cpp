#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount()
    : BankAccount(), annualInterestRate(0), period(0), currentSavingMonths(0) {}

void SavingBankAccount::input() {
    BankAccount::input();

    cout << "Enter annual interest rates (%): ";
    cin >> annualInterestRate;
    annualInterestRate /= 100;

    cout << "Enter period: ";
    cin >> period;

    cout << "Enter current saving months: ";
    cin >> currentSavingMonths;
}

void SavingBankAccount::print() const {
    BankAccount::print();

    cout << "Annual interest rates: " << annualInterestRate << endl;
    cout << "Period: " << period << endl;
    cout << "Current saving months: " << currentSavingMonths << endl;
}

void SavingBankAccount::createNew(const SavingBankAccount &oldAccount, double money) {
    this->accountNumber = oldAccount.accountNumber;
    this->name = oldAccount.name;
    this->socialID = oldAccount.socialID;
    this->balance = money;
    currentSavingMonths = 0;

    cout << "Enter annual interest rates (%): ";
    cin >> annualInterestRate;
    annualInterestRate /= 100;

    cout << "Enter period: ";
    cin >> period;
}

bool SavingBankAccount::deposit(double money) {
    if (currentSavingMonths < period) {
        cout << "Can't deposit because the number of saving months is less than period!\n";
        return false;
    }

    cout << "Deposited successfully\n";
    return BankAccount::deposit(money);
}

bool SavingBankAccount::withdraw(double money) {
    if (currentSavingMonths < period) {
        cout << "Can't withdraw because the number of saving months is less than period!\n";
        return false;
    }

    cout << "Withdrew successfully\n";
    return BankAccount::withdraw(money);
}

bool SavingBankAccount::withdrawImmediately(double money) {
    annualInterestRate = 0.02;
    period = 0;

    return BankAccount::withdraw(money);
}

double SavingBankAccount::getBalance() {
    return balance * pow(1 + annualInterestRate / 12, currentSavingMonths);
}
