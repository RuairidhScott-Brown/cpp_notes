/*
COMPOSITE TYPES
    - you can think of structs and classes as compositie type because they are an aggregation of other types

COMPOSTION
object composition is the process of creating complex objects from simpler ones.

    An object must have the following properties to be classed as composition
        - the part memeber is part of the object class
        - the part member can only belong to one object class at a time
        - the part member has its existence managed by the object class
        - the part memeber does not know about the existence of the object

    the part is often created and destroyed when the object is created and destroyed

    unidirectional behaviour is observed as the member has no idea about the class as a whole

    Example of someones heart: 
        - heart is part of the human class/object
        - heart can only belong to one person at a time
        - the heart is managed by the class/object person
        - and the heart doesnt know about the rest of the body

EXCEPTIONS TO THE COMPOSITION RULES
    - composition may defer creation of some of the parts until they are needed and not right at the beginning. such as dynamic arrays
    - composition may use a part that has been given to it at the beginning rather than at creat it itself
    - composition may delegate destruction of its parts to another object such as a garbage collector for example.

    
    - Typically use normal member variables
    - Can use pointer members if the class handles object allocation/deallocation itself
    - Responsible for creation/destruction of parts 

*/

#include <iostream>

class Fraction {
    /*
    For the numerator and denominator
    - the part memeber is part of the object class == True
    - the part member can only belong to one object class at a time == True
    - the part member has its existence managed by the object class == True 
    - the part memeber does not know about the existence of the object == True

    */
    private:
        int m_numerator;
        int m_denominator;

    public:
        Fraction(int numerator = 0, int denominator = 1)
            : m_numerator{numerator}, m_denominator{denominator} {
                //std::reduce(); make a note that I'm not really sure how this works
            }

        



};

