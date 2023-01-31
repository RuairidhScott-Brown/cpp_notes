/*




BASE CLASS REFERENCES/ POINTERS

    - because derived classes are also base classes. We can assign
      derived objects are type base. However this means that the
      object will only have acess to base class methods.

    - Why would we ever do this?? set the type of a derived object
      as base type. Well it means that could have functions that
      accept the base class type and therefore all of the derived
      types too

    i.e. we don't have to do this

void report(const Cat& cat)
{
    std::cout << cat.getName() << " says " << cat.speak() << '\n';
}

void report(const Dog& dog)
{
    std::cout << dog.getName() << " says " << dog.speak() << '\n';
}

We can do this!!!

void report(const Animal& rAnimal)
{
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}


Account a;
Account &ref = a;
ref.withdraw(1.0); //Account::withdraw // the binding is dynamic


Trust t;
Account &ref1 = t;
ref1.withdraw(1.0) //Trust:;withdraw  // the binding is dynamic



void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}

Account a;
do_withdraw(a, 100); //Account::withdraw

Trust t;
do_withdraw(t, 1000); //Trust::withdraw

*/


#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}

int main() {

    Account a;
    Account &ref = a;
    ref.withdraw(1000);		    // In Account::withdraw

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);        // In Trust::withdraw

   Account a1;
   Savings a2;
   Checking a3;
   Trust a4;
   
   do_withdraw(a1, 1000);       // In Account::withdraw
   do_withdraw(a2, 2000);       // In Savings::withdraw
   do_withdraw(a3, 3000);       // In Checking::withdraw
   do_withdraw(a4,  4000);      // In Trust::withdraw


    return 0;
}