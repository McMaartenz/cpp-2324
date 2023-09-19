#include <cstdlib>
#include <iostream>

/*! \brief Get first digit in string
 *  \param string C-style string
 *  \return First digit in \a string. If no digit present, returns 0
 */
int digit(const char* string);

int main(int argc, char** argv) {
    const char* string = "Op 4 oktober is het dierendag!";
    const char* string_no_digit = "Dierendag is in oktober";
    
    int n = digit(string);
    std::cout << "Found digit: " << n << std::endl;
    
    n = digit(string_no_digit);
    std::cout << "Found digit: " << n << std::endl;
    return EXIT_SUCCESS;
}

int digit(const char* string) {
    do {
        if (*string >= '0' && *string <= '9') {
            return *string - '0';
        }
    }
    while (*(string++));

    return 0;
}
