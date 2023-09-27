#include <cstdlib>
#include <iostream>

/*! \brief Dynamically create an array of size \a size
 *  \param size Size of array
 *  \return Pointer to new array. Caller frees
 */
int* create_arr(size_t size);

/*! \brief Print an array to STDOUT
 *  \param arr Array to print
 *  \param size Array size
 */
void print_arr(int* arr, size_t size);

int main(int argc, char** argv) {
    size_t n;
    std::cout << "Enter array length: ";
    std::cin >> n;

    int* arr = create_arr(n);
    print_arr(arr, n);
    
    delete[] arr;
    return EXIT_SUCCESS;
}

int* create_arr(size_t size) {    
    int* const arr = new int[size];
    for (size_t i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    return arr;
}

void print_arr(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
