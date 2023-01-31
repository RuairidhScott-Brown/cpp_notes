#include "src/account.h"
#include "src/saving_account.h"
#include <iostream>

using namespace std;

int main() {
    cout << "++++++++++Account+++++++++++\n";
    Account acc{};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    Account* p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;
    cout << '\n';

    cout << "++++++++++SavingAccount+++++++++++\n";
    SavingAccount sacc{};
    sacc.deposit(2000.0);
    sacc.withdraw(500.0);

    SavingAccount* p_sacc {nullptr};
    p_sacc = new SavingAccount();
    p_sacc->deposit(1000.0);
    p_sacc->withdraw(500.0);
    delete p_sacc;

    cout << '\n';

    return 0; 
}