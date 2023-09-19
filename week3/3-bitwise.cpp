#include <cstdlib>
#include <iostream>

/*! \brief Get most significant bit
 *  \param input Byte to read
 *  \return Whether bit is high
 */
bool get_MSB(uint8_t input);

/*! \brief Get bit at specified \a pos
 *  \param input Byte to read
 *  \param pos Position of bit
 *  \return Whether bit is high
 */
bool get_bit(uint8_t input, size_t pos);

int main(int argc, char** argv) {
    std::cout << get_bit(2, 1);
    std::cout << get_bit(0, 1);
    return EXIT_SUCCESS;
}

bool get_MSB(uint8_t input) {
    return input & 0b1000'0000;
}

bool get_bit(uint8_t input, size_t pos) {
    return input & (1 << pos);
}
