#include <cstdlib>
#include <iostream>

/*! \brief Compare two strings
 *  \param a First string
 *  \param b Second string
 *  \return Whether strings are equal
 */
bool compare(const char* a, const char* b);

int main(int argc, char** argv) {
    const char* a = "Hello, World!\n";
    const char* b = "hello world";

    std::cout << compare(a, a) << std::endl;
    std::cout << compare(a, b) << std::endl;
    std::cout << compare(b, a) << std::endl;
    std::cout << compare(b, b) << std::endl;
    return EXIT_SUCCESS;
}

bool compare(const char* a, const char* b) {
    while (*a == *(b++)) {
        if (*(a++) == '\0') {
            return true;
        }
    }

    return false;
}
