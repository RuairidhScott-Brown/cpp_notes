/*
POLYMORPHISM
    - compile time/ static binding poly ==> overloaded functions and operators
    - not the default in c++

RUNTIME POLYMORPHISM
    - being able to assign different meaning to the same function at run time.
    - Function over-riding

e.g a non polymorphic example of static binding not working how we want it to.
Note: that each class has its own method for withdraw.

Account a;
a.withdraw()

Trust d;
d.withdraw()

Account *p = new Trust();
p->withdraw(); //this will use Account::withdraw() as it is the type that is known at
               //compile time.

orrrr

void display_account(const Account &acc) {
    acc.display(); // will always use Account::display because of the Account.
}
*/

#include <iostream>
#include <memory>

class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello()  const {   
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj) {
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main() {
    Base b;
    b.say_hello();
    
    Derived d;
    d.say_hello();
    
    greetings(b);
    greetings(d);
    
    Derived *ptr = new Derived();
    ptr->say_hello();
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();
    
    
    
   delete ptr;
    
    return 0;
}