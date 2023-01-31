#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {

    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
    
    private:
        static constexpr const char *def_name = "Unnamed Trust Account";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
        static constexpr double def_bonous = 50.0;
        static constexpr double def_withdraw_limit = 20.0;
        static constexpr int def_max_num_withdraws = 3;

    protected:
        double m_bonous;
        double m_withdraw_limit;
        int m_max_num_withdraws;
        int m_num_withdraws;

    public:
        Trust_Account(std::string name = def_name, double balance = def_balance, 
                      double int_rate = def_int_rate, double bonous = def_bonous,
                      double withdraw_limit = def_withdraw_limit, 
                      int m_max_num_owithdraws = def_max_num_withdraws); 
        bool deposit(double amount);
        bool withdraw(double amount);   
};


#endif