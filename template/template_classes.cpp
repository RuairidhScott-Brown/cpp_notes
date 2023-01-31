/*
TEMPLATE CLASSES

- member functions defined outside the class need their own template declaration

- the compiler stencils out a copy upon demand, with the template parameter replace
  by the actual data type the user needs, and then compiles the copy.

- If you don’t ever use a template class, the compiler won’t even compile it.

- you should put the full code in the header file for a template class. Do not
  separate into header and cpp files. This will not work.

*/


#include <cassert>
#include <iostream>

template<class T>
class Array
{
private:
    int m_length{};
    T* m_data{};

public:

    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    // We don't want to allow copies of IntArray to be created.
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};


// member functions defined outside the class need their own template declaration
template <typename T>
int Array<T>::getLength() const // note class name is Array<T>, not Array
{
  return m_length;
}

int main()
{
	Array<int> intArray { 12 };
	Array<double> doubleArray { 12 };

	for (int count{ 0 }; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';

	return 0;
}