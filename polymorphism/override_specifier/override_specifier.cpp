/*
OVERRIDE SPECIFIER
    - makes sure that your are overriding rather than redefining.
    - if the functions is not being overriden then the compiler
      will throw and error message
    - has no performance impact, should always use it.
    - if you tag with override, you do not need to also tag with
      virtual



*/

#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    virtual void say_hello() /*const*/ override {             // Notice I forgot the const this will show up during debugging
                                                    // solution is to add const
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    virtual ~Derived() {}
};


int main() {
    
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();
    
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();
    
   
    return 0;
}