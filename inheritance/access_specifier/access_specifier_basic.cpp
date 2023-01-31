/*
ACCESS SPECIFIER

PUBLIC
    - establishes a "is-a" relationship between the Base class and the Derived class
    - if a specifier is not defined then this is the defaukt.

PROCTECTED
    - the protected access specifier allows the class the member belongs to, friends, and 
      derived classes to access the member. However, protected members are not accessible 
      from outside the class.
    - Favor private members over protected members.

PRIVATE AND PROCTECTED
    - establishes a "derived class has a base class" relationship
    - different from composition.


*/

class Base
{
public:
    int m_public {}; // can be accessed by anybody
protected:
    int m_protected {}; // can be accessed by Base members, friends, and derived classes
private:
    int m_private {}; // can only be accessed by Base members and friends (but not derived classes)
};

class Derived: public Base
{
public:
    Derived()
    {
        m_public = 1; // allowed: can access public base members from derived class
        //m_protected = 2; // allowed: can access protected base members from derived class
        //m_private = 3; // not allowed: can not access private base members from derived class
    }
};

int main()
{
    Base base;
    base.m_public = 1; // allowed: can access public members from outside class
    //base.m_protected = 2; // not allowed: can not access protected members from outside class
    //base.m_private = 3; // not allowed: can not access private members from outside class

    return 0;
}