/*
TO IGNORE VIRTUALISATION
    - just specify the exact function you want to call

*/


class Base
{
public:
    virtual ~Base() = default;
    virtual const char* getName() const { return "Base"; }
};

class Derived: public Base
{
public:
    virtual const char* getName() const { return "Derived"; }
};

#include <iostream>
int main()
{
    Derived derived;
    const Base &base { derived };
    // Calls Base::GetName() instead of the virtualized Derived::GetName()
    std::cout << base.Base::getName() << '\n';

    return 0;
}