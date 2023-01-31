/*
STATIC BINDING
    - c++ defaults to static binding of method calls.
    - bindings of what methods are used are decided at compile time.
    - Derived class objects will use Derived::deposit
    - Can overide explicitly by invoking Base::deposit from Derived::deposit

    Base b;
    b.deposit(1.0); //Base::deposit

    Derived d;
    d.deposit(1.0); //Derived::deposit

    Base *ptr = new Derived(); //this is valid
    ptr->deposit(1.0)    //Base::deposit

*/