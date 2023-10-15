#include <iostream>
#include <cstdlib>
#include <cstring>

char* concat(const char a[], const char b[]);

int main(int argc, char** argv) {
    char* joined = concat("test", "abcd");

    std::cout << joined << std::endl;

    delete joined;
    return EXIT_SUCCESS;
}

char* concat(const char a[], const char b[]) {
    const int len_a = strlen(a),
              len_b = strlen(b);

    const int str_length = len_a + len_b + 1; // Include \0

    char* const c = new char[str_length];
    memcpy(c, a, len_a);
    strcpy(c + len_a, b); // Appends \0

    return c;
}
