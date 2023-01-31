#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate, 
                             double bonous, double withdraw_limit, int max_num_withdraws)
    : Savings_Account{name, balance, int_rate}, m_bonous{bonous}, 
      m_withdraw_limit{withdraw_limit}, m_max_num_withdraws{max_num_withdraws}, m_num_withdraws{1} {}


bool Trust_Account::deposit(double amount) {
    if (amount >= 5000.0) {amount+=m_bonous;}
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (m_num_withdraws > 3) {
        std::cout << "Sorry you've reached your maxium number of withdraws\n";
        return false;
    } else if (amount > balance*(m_withdraw_limit/100)) {
        std::cout << "Sorry that is too much money to take in one go\n";
        return false;
    } else {
        m_num_withdraws+=1;
        return Savings_Account::withdraw(amount);
    }
}


std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}