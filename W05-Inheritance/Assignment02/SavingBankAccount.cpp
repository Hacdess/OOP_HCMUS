#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount()
    : BankAccount(), annualInterestRate(0), period(0), currentSavingMonths(0), initBalance(0) {}

void SavingBankAccount::input() {
    BankAccount::input();

    cout << "Enter annual interest rates (%): ";
    cin >> annualInterestRate;
    annualInterestRate /= 100;

    cout << "Enter period: ";
    cin >> period;

    cout << "Enter current saving months: ";
    cin >> currentSavingMonths;

    initBalance = balance;
    balance = balance * pow(1 + annualInterestRate, currentSavingMonths);
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

double SavingBankAccount::withdrawImmediately() {
    balance = 0;
    return initBalance * pow(1 + 0.02, currentSavingMonths);
}

double SavingBankAccount::getBalance() {
    return balance;
}

double SavingBankAccount::getInterest() {
    cout << balance << " - " << initBalance << endl;
    return balance - initBalance;
}
