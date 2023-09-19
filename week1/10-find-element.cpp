#include <cstdlib>
#include <iostream>

/*! \brief Find \a target in the \a array
 *  \param array Haystack
 *  \param size Size of haystack
 *  \param target Needle to find in \a array
 *  \return Index of \a target in \a array, or -1 on failure
 */
ssize_t find(const int* array, size_t size, int target);

/*! \brief Find max value in the \a array
 *  \param array Array
 *  \param size Size of array
 *  \return Index of largest value in \a array, or -1 if empty.
 */
ssize_t find_max(const int* array, size_t size);

int main(int argc, char** argv) {
    constexpr size_t ARRAY_LENGTH = 4;
    const int array[ARRAY_LENGTH] = { 42, 64, 48, 32 };

    ssize_t index = find(array, ARRAY_LENGTH, 48);
    std::cout << "Position: " << index << std::endl;

    index = find_max(array, ARRAY_LENGTH);
    std::cout << "Max: " << index << std::endl;

    index = find_max({}, 0);
    std::cout << "Max: " << index << std::endl;
    return EXIT_SUCCESS;
}

ssize_t find(const int* array, size_t size, int target) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }

    return -1;
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
