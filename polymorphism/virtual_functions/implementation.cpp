/*
BASICS OF EXECUTION
When a program is compiled, the compiler converts each statement 
in your C++ program into one or more lines of machine language. 
Each line of machine language is given its own unique sequential 
address. This is no different for functions -- when a function is 
encountered, it is converted into machine language and given the 
next available address

BINDING
Binding refers to the process that is used to convert identifiers 
(such as variable and function names) into addresses.

EARLY BINDING
Early binding (also called static binding) means the compiler 
(or linker) is able to directly associate the identifier name 
(such as a function or variable name) with a machine address.
Then the program can jump to the memory address.

LATE BINDING
when it is not possible to know which function will be called 
until runtime (when the program is run). This is known as late 
binding (or dynamic binding).

Inefficient

FUNCTIONS POINTERS
An example of a process that uses late binding.


VIRTUAL TABLE
virtual table is a lookup table of functions used to resolve 
function calls in a dynamic/late binding manner.

First, every class that uses virtual functions (or is derived 
from a class that uses virtual functions) is given its own virtual 
table. This table is simply a static array that the compiler 
sets up at compile time. A virtual table contains one entry for 
each virtual function that can be called by objects of the class. 
Each entry in this table is simply a function pointer that points 
to the most-derived function accessible by that class.

__VPTR
#the compiler also adds a hidden pointer that is a member of the 
base class, which we will call *__vptr. *__vptr is set 
(automatically) when a class instance is created so that it 
points to the virtual table for that class. Unlike the *this 
pointer, which is actually a function parameter used by the 
compiler to resolve self-references, *__vptr is a real pointer. 
Consequently, it makes each class instance allocated bigger by 
the size of one pointer. It also means that *__vptr is inherited 
by derived classes, which is important.


*/

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    // Create a function pointer and make it point to the add function
    int (*pFcn)(int, int) { add };
    std::cout << pFcn(5, 3) << '\n'; // add 5 + 3

    return 0;
}