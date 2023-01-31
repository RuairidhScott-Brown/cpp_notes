/*
L-Value and R-Value

TYPE OF AN EXPRESSION

- type of an expression is equivalent to the type of the value
  object, or function that results from the evaluated expression

-  type of an expression must be determinable at compile time

- the value of an expression may be determined at either compile
  time (if the expression is constexpr) or runtime (if the expression is not constexpr).


VALUE OF AN EXPRESSION

-  The value category of an expression (or subexpression)
   indicates whether an expression resolves to a value, a function,
   or an object of some kind.

- Prior to C++11, there were only two possible value categories: lvalue and rvalue.

- In C++11, three additional value categories (glvalue, prvalue, and xvalue) 
  were added to support a new feature called move semantics.

- lvalue is an expression that evaluates to an identifiable object or function (or bit-field).
        - An entity (such as an object or function) that has an identity can be differentiated 
          from other similar entities (typically by comparing the addresses of the entity).

        - Entities with identities can be accessed via an identifier, reference, or pointer, 
          and typically have a lifetime longer than a single expression or statement.

        - values come in two subtypes: a modifiable lvalue is an lvalue whose value can be
          modified. A non-modifiable lvalue is an lvalue whose value can’t be modified
          (because the lvalue is const or constexpr).

- rvalue is an expression that is not an l-value. Commonly seen rvalues include literals 
  and the return value of functions and operators. Rvalues aren’t identifiable (meaning they have to be used immediately),
  and only exist within the scope of the expression in which they are used.



CONVERTING BETWEEN THE VALUES

- The answer is because lvalues will implicitly convert to rvalues, so an lvalue can be used wherever an rvalue is required.

*/


#include <iostream>

int main()
{
    int x { 5 };
    int y { x }; // x is an lvalue expression
    //x is an lvalue expression as it evaluates to variable x (which has an identifier).

    const double d{};
    const double e { d }; // d is a non-modifiable lvalue expression

    return 0;
}

int return5()
{
    return 5;
}

int main()
{
    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

    return 0;
}