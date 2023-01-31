/*
STD::INITIALIZER_LIST
    - when the compiler sees an initialiser list it automatically converts it into an
    object of type std::initializer_list.

    - live in the initialiser_list header

CAVEAT
    - the std::initializer_list will take precedence over other constructors
    - for example:

        IntArray array {5};
    
    This will math with  IntArray(std::initializer_list<int>), not IntArray(int)

CLASS ASSIGNMENT USING INITIALISER_LIST
    - you can use this object to assign new values to the fucntion by overloading
    the assignment operator with it.

    i.e. array = { 1, 3, 5, 7, 9, 11 };


*/

#include <iostream>
#include <cassert>
#include <initializer_list>

void init_array_ints() {
    int array[] {5,4,3,2,1};
    for (auto i : array) {
        std::cout << i << ' ';
    }
}

void init_array_ints_dynamically() {
    int* array {new int[5] {5,4,3,2,1}};
}


class IntArray {
    private:
        int m_length {};
        int* m_data {};

    public:
        IntArray() = default;

        IntArray(int length)
            : m_length {length}, m_data {new int[length] {}} {}

        IntArray(std::initializer_list<int> list) 
            : IntArray(static_cast<int>(list.size())) {
                int count {0};
                for (auto element : list) {
                    m_data[count] = element;
                    ++count;
                }
            }

        ~IntArray() {
            delete[] m_data;
        }

        IntArray(const IntArray&) = delete;
        IntArray& operator=(const IntArray& list) = delete;

        int& operator[](int index) {
            assert(index >= 0 && index < m_length);
            return m_data[index];
        }

        int getLength() const {return m_length;}
};

int main() {
    init_array_ints();
    init_array_ints_dynamically()

    //need to come back to this note

}
