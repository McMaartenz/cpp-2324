#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
    int *p1 = new int,
        *p2 = new int,
        *p3;

    *p1 = 4;
    *p2 = 2;

    p3 = p1;
    p1 = p2;
    p2 = p3;

    std::cout << "*p1: " << *p1 << std::endl;
    std::cout << "*p2: " << *p2 << std::endl;

    delete p1;
    delete p2;

    return EXIT_SUCCESS;
}
