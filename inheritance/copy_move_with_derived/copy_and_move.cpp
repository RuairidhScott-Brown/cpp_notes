/*
COPY AND MOVE CONSTRUCTORS
    - not automatically inherited from the base class
    - the compiler provides some basic ones

    - the complier can slice a derived object to only account for the
      base part of the object.
    
    - have to think about this for the move/copy/operator overloading


*/
#include <iostream>
using namespace std;

class Base {

    private:
        int value;

    public:
        Base(const Base &other) : value{other.value} {
            cout << "Base copy constructor" << endl;
        }

        Base &operator=(const Base &rhs) {
            if (this != &rhs) {
                value = rhs.value;
            }
            return *this;
        }
};

class Derived : public Base {

    private:
        int double_value;

    public:
        Derived(const Derived &other) : Base(other), double_value{other.double_value} {
            cout << "Derived copy constructor " << endl;
        }

        Derived &operator=(const Derived &rhs) {
            if (this != &rhs) {
                Base::operator=(rhs); //this takes care of the base part
                double_value = rhs.double_value; //this takes care of the derived part
            }
            return *this;
        }
};