/*
STATIC VARIABLES
    - when defined in a function. They keep their values
      and are not destroyed when they go out of scope.

    - when they are used for global variables it means that the
      variable can't be used outside the file they are created in.

    - One good use for a const static local variable is when you
      have a function that needs to use a const value, but creating
      or initializing the object is expensive (e.g. you need to read
      the value from a database). If you used a normal local variable,
      the variable would be created and initialized every time the 
      function was executed. With a const/constexpr static local variable,
      you can create and initialize the expensive object once, and 
      then reuse it whenever the function is called.

STATIC MEMBER VARIABLES
    - they are shared by all objects of the class

    - static members exist even if no objects of the
      class have been instantiated
    - they can be accessed directly using the class name 
      and the scope resolution operator
    - you must explicitly define the static member
      outside of the class, in the global scope.
    - static member definition is not subject to access controls

    - if const it can be initialised inside the class
    - static constexpr members can be initialized inside the class definition:
    - if using c++17 you can use the inline keyword

STATIC MEMBER FUNCTIOINS
    - static member functions are not attached to any particular object.
    - they can be called directly by using the class name and the scope resolution operator
    - they can also be called through objects of the class type, though this is not recommended.
    
    - they have no this pointer! This makes sense as the *this pointer is used to keep track of
      what object it is using.

    - static member functions can directly access other static members (variables or functions),
      but not non-static members.

*/

#include<array>
#include<iostream>
#include<vector>

class Whatever
{
public:
    static const int s_value{ 4 }; // a static const int can be declared and initialized directly
};

class Whatever2
{
public:
    static constexpr double s_value{ 2.2 }; // ok
    static constexpr std::array<int, 3> s_array{ 1, 2, 3 }; // this even works for classes that support constexpr initialization
};

class Whatever3
{
public:
    static inline int s_value{ 4 }; // a static inline int can be declared and initialized directly (C++17)
};

class Something
{
public:
    static int s_value; // declares the static member variable
};

int Something::s_value{ 1 }; // defines the static member variable (we'll discuss this section below)

class IDGenerator {
private:
    static int s_nextID; // Here's the declaration for a static member

public:
     static int getNextID(); // Here's the declaration for a static function
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::s_nextID{ 1 };

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; }


class MyClass{
public:
    static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars{
  []{ // The parameter list of lambdas without parameters can be omitted.
      // Inside the lambda we can declare another vector and use a loop.
      std::vector<char> v{};

      for (char ch{ 'a' }; ch <= 'z'; ++ch)
      {
          v.push_back(ch);
      }

      return v;
  }() // Call the lambda right away
};

int main()
{
    // note: we're not instantiating any objects of type Something

    Something::s_value = 2;
    std::cout << Something::s_value << '\n';

    for (int count{ 0 }; count < 5; ++count)
      std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}