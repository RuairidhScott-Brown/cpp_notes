/*
In this example there is a single reference to one teacher in the department class.
This is fine if there is only one teacher but if there are more (say we have a vector)
then we cant use a reference.

Why not?
list elements can't be references.

Solution?
they could be pointers but this opens up a can or worms.

Fancy stuff?
std::reference_wrapper is a class that acts like a reference but it allows copying and assignment
i.e. you can use std::vector

USING STD::REFERENCE_WRAPPER
    - when you create a reference wrapper the object cant be anonymous (this is because anonymous
    objects have expression scope and this would leave the referecnce dangling)
    - to get the object out of the reference wrapper you have to use get()
*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>

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
        //const Teacher& m_teacher;
        std::vector<std::reference_wrapper<const Teacher>> m_teachers {};

    public:
        Department() {}

        Department(const Teacher& teacher) {
            m_teachers.push_back(teacher);
        }
        
        void add(const Teacher& teacher) {
            m_teachers.push_back(teacher);
        }

        friend std::ostream& operator<<(std::ostream& out, const Department& department) {
            for(const auto& teacher : department.m_teachers) {
                out << " " << teacher.get().getName();
            }

            out << "\n";
            return out;
        }
};


void question2() {

    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

}

int main() {
    Teacher bob{"bob"};

    {
        Department department {bob}; 
    }

    std::cout << bob.getName() << "still exists\n";

    //example of using std::reference_wrapper
    std::string tom {"tom"};
    std::string berta {"berta"};
    std::vector<std::reference_wrapper<std::string>> names {tom, berta};

    std::string jim {"jim"};
    names.push_back(jim);
    
    for (auto name : names) {
        name.get() += " beam";
    }

    std::cout << jim << '\n';

    //question 2 from the quiz
    question2();

    return 0;
}