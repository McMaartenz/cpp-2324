#include <cstdlib>
#include <cstring>
#include <iostream>

/*! \brief Return a concatenated string of a, and b 
 *  \param a C-string
 *  \param b C-string, second half
 *  \return String with a + b concatenated. Caller frees
 */
char* concat(const char* a, const char* b);

int main(int argc, char** argv) {
    const char* result = concat("hello", "world");
    std::cout << "Result: " << result << std::endl;
    
    delete[] result;
    return EXIT_SUCCESS;
}

char* concat(const char* a, const char* b) {
    const size_t length_a = std::strlen(a),
                 length_b = std::strlen(b),
                 length_c = length_a + length_b;

    char* const c = new char[length_c + 1];
    for (size_t i = 0; i < length_a; i++) {
        c[i] = a[i];
        c[i + length_b] = b[i];
    }

    c[length_c] = '\0';
    return c;
}
