#include <cstdlib>
#include <iostream>

/*! \brief Prints an array
 *  \param array Array to print
 *  \param size Array size
 */
void print_array(const int* array, size_t size);

/*! \brief Pretty print an entry in an array
 *  \param index Index of array
 *  \param value Value at index
 *  \sa print_array
 */
void print_entry(size_t index, int value);

int main(int argc, char** argv) {
    constexpr size_t ARRAY_LENGTH = 20;
    const int array[ARRAY_LENGTH] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};

    print_array(array, ARRAY_LENGTH);
    return EXIT_SUCCESS;
}

void print_array(const int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        print_entry(i, array[i]);
    }
}

void print_entry(size_t index, int value) {
    std::cout << index << ": " << value << std::endl;
}
