#include <cstdlib>
#include <iostream>

/*! \brief Determine length of C-string
 *  \param string C-string
 *  \return Length of \a string
 */
size_t length(const char* string);

/*! \brief Compare two strings
 *  \param a First string
 *  \param b Second string
 *  \param check_size How long the check should at max be
 *  \return Whether strings are equal
 */
bool compare(const char* a, const char* b, size_t check_size);

/*! \brief Whether \a haystack contains \a needle
 *  \param haystack Search place
 *  \param needle Search target
 *  \return Whether \a needle is inside \a haystack
 */
bool contains(const char* haystack, const char* needle);

int main(int argc, char** argv) {
    const char* haystack = "This is a haystack with a needle somewhere";
    const char* needle = "needle";
    const char* anvil = "anvil";

    std::cout << contains(haystack, needle) << std::endl;
    std::cout << contains(haystack, anvil) << std::endl;
    std::cout << contains(anvil, haystack) << std::endl;
    return EXIT_SUCCESS;
}

bool contains(const char* haystack, const char* needle) {
    const size_t haystack_length = length(haystack);
    const size_t needle_length = length(needle);

    if (needle_length > haystack_length) {
        return false;
    }

    for (size_t i = 0; i < (haystack_length - needle_length); i++) {
        if (compare(haystack + i, needle, needle_length)) {
            return true;
        }
    }

    return false;
}

bool compare(const char* a, const char* b, size_t check_size) {
    while (*a == *(b++)) {
        if (*(a++) == '\0' || !(--check_size)) {
            return true;
        }
    }

    return false;
}

size_t length(const char* string) {
    size_t size = 0;

    while (string[size]) { size++; }
    return size;
}
