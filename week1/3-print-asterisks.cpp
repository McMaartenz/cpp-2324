#include <cstdlib>
#include <iostream>

/*! \brief Print a square
 *  \param size Square width/height
 */
void print_square(int size);

/*! \brief Print a triangle
 *  \param size Triangle width/height
 */
void print_triangle(int size);

int main(int argc, char** argv) {
    print_square(4);
    print_triangle(4);
    return EXIT_SUCCESS;
}

void print_square(int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void print_triangle(int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c <= r; c++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
