/*
BASIC INHERITANCE (public)
    - child class inherits both the member functions and member variables
      from the parent class public section.
    - using the public specifier creates a is-a relationship.

*/


#include <string>
#include <iostream>

class Person {

    public:
        std::string m_name {};
        int m_age {};

        Person(const std::string& name = "", int age = 0)
            : m_name {name}, m_age {age} {}

        const std::string& getName() const {return m_name;}
        int getAge() const {return m_age;}


};

//this is public inheritiance
class BaseballPlayer : public Person {
    
    public:
        double m_battingAverge {};
        int m_homeRuns {};

        BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
            : m_battingAverge {battingAverage}, m_homeRuns {homeRuns} {}
};

class Employee : public Person {
    
    public:
        double m_hourlySalary {};
        long m_employeeID {};

        Employee(double hourlySalary = 0.0, long employeeID = 0)
            : m_hourlySalary {hourlySalary}, m_employeeID {employeeID} {}

        void printNameAndSalary() const {
            std::cout << m_name << ": " << m_hourlySalary << '\n';
        }
};

class Supervisor : public Employee {
    public:
        long m_overseesIDs[5] {};
};

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe{};
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    Employee frank{20.25, 12345};
    frank.m_name = "Frank"; // we can do this because m_name is public

    frank.printNameAndSalary();

    return 0;
}