/*
PARTIAL TEMPLATE SPECIALISATION FOR POINTERS

- Sometimes when you are expecting a pointer to a class
  you want to do a deep copy rather than a shallow copy of the
  pointer address. An example would be a char array. Most of the time
  you don't want the pointer to the array in the class but rather a copy
  of the actual data in the array.

- Full specialisation will always take precedence.

*/



#include <iostream>

template <typename T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value)
        : m_value { value }
    {
    }

    ~Storage()
    {
    }

    void print() const
    {
        std::cout << m_value << '\n';
    }
};

// You need to include the Storage<T> class from the example above here

template <typename T>
class Storage<T*> // this is a partial-specialization of Storage that works with pointer types
{
private:
    T* m_value;
public:
    Storage(T* value) // for pointer type T
        : m_value { new T { *value } } // this copies a single value, not an array
    {
    }

    ~Storage()
    {
        delete m_value; // so we use scalar delete here, not array delete
    }

    void print() const
    {
        std::cout << *m_value << '\n';
    }
};


// Full specialization of constructor for type char*
template <>
Storage<char*>::Storage(char* value)
{
	// Figure out how long the string in value is
	int length { 0 };
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator

	// Allocate memory to hold the value string
	m_value = new char[length];

	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

// Full specialization of destructor for type char*
template<>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

// Full specialization of print function for type char*
// Without this, printing a Storage<char*> would call Storage<T*>::print(), which only prints the first char
template<>
void Storage<char*>::print() const
{
	std::cout << m_value;
}

int main()
{
	// Declare a non-pointer Storage to show it works
	Storage<int> myint { 5 };
	myint.print();

	// Declare a pointer Storage to show it works
	int x { 7 };
	Storage<int*> myintptr { &x };

	// If myintptr did a pointer assignment on x,
	// then changing x will change myintptr too
	x = 9;
	myintptr.print();

	// Dynamically allocate a temporary string
	char* name { new char[40]{ "Alex" } };

	// Store the name
	Storage<char*> myname { name };

	// Delete the temporary string
	delete[] name;

	// Print out our name to prove we made a copy
	myname.print();
}