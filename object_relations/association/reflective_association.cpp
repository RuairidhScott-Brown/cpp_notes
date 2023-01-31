/*
REFLECTIVE ASSOCIATION
    when objects have a relationship with other objects of the same type.

    e.g.
    you can think of a university course and its pre-requisites

*/

#include <string>

class Course {
    private:
        std::string m_name;
        const Course* m_prerequisites;

    public:
        Course(const std::string& name, const Course* prerequisites = nullptr)
            : m_name {name}, m_prerequisites {prerequisites} {}
};