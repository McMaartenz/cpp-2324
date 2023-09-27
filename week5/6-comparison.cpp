#include <cstdlib>
#include <iostream>

#define print_a_b std::cout << "a: " << a << ", b: " << b << std::endl

/*! \brief Compare a, and b. Set them according to compare result 
 *  \param a Set to 1 if larger than \a b, or 0 if equal
 *  \param b Set to 1 if larger than \a a, or 0 if equal
 */
void cmp(int& a, int& b);

int main(int argc, char** argv) {
    int a = 10, b = 5;
    print_a_b;

    cmp(a, b);
    print_a_b;

    a = 5, b = 10;
    print_a_b;

    cmp(a, b);
    print_a_b;

    a = 5, b = 5;
    print_a_b;

    cmp(a, b);
    print_a_b;
    
    return EXIT_SUCCESS;
}

void cmp(int& a, int& b) {
    if (a > b) {
        a = 1;
        b = 0;
    }
    else if (b > a) {
        b = 1;
        a = 0;
    }
    else {
        a = 0;
        b = 0;
    }
}
