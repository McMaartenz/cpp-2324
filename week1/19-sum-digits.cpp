#include <cstdlib>
#include <iostream>
#include <tuple>

/*! \brief Get first digit in string, with index
 *  \param string C-style string
 *  \return First digit in \a string with index thereof. If no digit present, index is -1
 */
std::tuple<int, ssize_t> digit(const char* string);

/*! \brief Sum of all digits in string
 *  \param string C-style string
 *  \return The sum of single digits
 *  Numbers like "2014" are parsed as: 2+0+1+4
 */
int sum_digits(const char* string);

int main(int argc, char** argv) {
    const char* expression = "4 + 10 + 1978 = ";
    const char* empty = "hier zit niks in";

    int n = sum_digits(expression);
    std::cout << n << std::endl;

    n = sum_digits(empty);
    std::cout << n << std::endl;

    return EXIT_SUCCESS;
}

int sum_digits(const char* string) {
    size_t index, offset = 0;
    int sum = 0;

    do {
        auto d = digit(string + offset);
        sum += std::get<0>(d);
        index = std::get<1>(d);

        offset += index + 1;
    }
    while (index != -1);

    return sum;
}

std::tuple<int, ssize_t> digit(const char* string) {
    const char* const start = string;
    do {
        if (*string >= '0' && *string <= '9') {
            return {*string - '0', string - start};
        }
    }
    while (*(string++));

    return {0, -1};
}
