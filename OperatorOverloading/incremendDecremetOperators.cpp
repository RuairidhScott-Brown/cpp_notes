/*
The increment and decrement operators are a bit tricky as they can have two meanings:
    ++x -> increments x and then returns x (prefix)
    x++ -> returns x and then increments x (posfix)

*/

#include <iostream>

class Digit {
    private:
        int m_digit;
    
    public:
        Digit(int digit = 0)
            : m_digit{digit} {}

        //Prefix
        Digit& operator++();
        Digit& operator--();

        //posfix
        Digit operator++(int);
        Digit operator--(int);

        friend std::ostream& operator<<(std::ostream &out, const Digit &digit);
};

Digit& Digit::operator++() {
    if (m_digit == 9) {
        m_digit = 0;
    } else {
        ++m_digit;
    }

    return *this;
}

Digit& Digit::operator--() {
    if (m_digit == 0) {
        m_digit = 9;
    } else {
        --m_digit;
    }

    return *this;
}

Digit Digit::operator++(int) {
    Digit temp{*this};

    ++(*this);

    return temp;
}

Digit Digit::operator--(int) {
    Digit temp{*this};

    --(*this);

    return temp;
}

std::ostream& operator<<(std::ostream &out, const Digit &digit) {
    out << digit.m_digit;
    return out;
}

int main()
{
    Digit digit(5);
 
    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;
 
    return 0;
}