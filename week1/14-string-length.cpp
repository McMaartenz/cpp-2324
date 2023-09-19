#include <cstdlib>
#include <iostream>

/*! \brief Determine length of C-string
 *  \param string C-string
 *  \return Length of \a string
 */
size_t length(const char* string);

int main(int argc, char** argv) {
    std::cout << "Length: " << length("Hi\n") << std::endl;

    constexpr size_t ARRAY_LENGTH = 3;
    const char* strings[ARRAY_LENGTH] = {
        "Nothing better than C",
        "But wow",
        "Ever heard of HolyC?"
    };

    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        std::cout << "Length of string '" << strings[i] << "': " << length(strings[i]) << std::endl;
    }

    return EXIT_SUCCESS;
}

size_t length(const char* string) {
    size_t size = 0;

    while (string[size]) { size++; }
    return size;
}
