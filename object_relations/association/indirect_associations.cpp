/*
INDIRECT
    in the other examples pointers and references have been use to link the objects together.
    You do not necessarily have to use these as an association allows for any type of linking
    that allow two objects to be connected.
*/

#include <iostream>
#include <string>

class Car {
    private:
        std::string m_name {};
        int m_id {};

    public:
        Car(const std::string& name, int id)
            : m_name {name}, m_id {id} {}

        const std::string&  getName() const {return m_name;}

        int getId() const { return m_id;}
};

class CarLot {
    
    private:
        static Car s_carlot[4];

    public:
        CarLot() = delete;

        static Car* getCar(int id) {
            for (int count {0}; count <  4; ++count) {
                if (s_carlot[count].getId() == id) {
                    return &(s_carlot[count]);
                }
            }

            return nullptr;
        }
};

class Driver {
    private:
        std::string m_name {};
        int m_carId {};

    public:
        Driver(std::string& name, int carId)
            : m_name {name}, m_carId {carId} {}

        const std::string& getName() const {return m_name;}
        int getCarId() const {return m_carId;}
};

int main()
{
    std::string name {"Franz"};
    
	Driver d{name, 17}; // Franz is driving the car with ID 17

	Car* car{ CarLot::getCar(d.getCarId()) }; // Get that car from the car lot

	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << " couldn't find his car\n";

	return 0;
}