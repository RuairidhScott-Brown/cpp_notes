/*
PURE VIRTUAL FUNCTIONS
    - used to make a abstract class
    - specified with "=0"

    virtual void function() = 0; //pure virtual function 

    -the derived class after base muse override the base class
     otherwise the derived class will also become abstract.

    class shape { //abstract class
        private:

        public:
            virtual void draw() = 0 //pure virtual function 
            virtual void rotate() = 0 //pure virtual function 
            virtual ~Shape();
    };

    Shape s; \\Error
    Shape *ptr = new Shape(); \\Error

    Shape *ptr = new Circle(); \\fine
    ptr->draw(); \\fine
    ptr->rotate(); \\fine

ABSTRACT CLASS
    - cannot instantiate objects
    - theses are base classes in inheritance hierarchies
    - contains at least one pure virtual function.

CONCRETE CLASS
    - a normal class

REMEBER:
    That by using the virtual keyword the compiler will know that you are
    wanting to use the most derived method (i.e. overrideing the previous base
    class methods that have the same name and parameters.)


*/
#include <iostream>
#include <vector>

class Shape {			// Abstract Base class
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	 // pure virtual function
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape {    // Abstract class
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  // Abstract class as we did not overide the pure
                                     // virtual functions
public:
    virtual ~Closed_Shape() { };
};

class Line: public Open_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {
//    Shape s;
//    Shape *p = new Shape(); //This should not work

//        Circle c; //this is statically bound
//        c.draw();

//    Shape *ptr = new Circle();
//    ptr->draw();
//    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};
    
//    for (const auto p: shapes) 
//        p->draw();
        
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}
