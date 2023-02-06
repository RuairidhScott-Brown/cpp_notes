/*
UNCAUGHT EXCEPTIONS AND CATCH ALL

UNCAUGHT
    - std::terminate() is called, and the application is terminated.
    - The call stack may or may not be unwound if an exception is unhandled.
      This is so that information can be stored maybe for debugging

CATCH ALL
    - you use an ellipse.
    - The catch-all handler must be placed last in the catch block chain. 
*/

#include <iostream>

int main()
{
	try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
}