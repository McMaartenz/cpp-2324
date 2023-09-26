#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
    int a = 42;
    int* const p = &a;
    
    std::cout << "Value of *p: " << *p << std::endl;

    *p = 1337;

    std::cout << "Value of a: " << a << std::endl;
    return EXIT_SUCCESS;
}
