/*
CONSTEXPR
    - allows the compiler to run code at compile time instead of runtime.
    - The entire expression becomes constant, and therefore can be known at
      compile time.


*/


#include<iostream>



struct Type {
    constexpr int do_thing() const {return data + 4;}
    constexpr int do_another_thing() const {return data + 6;}
    int data{};
};

constexpr int fact(int n) {
    if (n == 1) {
        return 1;
    }
    return fact(n-1) + fact(n-2);
}



int main() {
    Type obj;
    obj.do_thing();

    int a[fact(4)] {};
    return 0;
}