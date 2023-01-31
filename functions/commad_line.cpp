/*
COMMAND LINE

ARGC
    - the number of arguments that are passed to the script
    - will always be 1 and the name of the script is counted as
      the first element

ARGV
    is an array of c-style strings that are the arguents passed


*/

#include <iostream>
#include <sstream>
#include <string>

//sometimes (int argc, char** argv)
int main(int argc, const char* argv[]) {

    if (argc <=1) {
        if (argv[0]) {
            std::cout << "Usage: " <<  argv[0] << " <number>" << '\n';
        } else {
            std::cout << "Usage <program name> <number>" << '\n';
        }
        return -1;
    }

    std::stringstream convert {argv[1]}; 

    int my_int {};
    if (!(convert >> my_int)) {
        my_int = 0;
    }
    std::cout << "Got integer: " <<  my_int << '\n';
    return 0;
}