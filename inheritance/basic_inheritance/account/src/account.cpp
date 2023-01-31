#include <iostream>
#include "account.h"

Account::Account() : balance{0.0}, name{"An Account"} {}
Account::~Account() {}

void Account::deposit(double amount) {
    std::cout << "Account deposit called with: " << amount << '\n';
} 

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with: " << amount << '\n';
} 