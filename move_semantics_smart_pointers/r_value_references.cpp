/*
R-VALUE REFERENCES


L-VALUE
- L value references can only be initialised with a modifiable l-value.
- L value references to const objects can be initialised with modifiable 
  and non-modifiable l-values and r-values alike. However, those values can’t
  be modified.
- L-value references to const objects are particularly useful because they allow
  us to pass any type of argument (l-value or r-value) into a function without
  making a copy of the argument.

R-VALUE
c++11 and onwards only
- An r-value reference is a reference that is designed to be initialized with an r-value (only)
- you can initialise an r-value such that it is modifiable or not.
- an r-value reference is created using a double ampersand:
- don't return an r-value reference. It will probably hang.

- First, r-value references extend the lifespan of the object they are
  initialized with to the lifespan of the r-value reference (l-value references to const objects can do this too)
- Second, non-const r-value references allow you to modify the r-value!

*/

int x{ 5 };
int &lref{ x }; // l-value reference initialized with l-value x
int &&rref{ 5 }; // r-value reference initialized with r-value 5

#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};


void fun(const int &lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const\n";
}

void fun(int &&rref) // r-value arguments will select this function
{
	std::cout << "r-value reference\n";
}


int main()
{
    /*
    As an anonymous object, Fraction(3, 5) would normally go out of scope at the end of
    the expression in which it is defined. However, since we’re initializing an r-value 
    reference with it, its duration is extended until the end of the block. We can then 
    use that r-value reference to print the Fraction’s value.
    */
	auto &&rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction

	// f1 of operator<< binds to the temporary, no copies are created.
	std::cout << rref << '\n';

    int &&rref{ 5 }; // because we're initializing an r-value reference with a literal, a temporary with value 5 is created here
                     // so that the reference is referencing a temporary object, not a literal value.
    rref = 10;
    std::cout << rref << '\n';

    int x{ 5 };
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function

    int &&ref{ 5 };
    fun(ref); //This calls the l-value version as it is passed in an l-value
              //all named variables are l-values

	return 0;
} // rref (and the temporary Fraction) goes out of scope here