/*
CONSTRUCTION AND INITIALISATION
    - It is worth mentioning that constructors can only call constructors 
      from their immediate parent/base class.

    - with non derived classes construction only has to worry about its own
      members.
        e.g. initialisation of a Base object
        1. memory for the base is set aside
        2. the appropriate Base constructor is called
        3. the body of the constructor is executed
        4. control is returned to the caller

    - How does the initialisation of a derived class happen, in an essence
      the base classs does everything first.  
        1. memory for the derived object is set aside
        2. the derived constructor is called
        3. the base object is called with the appropriate construcotr
        4. the initialisation list initialises the variables
        5. control ios returned to the caller

        Essentially what happens is: Derived constuctor started -> Base constructor started and finishes
        -> Derived constructor finishes.

    
    - c++ prevents classes from initialising inherited memeber variabes in the initialisation
      list of the derived constuctor.  
        - consider if m_id was const.
            - because const variables must be initialised with values at the time
              of creation the base class constructor must set aside its value when
              the variable is created.
            - that means that when the derived constructor is then called it has the
              oppertunity to change the value of set aside from the base constuctor
              which is no good

    - what about chaning the base member variables y direct assignment in the body of the derived
      constructor?
        - wouldn't work if the base member variables were const
        - inefficient as it would mean assigning a variables data twice for no reason
        - and the base class might need this value in the construction body.   

    - The answer is t0 explicitly define what constructor should be used from the base class
        1. memory for the derived object is allocated
        2. the derived constructor is called
        3. the complier looks to see if we asked for a partcular base constuctor
        4. the base constructor initialisation list sets m_id
        5. the base class constructor body is executed
        6. the base class constructor returns
        7. the derived class constructor initialisation list is caleed
        8. the derived class constructor body is executed
        9. the derived class constructor returns

PRIVATE MEMBERS
     - public members can be accessed by anybody. Private members can only be accessed by member functions 
       of the same class. Note that this means derived classes can not access private members of the base class directly!

DESTRUCTORS
    - When a derived class is destroyed, each destructor is called in the reverse order of construction

*/

#include <iostream>

class Base
{
private:
    int m_id {};

public:
    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
private:
    double m_cost {};

public:
    Derived(double cost=0.0, int id = 0)
        : Base {id}, m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

#include <string>

#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    int m_age {};

public:
    Person(const std::string& name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
private:
    double m_battingAverage {};
    int m_homeRuns {};

public:
    BaseballPlayer(const std::string& name = "", int age = 0,
        double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age } // call Person(const std::string&, int) to initialize these fields
        , m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};





int main()
{
    Base base{ 5 }; // use Base(int) constructor

    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    BaseballPlayer pedro{ "Pedro Cerrano", 32, 0.342, 42 };

    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';
    std::cout << pedro.getHomeRuns() << '\n';

    return 0;
}