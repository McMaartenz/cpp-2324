#include <cstdlib>
#include <iostream>
#include <cmath>

/*! \brief Round a number
 *  \param n Decimal to round
 *  \return Rounded number with 0 precision
 */
int rounded(double n);

int main(int argc, char** argv) {
    std::cout << rounded(5.4998) << std::endl;
    std::cout << rounded(5.5) << std::endl;
    return EXIT_SUCCESS;
}

int rounded(double n) {
    return std::round(n);
}
