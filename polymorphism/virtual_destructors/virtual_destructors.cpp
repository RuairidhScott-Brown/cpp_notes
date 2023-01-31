/*
WHY DO WE NEED VIRTUAL DESTRUCOTRS

ecause base is a Base pointer, when base is 
deleted, the program looks to see if the Base 
destructor is virtual. It’s not, so it assumes 
it only needs to call the Base destructor.

To solve this we should make the base destructor virtual

RULE
Whenever you are dealing with inheritance, you should 
make any explicit destructors virtual.


RULE
A base class destructor should be either 
public and virtual, or protected and nonvirtual.

A class with a protected destructor can’t be deleted via a pointer
preventing the accidental deleting of a derived class through a 
base pointer when the base class has a non-virtual destructor. 
Unfortunately, this also means the base class can’t be deleted 
through a base class pointer, which essentially means the class 
can’t be dynamically allocated or deleted except by a derived class. 
This also precludes using smart pointers (such as std::unique_ptr 
and std::shared_ptr) for such classes, which limits the usefulness 
of that rule


RULE ALTERNATIVE
If you intend your class to be inherited from, make sure 
your destructor is virtual.

If you do not intend your class to be inherited from, 
mark your class as final. This will prevent other classes from inheriting from it in the first place, without imposing any other use restrictions on the class itself.


*/


#include <iostream>
class Base
{
public:
    ~Base() // note: not virtual
    {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived: public Base
{
private:
    int* m_array;

public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }

    ~Derived() // note: not virtual (your compiler may warn you about this)
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived *derived { new Derived(5) };
    Base *base { derived };

    delete base;

    return 0;
}