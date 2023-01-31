/*
DEPENDENCIES
    one object invokes another objects functionality in order 
    to accomplish a specific task.

    Unidirectional

    e.g.
    the use of std::cout. It is not controlled in any way by the object we use
    it in but it is needed.

*/

#include <iostream>

class Point {
    /*
    In the above code, Point isn’t directly related to std::cout, but it has a 
    dependency on std::cout since operator<< uses std::cout to print the Point to 
    the console.
    */
    private:
        double m_x, m_y, m_z;

    public:
        Point(double x = 0.0, double y = 0.0, double z = 0.0)
            : m_x {x}, m_y {y}, m_z {z} {}

        friend std::ostream& operator<<(std::ostream& out, const Point &point);
};

std::ostream& operator <<(std::ostream& out, const Point& point) {
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
    return out;
}

int main()
{
    Point point1(2.0, 3.0, 4.0);

    std::cout << point1;

    return 0;
}