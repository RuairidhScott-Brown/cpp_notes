#include <iostream>

class Cents {
    private:
        int m_cents;

    public:
        Cents(int value)
            : m_cents{value} {}

        int getCents() const {return m_cents;}
};

/* note that you will speciffially have to define a prototype in the header file where you define the class 
   this is not true if you use a friend class
*/
Cents operator+(const Cents &c1, const Cents &c2) {
    return Cents(c1.getCents() + c2.getCents());
}


int main() {
    Cents cents1(6);
    Cents cents2(4);
    Cents centsSum( cents1 + cents2);

    std::cout << "I have " << centsSum.getCents() << '\n';

    return 0;
}


