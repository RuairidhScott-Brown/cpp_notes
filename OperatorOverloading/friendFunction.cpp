/*
USING THE FRIEND FUNCTION TO IMPLIMENT OPERATOR OVERLOADING

    - for binary operators there has to be two typer one for cents(4) + 4 (cents, int) and 4 + cents(4) (int, cents)

*/

#include <iostream>

class Cents {
    private:
        int m_cents;

    public:
        Cents(int cents) : m_cents{cents} {}

        friend Cents operator+(const Cents &c1, const Cents &c2);
        
        friend Cents operator+(const Cents &c1, int value);

        friend Cents operator+(int value, const Cents &c1);

        int getCents() const { return m_cents;}
};

Cents operator+(const Cents &c1, const Cents &c2) {
    return c1.m_cents + c2.m_cents;
}

Cents operator+(const Cents &c1, int value) {
    return c1.m_cents + value;
}

Cents operator+(int value, const Cents &c1) {
    return c1.m_cents + value;
}

int main() {
    Cents c1 {Cents(4) + 6};
    Cents c2 {6 + Cents(4)};
    Cents c3 {Cents(4) + Cents(6)};

    std::cout << "I have " << c1.getCents() << '\n';
    std::cout << "I have " << c2.getCents() << '\n';
    std::cout << "I have " << c3.getCents() << '\n';
          

    return 0;
}
