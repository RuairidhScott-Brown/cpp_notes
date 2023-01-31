/*
INTRODUCTION to the STD::VECTOR

- handles its own memory management
- does not neet to know the size of the array at declaration
- memory is deallocated as soon as it goes out of scope
- Resizing a vector is expensive.
- length is how many elements are used in the vector.
- capacity is number of elements that can be stored in the array. Elements in memeory.
- vector does not resize based on the .at() method. [] and .at() are based on the
  length of the vector. Not its capacity.


*/

#include<iostream>
#include<vector>

void erasing() {
    std::vector<int> array {1,2,3,4};
    array.erase(array.begin()+1); //erase an element
    array.erase(array.begin()+1, array.begin()+2); //erasing a range
}

void accessing() {
    std::vector<int> array2 = { 9, 7, 5, 3, 1 };
    std::cout << array2.at(1) << '\n'; //has bound checking
    std::cout << array2[1] << '\n'; //does not have bound checking
}

void getting_the_length() {
    std::vector<int> array2 = { 9, 7, 5, 3, 1 };
    std::cout << array2.size() << '\n'; //Returns an unsigned int or size_type
    array2.resize(10); //How to resize the array. New elements are give the value of 0.
    std::cout << array2.capacity() << '\n'; //getting the capacity of the vector
}


void printStack(const std::vector<int>& stack)
{
	for (auto element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}
void vector_as_a_stack() {

    std::vector<int> stack{};

    stack.reserve(5); //changes the capacity to atleast 5.

	printStack(stack);

	stack.push_back(5); // push_back() pushes an element on the stack, it will resize the vector. Can allocate more space than is needed
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n'; // back() returns the last element

	stack.pop_back(); // pop_back() pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);


}

int main() {
    //INITIALISATION
    std::vector<int> array;
    std::vector<int> array2 = { 9, 7, 5, 3, 1 }; 
    std::vector<int> array3 { 9, 7, 5, 3, 1 };
    std::vector<int> array4(5);

    //INITIALISATION C++17
    std::vector<int> array4 { 9, 7, 5, 3, 1 };

    //CHANGING THE SIZE OF A VECTOR
    array = { 0, 1, 2, 3, 4 }; 
    array = { 9, 8, 7 }; 

    return 0;
}