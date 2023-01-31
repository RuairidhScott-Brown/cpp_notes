/*
POITNER TO A POITNER


*/
#include<iostream>

int main() {
    //pointer to an int
    int* ptr;

    //pointer to a pointer to an int =
    int** ptr;

    int value { 5 };

    int* ptr { &value };

    //should print 5
    std::cout << *ptr << '\n';

    //should print 5 too
    int** ptrptr { &ptr };
    std::cout << **ptrptr << '\n';

    //ARRAY OF POITNERS
    int** array3 { new int*[10] };

    //DYNAMIC MULTIDIMENSIONAL ARRAYS
    int (*array4)[5] { new int[10][5] }; //the right most array size has to be a compile time constant
    auto array5 {new int[10][5]};

    //passing to a function
    int multiply(const double (*a)[], const double (*b)[], int n) {return 0;}



    //if the right most value is not a compile time constant
    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count) {
        array[count] = new int[5]; // these are our columns
    }
    for (int count = 0; count < 10; ++count) {
        delete[] array[count];
    }
    delete[] array; // this needs to be done last




    return 0;
}