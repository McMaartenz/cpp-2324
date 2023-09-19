#include <cstdlib>
#include <iostream>

/*! \brief Read a number from STDIN
 *  \return Entered integer
 */
int number(void);

int main(int argc, char** argv) {
    const int n = number();

    std::cout << "Entered: " << n << std::endl;
    return EXIT_SUCCESS;
}

int number(void) {
    int n;
    std::cout << "Provide a whole number: ";
    std::cin >> n;
    return n;
}
