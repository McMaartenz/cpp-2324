#include <cstdlib>
#include <iostream>

/*! \brief Swap array[a] with array[b]
 *  \param array Array to manipulate
 *  \param a First index
 *  \param b Second index
 *  \exception If either \a a or \a b exceeds array bounds
 */
void swap(int* array, size_t a, size_t b);

int main(int argc, char** argv) {
    constexpr size_t ARRAY_LENGTH = 4;
    int array[ARRAY_LENGTH] = { 1, 2, 3, 4 };

    swap(array, 2, 3);
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        std::cout << array[i];
    }
    return EXIT_SUCCESS;
}

void swap(int* array, size_t a, size_t b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
