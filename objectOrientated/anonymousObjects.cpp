/*
ANONYMOUS OBJECTS

    - this is a object with no name and therefore have expression scope  meaning that the a created used and destroyed in one expression

*/
#include <iostream>


int sum(int x, int y) {
    //note that x+y is calculated and made into an anonymous object which is then copyed to return from the function
    return x + y;
}

void printValue(int x) {
    std::cout << x;
}


class Cents {
    private:
        int m_cents;

    public:
        Cents(int cents)
            : m_cents(cents) {}

        int getCents() const {return m_cents;}
};

Cents add(const Cents &c1, const Cents &c2) {
    Cents sum {c1.getCents() + c2.getCents()};
    return sum;
}



int main() {
    std::cout <<  sum(5,3) << std::endl;
    printValue(5+3);
    int value {5 +3};
    printValue(value);

    Cents cents1 {6};
    Cents cents2 {5};
  
    std::cout << "I have " << add(cents2, cents1).getCents() << " cents.\n";
    std::cout << "I have " << add(Cents{6}, Cents{5}).getCents() << " cents.\n";
    
    return 0;
}