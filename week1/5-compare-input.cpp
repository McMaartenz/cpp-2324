#include <cstdlib>
#include <iostream>

/*! \brief Return minimum of provided arguments
 *  \param a A number
 *  \param b A number
 *  \return Lowest of a, b
 */
int min(int a, int b);

/*! \brief Return a number from STDIN 
 *  \return Entered integer
 */
int number(void);

int main(int argc, char** argv) {
    const int a = number(),
              b = number();

    const int n = min(a, b);
    std::cout << "Minimum of a, b: " << n << std::endl;
    return EXIT_SUCCESS;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int number(void) {
    int n;
    std::cout << "Provide a whole number: ";
    std::cin >> n;
    return n;
}
