#include <cstdlib>
#include <iostream>

/*! \brief Divides a by b and puts result in d
 *  \param d Division result
 *  \param a First number
 *  \param b Second number
 *  \return Whether successfully divided
 */
bool divide(double& d, double a, double b);

int main(int argc, char** argv) {
    double result = 0.0;
    if (divide(result, 5, 10)) {
        std::cout << "Result: " << result << std::endl;
    }
    else {
        std::cout << "Something went wrong\n";
    }

    if (divide(result, 5, 0)) {
        std::cout << "Result: " << result << std::endl;
    }
    else {
        std::cout << "Something went wrong\n";
    }

    return EXIT_SUCCESS;
}

bool divide(double& d, double a, double b) {
    if (!b) { return false; }
    
    d = a / b;
    return true;
}
