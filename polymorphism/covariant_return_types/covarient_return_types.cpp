/*
COVARIANT RETURN TYPES

    - essentailly it means that virtual derived
      functions can return a different type than
      the original functions. This is only true if
      the return type of the functions is a pointer
      to a class


RETURN TYPES

  -  covariant return types: C++ can’t dynamically select types, 
     so you’ll always get the type that matches the actual version of 
     the function being called.
  -  This is why the b->getThis()->printType() will print base


*/
#include <iostream>
#include <string_view>

class Base
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};

int main()
{
	Derived d{};
	Base* b{ &d };
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType

	return 0;
}