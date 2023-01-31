

#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <iostream>

class IntArray {
    private:
        int m_length {};
        int* m_data {};

    public:
        IntArray() = default;

        IntArray(int length)
            : m_length {length} {

                assert(length >= 0);

                if (length > 0) {
                    m_data = new int[length] {};
                }
            }

        ~IntArray() {
            delete[] m_data;
            //we don't need to add a nullptr or change m_length here as the
            //object will be destroyed after this function anyway.
        }

        void erase() {
            delete[] m_data;

            m_data = nullptr;
            m_length = 0;
        }

        int& operator[](int index) {
            assert(index >= 0 && index < m_length);

            return m_data[index];
        }

        int getLength() const {return m_length;}

        void reallocate(int newLength) {
            erase();

            if (newLength <= 0) {
                return;
            }

            m_data =  new int[newLength];
            m_length = newLength;
        }

        void resize(int newLength) {

            if (newLength == m_length) {
                return;
            }

            if (newLength <= 0) {
                erase();
                return;
            } 

            int* data {new int[newLength]};

            if (m_length > 0) {
                int elementsToCopy {(newLength > m_length) ? m_length : newLength};

                for (int index{0}; index < elementsToCopy; ++index) {
                    data[index] = m_data[index];
                }
            }

            delete[] m_data;

            m_data = data;
            m_length = newLength;
        }

        void insertBefore(int value, int index) {

            assert(index >= 0 && index  <= m_length);

            int* data {new int[m_length + 1]};
            
            for (int before{0}; before <  index; ++before) {
                data[before] = m_data[before];
            }

            data[index] = value;

            for (int after{index}; after < m_length; ++after) {
                data[after + 1] = m_data[after];
            }

            delete[] m_data;
            m_data = data;
            ++m_length;
        }

        void remove(int index) {
            assert(index >= 0 && index < m_length);

            if (m_length == 1) {
                erase();
                return;
            }

            int* data {new int[m_length - 1]};

            for (int before{0}; before < index; ++before) {
                data[before] = m_data[before];
            }

            for (int after{index+1}; after < m_length; ++after) {
                data[after-1] = m_data[after];
            }

            delete[] m_data;
            m_data = data;
            --m_length;
        }

        void insertAtBeginning(int value) {insertBefore(value, 0);}
        void insertAtEnd(int value) {insertBefore(value, m_length);}
};



int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i<10; ++i)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Print out all the numbers
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}

#endif