/*
OVERLOADING TYPECASTING

- does not take any parameters
- does not have a return type as C++ assumes your not a dumb cunt



*/

#include <iostream>

class Cents {
    private:
        int m_cents {};

    public:
        Cents(int cents = 0) : m_cents{cents} {}

        operator int() const { return m_cents;}

        int getCents() {return m_cents;}
        void setSents(int cents) {m_cents = cents;}
};

void printInt(int value) {
    std::cout << value;
}

class Dollars {
    private:
        int m_dollars;

    public:
        Dollars(int dollars = 0) : m_dollars(dollars) {}

        operator Cents() const {return Cents(m_dollars * 100);}
};

void printCents(Cents cents) {
    std::cout << cents;
}


int main() {
    Cents cents{ 7 };
    int c {static_cast<int>(cents)};
    printInt(cents);

    std::cout << '\n';

    Dollars dollars {9};
    printCents(dollars);

    std::cout << '\n';

    return 0;
}