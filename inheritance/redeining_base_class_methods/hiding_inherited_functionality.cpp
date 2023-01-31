/*
Hiding inherited functionality
    - C++ gives us the ability to change an inherited member’s access 
      specifier in the derived class.

    - You can only change the access specifiers of base members the 
      derived class would normally be able to access.

    - n a derived class, it is possible to hide functionality that 
      exists in the base class, so that it can not be accessed through 
      the derived class. 

    - mark member functions as deleted in the derived class, which 
      ensures they can’t be called at all through a derived object:
*/

#include <iostream>

class Base
{
private:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

protected:
    void printValue() const { std::cout << m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};

class Base2
{
public:
	int m_value {};

    void print_stuff() {std::cout << "Testing\n";}
};

class Derived2 : public Base2
{
private:
	using Base2::m_value;

public:
	Derived2(int value)
	// We can't initialize m_value, since it's a Base member (Base must initialize it)
	{
		// But we can assign it a value
		m_value = value;
	}
    void print_stuff() = delete; //this is used to completely reomve the functionality of
                                 //the base class
};

int main()
{
	Derived2 derived { 7 };

	// The following won't work because m_value has been redefined as private
	std::cout << derived.m_value;

	return 0;
}