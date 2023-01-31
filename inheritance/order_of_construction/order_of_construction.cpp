/*
ORDER OF CONSTRUCTION
    - do not thing that the Base member get copied into the Derived class
    - think go it as a two part class with each class making up a part

    - when initialising a non-derived class such as Base c++ allocates
      memory for the base and calls the base's default constructor to handle
      the initialisation.

    - When constucting a derived class c++ does it in phases. The top of the
      inheritance tree is constructed first then each child class is constructed
      in order.

      e.g.
      for the derived object the Base constructor is called and finishes before
      the derived constructor is called and finishes.

    - derived class does not inherit
        - base class constructors
        - base class destructors
        - base class overloaded assignment operators
        - base class friend functions

    - however the deprived class constructors, destructors and overloaded assignment
      operators can invoke the base class versions

    - c++11 allows explicit inheritance of base non special constructors with Base::Base;
      anywhere in the derived class declaration
    
    MUCH BETTER TO DEFINE CONSTRUCTORS YOURSELF




*/

#include <iostream>

class Base {
    public:
        int m_id {};

        Base(int id = 0)
            : m_id {id} {
                std::cout << "Base\n";
            }

            int getId() const {return m_id;}      
};

class Derived : public Base {
    public:
        double m_cost {};

        Derived(double cost = 0.0)
            : m_cost(cost) {
                std::cout << "Derived\n";
            }

        double getCost() const {return m_cost;}
};

int  main() {
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;

    return 0;
}