/*
DYNAMIC POLYMORPHISM
    - must have inheritance
    - base class pointer or base class reference
    - virtual functions: A virtual function is a special type of function 
      that, when called, resolves to the most-derived version of the 
      function that exists between the base and derived class. 
    
    - redefined functions are bound statically
    - overridden functions are bound dynamically
    - virtual functions are overridden


VIRTUAL FUNCTION
    - virtual function is a special type of function that, 
      when called, resolves to the most-derived version of 
      the function that exists between the base and derived class

    - considered a match if it has the same signature (name, 
      parameter types, and whether it is const) and return type. 


example

class Account {
    public:
        virtual void withdraw(double amount);
};

VIRTUAL DESTRUCTORS
    - Because derived virtual methods are created dynamically we need to destroy them.
      Otherwise it becomes undefined behaviour.
    - Always provide public virtuabl destructors
 

VIRTUAL FUNCTIONS FROM CONSTRUCTORS
    - Do not call virtual functions from constructors/destructors
    When you initialise an object, the base class constructor
    is called first. Therefore the virtual functions will be
    called before any of the derived methods have been created.

DOWNSIDE OF VIRTUAL FUNCTIONS
    - they are inefficient and slower.

*/


#include <iostream>
#include <vector>

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
    virtual void withdraw(double amount) { //you dont have to add the virtual keyword here but its best practice
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) { //you dont have to add the virtual keyword here but its best practice
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  { 
public:
    virtual void withdraw(double amount) { //you dont have to add the virtual keyword here but its best practice
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    
    std::cout << "\n === Array ==== " << std::endl;
    Account *array [] = {p1,p2,p3,p4};
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);
        
    std::cout << "\n === Array ==== " << std::endl;
    array[0] = p4;
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    std::vector<Account *> accounts {p1,p2,p3,p4};
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);
        
    std::cout << "\n === Vector ==== " << std::endl;
    accounts.push_back(p4);
    accounts.push_back(p4);
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}