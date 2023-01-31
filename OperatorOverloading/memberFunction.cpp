/*
MEMEBR FUNCTION USED TO OVERLOAD THE OPERATOR
    restrictions
    - the overloaded operator must be a membe function of the left operand
    - the left operand becomes the implicit *this object
    - all other operands become function parameters

    if you want to overload using = [] () -> requires the use of memebr functions
    however if you do not hace access to the class/object that defines the left operand then you have
    to use a normal function or a friend function
*/



#include <iostream>

class Cents {
    private:
        int m_cents;

    public:
        Cents(int cents) 
            : m_cents{cents} {}

        Cents operator+(int value);

        int getCents() const {return m_cents;}    
};

Cents Cents::operator+(int value) {
    return Cents(m_cents + value);
}

int main() {
    Cents cents1(6);
    Cents cents2 = cents1 + 2;

    std::cout << "I have " << cents2.getCents() << '\n';

    return 0; 
}