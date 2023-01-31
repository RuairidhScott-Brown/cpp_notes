/*
BASIC ARRAYS IN C++
- have to know the length at compile time.
- cant define the length of the array with a varaible that is not known at compile time.


*/
#include<iostream>
#include<iterator>



void array_with_enum() {
    //using enums so that the indexing is more clear.
    enum Student_Names {
        Ruairidh,
        James,
        Kyle,
        Alex,
        Zoe,
    };

    int test_scores[5] {};
    std::cout << test_scores[Ruairidh] << '\n';
}

void passing_array_to_function() {
    //arrays are passed by reference and are not copied.
    //using function such as size and sizeof will not work if an array is passed
    //a function
}

void size_of_array() {
    int vec[5] {};
    std::cout << std::size(vec) << '\n';
    //you can use the sizeof operator to get the ize in bytes and then  depending on the
    //size of the variable type you can figure out the size of the array.
    std::cout << "The array has: " << sizeof(vec) / sizeof(vec[0]) << " elements\n";
}


int main() {
    return 0;
}