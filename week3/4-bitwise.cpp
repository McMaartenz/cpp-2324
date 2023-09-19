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

/*! \brief Clear bits 3, 5
 *  \param input Byte to read
 *  \return Modified byte with bits 3, 5 cleared
 */
uint8_t clear_35(uint8_t input);

int main(int argc, char** argv) {
    std::cout << (int)clear_35(0b1111'1111) << std::endl;
    std::cout << (int)clear_35(0b0001'0100) << std::endl;
    return EXIT_SUCCESS;
}

bool get_MSB(uint8_t input) {
    return input & 0b1000'0000;
}

bool get_bit(uint8_t input, size_t pos) {
    return input & (1 << pos);
}

uint8_t clear_35(uint8_t input) {
    return input & ~((1 << 2) | (1 << 4));
}
