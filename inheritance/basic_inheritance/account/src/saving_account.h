#ifndef _SAVING_ACCOUNT_
#define _SAVING_ACCOUNT_
#include "account.h"

class SavingAccount: public Account {
    public:
        double interest_rate;
        SavingAccount();
        ~SavingAccount();

        void deposit(double amount);
        void withdraw(double amount);
};

#endif