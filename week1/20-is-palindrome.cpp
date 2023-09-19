#include <cstdlib>
#include <iostream>

/*! \brief Determine length of C-string
 *  \param string C-string
 *  \return Length of \a string
 */
size_t length(const char* string);

/*! \brief Check whether string is a palindrome
 *  \param string C-style string
 *  \return Whether the string is a palindrome
 */
bool is_palindrome(const char* string);

int main(int argc, char** argv) {
    const char* palindrome = "meetsysteem";
    const char* racecar = "racecar";
    const char* nascar = "nascar";

    bool x = is_palindrome(palindrome);
    std::cout << x << std::endl;
    
    x = is_palindrome(racecar);
    std::cout << x << std::endl;

    x = is_palindrome(nascar);
    std::cout << x << std::endl;

    return EXIT_SUCCESS;
}

bool is_palindrome(const char* string) {
    size_t size = length(string);
    const char* reverse = string + size;

    while (*(string++) == *(--reverse) && --size);
    return !size;
}

size_t length(const char* string) {
    size_t size = 0;

    while (string[size]) { size++; }
    return size;
}
