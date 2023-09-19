#include <cstdlib>
#include <iostream>

/*! \brief Print hello world to the screen
 *  \param times How many times to print
 */
void print_hello(int times = 1);

int main(int argc, char** argv) {
    print_hello(5);
    return EXIT_SUCCESS;
}

void print_hello(int times) {
    while (times--) {
        std::cout << "Hello, World!\n";
    }
}
