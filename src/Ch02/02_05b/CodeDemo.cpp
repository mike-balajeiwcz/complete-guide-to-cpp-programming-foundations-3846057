// Complete Guide to C++ Programming Foundations
// Exercise 02_05
// Using Variables, by Eduardo Corpeño 

#include <iostream>

// global scope

int a, b = 5;

int main(){
    //local scope (local to main)
    bool my_flag;

    a = 7;
    my_flag = false;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "my_flag = " << my_flag << std::endl;

    unsigned int positive;
    positive = b - a;

    std::cout << "negative in unsigned int: " << positive << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
