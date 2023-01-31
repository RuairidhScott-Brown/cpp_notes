/*
ENUMS

- An enumeration (also called an enumerated type or an enum) is a compound
  data type where every possible value is defined as a symbolic constant
  (called an enumerator).

- Each enumerated type you create is considered to be a distinct type.

- each enumerator is automatically assigned an integer value based on
  its position in the enumerator list.

- first enumerator is assigned the integral value 0
  and each subsequent enumerator has a value one greater 
  than the previous enumerator:

- you can specify the types too

UNSCOPED ENUMERATION

- Unscoped enumerations are named such because they put their enumerator names
  into the same scope as the enumeration definition itself (as opposed to creating
  a new scope region like a namespace does

  e.g.

    enum Color
    {
        red,
        green,
        blue, // blue is put into the global namespace
    };

    enum Feeling
    {
        happy,
        tired,
        blue, // error: naming collision with the above blue
    };

    int main()
    {
        Color apple { red }; // my apple is red
        Feeling me { happy }; // I'm happy right now (even though my program doesn't compile)

        return 0;
    }

    both unscoped enumerations (Color and Feeling) put enumerators with the same name
    blue into the global scope. This leads to a naming collision and subsequent
    compile error.

- the compiler will then implicitly convert an unscoped enumeration or enumerator to
  its corresponding integer value BUT it will not implicitly convert an integer to 
  an unscoped enumerator. Unless you force it:

    Pet pet { static_cast<Pet>(2) }; // convert integer 2 to a Pet
    pet = static_cast<Pet>(3);

  IN c++17 you can do this tho:
    Pet pet { 2 }; // ok: can initialize with integer


- you can use a switch statement along with an enum

- you can override the operator<< to get a better ostream experience.

*/
#include<iostream>
#include<string>


// UNSCOPED ENUMERATION
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red, // 0
    green, // 1
    blue, // 2 
    // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

enum Animal
{
    cat = -3,
    dog,         // assigned -2
    pig,         // assigned -1
    horse = 5,
    giraffe = 5, // shares same value as horse thus the enumerators become non-distinct.
    chicken,      // assigned 6
};

enum FileReadResult
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

FileReadResult readFileContents() {
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

// GOOD PRACTICE FOR NAMING
enum Feeling
{
    feeling_happy,
    feeling_tired,
    feeling_blue, // no longer has a naming collision with color_blue
};

// BEST PRACTICE FOR DEFINING
namespace color
{
    // The names Color, red, blue, and green are defined inside namespace color
    enum Color
    {
        red,
        green,
        blue,
    };
}

enum Color : std::uint16_t
{
    black,
    red,
    blue,
};

enum Pet
{
    cat, // assigned 0
    dog, // assigned 1
    pig, // assigned 2
    whale, // assigned 3
}

constexpr std::string_view getColor(Color color) // C++17
{
    switch (color)
    {
    case black: return "black";
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

// Teach operator<< how to print a Color
// Consider this magic for now since we haven't explained any of the concepts it uses yet
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Color color)
{
	switch (color)
	{
	case black: out << "black";  break;
	case red:   out << "red";    break;
	case blue:  out << "blue";   break;
	default:    out << "???";    break;
	}

	return out;
}

std::istream& operator>> (std::istream& in, Pet &pet)
{
    int input{};
    in >> input; // input an integer

    pet = static_cast<Pet>(input);
    return in;
}

int main() {
    Color apple { red };   // my apple is red
    Color shirt { Color::green }; // my shirt is green
    Color cup { blue };    // my cup is blue

    Color socks { white }; // error: white is not an enumerator of Color
    Color hat { 2 };       // error: 2 is not an enumerator of Color

    if (readFileContents() == readResultSuccess) {
    // do something
    } else {
    // print error message
    
    }
    return 0;

    Color shirt{ blue };

    std::cout << "Your shirt is " << shirt; // what does this do? -> Your shirt is 2

    return 0;
}