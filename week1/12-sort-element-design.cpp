#include <cstdlib>
#include <iostream>

/*! \brief Find max value in the \a array
 *  \param array Array
 *  \param size Size of array
 *  \return Index of largest value in \a array, or -1 if empty.
 */
ssize_t find_max(const int* array, size_t size);

/*! \brief Swap array[a] with array[b]
 *  \param array Array to manipulate
 *  \param a First index
 *  \param b Second index
 *  \exception If either \a a or \a b exceeds array bounds
 */
void swap(int* array, size_t a, size_t b);

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

/*! \brief Sorts provided array
 *  \param array Array to sort
 *  \param size Array size
 *  \return Pointer to a sorted array. Must be freed by caller
 */
int* sort(const int* array, size_t size);

int main(int argc, char** argv) {
    constexpr size_t ARRAY_LENGTH = 4;
    const int array[ARRAY_LENGTH] = {4, 2, 3, 1};

    const int* sorted = sort(array, ARRAY_LENGTH);

    std::cout << "Unsorted array:\n";
    print_array(array, ARRAY_LENGTH);

    std::cout << "Sorted array:\n";
    print_array(sorted, ARRAY_LENGTH);

    delete sorted;
    return EXIT_SUCCESS;
}

int* sort(const int* array, size_t size) {
    int* sorted = new int[size];
    memcpy(sorted, array, sizeof(int)*size);

    ssize_t max_pos;
    for (size_t i = 0; i < size; i++) {
        max_pos = find_max(sorted, size - i);
        swap(sorted, max_pos, size - 1 - i);
    }

    return sorted;
}

ssize_t find_max(const int* array, size_t size) {
    int largest = INT_MIN;
    ssize_t largest_index = -1;

    for (size_t i = 0; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
            largest_index = i;
        }
    }

    return largest_index;
}

void swap(int* array, size_t a, size_t b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void print_array(const int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        print_entry(i, array[i]);
    }
}

void print_entry(size_t index, int value) {
    std::cout << index << ": " << value << std::endl;
}
