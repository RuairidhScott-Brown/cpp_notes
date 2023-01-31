#include <iostream>
#include "saving_account.h"

SavingAccount::SavingAccount() : interest_rate{3.0} {}
SavingAccount::~SavingAccount() {}

void SavingAccount::deposit(double amount) {
    std::cout << "Saving account deposit called with: " << amount << '\n';
}

void SavingAccount::withdraw(double amount) {
    std::cout << "Saving account withdraw called with: " << amount << '\n';
}