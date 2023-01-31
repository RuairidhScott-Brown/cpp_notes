/*
REDEFINING BASE CLASS METHODS
    
    - When a member function is called with a derived class object, 
      the compiler first looks to see if that member exists in the derived class. 
      If not, it begins walking up the inheritance chain and checking whether the 
      member has been defined in any of the parent classes. It uses the first one it finds.


FRIEND FUNCTIONS
    - Friend function of the base class are not actually part of the base class
      therefore we cant use the scoppe resolution operator Base:: to access the
      friend function functionaliy.
    - to solve this issue we can just use static_cast. 
 


*/
#include <iostream>

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }

    friend std::ostream& operator<< (std::ostream& out, const Base& b)
	{
		out << "In Base\n";
		out << b.m_value << '\n';
		return out;
	}
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }

    int getValue() const  { return m_value; }

    void identify() const
    {
        Base::identify(); // call Base::identify() first
        std::cout << "I am a Derived\n"; // then identify ourselves
    }

    friend std::ostream& operator<< (std::ostream& out, const Derived& d)
	{
		out << "In Derived\n";
		// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<const Base&>(d);
		return out;
	}
};


int main()
{
    Base base { 5 };
    base.identify();

    Derived derived { 7 };
    derived.identify();

    return 0;
}