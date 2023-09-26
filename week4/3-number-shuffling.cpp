#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
    int a, b, tmp;
    int *p, *q;

    a = 4;
    b = 2;

    p = &a;
    q = &tmp;

    *q = *p; // tmp = a
    
    q = &b; 
    *p = *q; // a = b

    p = &tmp;
    *q = *p; // b = tmp

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return EXIT_SUCCESS;
}
