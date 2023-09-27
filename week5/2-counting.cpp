#include <cstdlib>
#include <iostream>

/*! \brief Calculate the sum of both numbers
 *  \param s Output sum
 *  \param a First number
 *  \param b Second number
 */
void sum(int& s, int a, int b);

int main(int argc, char** argv) {
    int total;
    sum(total, 5, 10);

    std::cout << "Total: " << total << std::endl;
    return EXIT_SUCCESS;
}

void sum(int& s, int a, int b) {
    s = a + b;
}
