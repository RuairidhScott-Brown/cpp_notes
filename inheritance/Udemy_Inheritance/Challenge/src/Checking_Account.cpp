#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double trans_fee) 
    : Account {name, balance}, m_transaction_fee{trans_fee} {}

bool Checking_Account::withdraw(double amount) {
    if (balance < 1.5) {
        std::cout << "You're poor and don't have enough money to withrdaw\n";
        return false;
    } else {
        balance-=m_transaction_fee;
        return Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.m_transaction_fee << "]";
    return os;
}