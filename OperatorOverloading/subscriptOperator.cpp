/*
SUBSCRIPT OPERATOR OVERLOADING
    - must use a member function

    - the overloaded operator must always return a reference
      because the operator list[2] can be used on the left hand side
      i.e.

      list[2] = 3;

      it then must be a left hand value which means it must have a memory address
      and a reference counts as a l-value


*/
#include <iostream>

class InList {
    private:
        int m_list[10] {1,1,1,1,1,1,1,1,1,1};

    public:
        int& operator[] (int index);
        const int& operator[] (int index) const;
};

int& InList::operator[] (int index) {
    return m_list[index];
}

const int& InList::operator[] (int index) const {
    return m_list[index];
}


int main() {
    InList list {};
    list[2] = 3;
    std::cout << list[2] << '\n';
  
    const InList list1 {};
    //list1[2] = 3; //should cause an error due the attempt to edit a const object
    std::cout << list1[2] << '\n';


    //dealing with pointers
    InList *list3 = new InList{}; //creating a pointer to a list object
    (*list3)[2] = 3; //dereferenceing the list pointer to give the list
    delete list3;

    return 0;
}
