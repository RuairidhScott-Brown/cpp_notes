/*
REFERENCES

- can be thought of sort of like an alias to a variable
- but it takes its own space in memory

HOW THEY WORK BEHIND THE SCENES
- int &i = j ==> int* const i = &j
i.e. a reference is just a constant pointer to a variable
- note that reference get automaitcally dereferenceds


*/
#include<iostream>

using namespace std;

void basics() {
    int i = 10;   // A simple integer variable
    int &j = i;   // A Reference to the variable i
    
    j++;   // Incrementing j will increment both i and j.

    // check by printing values of i and j
    std::cout<<  i  <<  j  << std::endl; // should print 11 11

    // Now try to print the address of both variables i and j
    std::cout<<  &i  <<  &j  <<std::endl; 
    // surprisingly both print the same address and make us feel that they are
    // alias to the same memory location. 
    // In example below we will see what is the reality
}

void removing_syntax_sugar() {
    int i = 10;   		// A simple integer variable
    int *const j = &i;   	// A Reference to the variable i
    
    (*j)++;   		// Incrementing j. Since reference variables are 
			// automatically dereferenced by compiler

    // check by printing values of i and j
    std::cout<<  i  <<  *j  << std::endl; // should print 11 11
    // A * is appended before j because it used to be reference variable
    // and it should get automatically dereferenced.
}

void cascade_references() {
    int i = 10; // A Simple Integer variable
    int &j = i; // A Reference to the variable
    // Now we can also create a reference to reference variable. 
    int &k = j; // A reference to a reference variable
    // Similarly we can also create another reference to the reference variable k
    int &l = k; // A reference to a reference to a reference variable.

    // Now if we increment any one of them the effect will be visible on all the
    // variables.
    // First print original values
    // The print should be 10,10,10,10
    cout<<  i  <<  ","  <<  j  <<  ","  <<  k  <<  ","  <<  l  <<endl;
    // increment variable j
    j++; 
    // The print should be 11,11,11,11
    cout<<  i  <<  ","  <<  j  <<  ","  <<  k  <<  ","  <<  l  <<endl;
    // increment variable k
    k++;
    // The print should be 12,12,12,12
    cout<<  i  <<  ","  <<  j  <<  ","  <<  k  <<  ","  <<  l  <<endl;
    // increment variable l
    l++;
    // The print should be 13,13,13,13
    cout<<  i  <<  ","  <<  j  <<  ","  <<  k  <<  ","  <<  l  <<endl;
}


int main() {

    return 0;
}