#include <cstdlib>
#include <iostream>

/*! \brief Make a triangle of given \a size size 
 *  \param size Size of triangle to produce
 *  \return Pointer to a triangle. Caller frees
 */
int** make_triangle(size_t size);

/*! \brief Print a triangle to STDOUT
 *  \param triangle Triangle to print
 *  \param size Size of triangle
 */
void print_triangle(const int** triangle, size_t size);

/*! \brief Free a triangle. Does nothing on nullptr
 *  \param triangle Triangle to free, set to nullptr after
 *  \param size Size of triangle
 */
void clear_triangle(int**& triangle, size_t size);

int main(int argc, char** argv) {
    int** triangle = make_triangle(8);
    print_triangle(const_cast<const int**>(triangle), 8);

    clear_triangle(triangle, 8);
    return EXIT_SUCCESS;
}

int** make_triangle(size_t size) {
    int** const triangle = new int*[size];
    for (size_t layer = 0; layer < size; layer++) {
        int*& current_slice = triangle[layer];
        current_slice = new int[layer + 1];
        current_slice[0] = 1;
        current_slice[layer] = 1;

        const int* const previous_slice = triangle[layer - 1];
        for (size_t i = 1; i < layer; i++) {
            current_slice[i] = previous_slice[i - 1] + previous_slice[i];            
        }
    }

    return triangle;
}

void print_triangle(const int** triangle, size_t size) {
    for (size_t layer = 0; layer < size; layer++) {
        for (size_t i = 0; i < (layer + 1); i++) {
            std::cout << triangle[layer][i] << " ";
        }

        std::cout << std::endl;
    }
}

void clear_triangle(int**& triangle, size_t size) {
    if (!triangle) {
        return;
    }

    for (size_t layer = 0; layer < size; layer++) {
        delete[] triangle[layer];
    }

    delete[] triangle;
    triangle = nullptr;
}
