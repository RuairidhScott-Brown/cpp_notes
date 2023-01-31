/*
AGGREGATION RULES
    - the part (member) is part of the object.
    - the part (member) can belong to more than one member.
    - the part (member) does not have it existence managed by the class/object
    - the part (member) does not know about the existence of the object or class

EXAMPLE
    relationship between a person and their home adress.
    - the address can belong to more than one person
    - the address isn't managed by the person
    - the address doesnt know about the person
    - the address is part of the persons class/object

    
    - Typically use pointer or reference members that point to or reference objects that live outside the scope of the aggregate class
    - Not responsible for creating/destroying parts 
*/

#include <iostream>
#include <string>

class Teacher {
    private:
        std::string m_name {};

    public:
        Teacher(const std::string& name)
            : m_name{name} {}

        const std::string& getName() const {return m_name;}
};


class Department {
    private:
        const Teacher& m_teacher;

    public:
        Department(const Teacher& teacher)
            : m_teacher{teacher} {}
};

int main() {
    Teacher bob{"bob"};

    {
        Department department {bob}; 
    }

    std::cout << bob.getName() << "still exists\n";

    return 0;
}