/*
COPY CONSTRUCTOR
    - special type of constructor that creates a new object from another one
    - if you want to prevent copys of the class being made then we can make the copy constructor private

Elision
    - take the example of:

        Fraction fraction(Fraction(5,3));
        
    we create an anonymous object with Fraction(5,3) then we use the anonymous object as an initialiser for the fiveThirds. As the anonymous object is a Fraction object
    and we are initialising another Fraction object you would think that the copy constructor is called but it isn't. This is a optimisation that takes place.
    
MEMBER WISE INITIALISATION
    - each member is initialised directly from the other object



*/

//THE DIFFERENT TYPE OF INITIALISATIONS

//Direct
int g_x(5);

//Uniform
int g_y {5};

//Copy
int g_z = 5;


#include <cassert>
#include <iostream>

class Fraction {
    private:
        int m_numerator;
        int m_denominator;

    public:
        Fraction(int numerator = 0, int denominator = 0)
            : m_numerator(numerator), m_denominator(denominator) {}

        //NOTE: we can access the private member variables for the other object
        Fraction(const Fraction &fraction)
            : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator) {
                std::cout << "Copy constructor called\n";
            }
        
        friend std::ostream& operator<<(std::ostream &out, const Fraction &f1);        
};

std::ostream& operator<<(std::ostream &out, const Fraction &f1) {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
} 

int main() {
    Fraction fiveThirds(5,3);
    Fraction fCopy(fiveThirds);
    std::cout << fCopy << '\n';
    return 0;
}

