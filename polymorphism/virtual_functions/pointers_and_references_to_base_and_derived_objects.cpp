/*
POINTER TO CLASSES

If we have a base class and derived class which
inherits from base. The are new object is both a 
base and derived object.

This means we can assign a derived object pointer as
a base pointer.

i.e.

Derived derived {5};

Base* base{&derived};

However, if we do this then the object base will have no idea about
the derived part. i.e. if can only call the base class methods. It
does not know that the pointer points to a derived object, only that
it has a base part.


*/