/*
ASSOCIATION
    - the associated object (member) is otherwise unrelated to the object
    - the associated object (member) can belong to more than one object
    - the assocaited object (member) does not have its existence managed by the object
    - the assocaited object (member) may or may not know about the existence of the object

    the relationship may be unidirectional or bidirectional (where the two objects are aware of each other).

    e.g.
    The doctor clearly has a relationship with his patients, but conceptually it’s not a part/whole (object composition)
    relationship. A doctor can see many patients in a day, and a patient can see many doctors


*/

#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Patient;

class Doctor {
    private:
        std::string m_name {};
        std::vector<std::reference_wrapper<const Patient>> m_patients {};

    public:
        Doctor(const std::string& name)
            : m_name {name} {}

        void addPatient(Patient& patient);

        friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

        const std::string& getName() const {return m_name;}
};

class Patient {
    private:
        std::string m_name {};
        std::vector<std::reference_wrapper<const Doctor>> m_doctors {};

        void addDoctor(const Doctor& doctor) {
            m_doctors.push_back(doctor);
        }

    public:
        Patient(const std::string& name)
            : m_name {name} {}

        friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

        const std::string& getName() const {return m_name;}

        friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient) {
    m_patients.push_back(patient);

    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
    if (doctor.m_patients.empty()) {
        out <<  doctor.m_name << " has no patients right now";
        return out;
    }

    out <<  doctor.m_name << " is seeing patients: ";
    for (const auto& patient :  doctor.m_patients) {
        out << patient.get().getName() <<  ' ';
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    if (patient.m_doctors.empty()) {
        out << patient.getName() << " has not doctors right now.";
        return out;
    }

    out << patient.m_name << " is seeing doctors: ";
    for (const auto& doctor : patient.m_doctors) {
        out << doctor.get().getName() << ' ';
    }
    return out;
}

int main()
{
	// Create a Patient outside the scope of the Doctor
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };

	Doctor james{ "James" };
	Doctor scott{ "Scott" };

	james.addPatient(dave);

	scott.addPatient(dave);
	scott.addPatient(betsy);

	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';

	