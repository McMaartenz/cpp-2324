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

/*! \brief Clear bits at position \a pos_a and \a pos_b
 *  \param input Byte to read
 *  \param pos_a First bit position
 *  \param pos_b Second bit position
 *  \return Modified byte with specified bits cleared
 */
uint8_t clear_bits(uint8_t input, int pos_a, int pos_b);

/*! \brief Swap bits at position \a pos_a and \a pos_b if bit at position \a pos_c is high
 *  \param input Byte to read
 *  \param pos_a First bit position
 *  \param pos_b Second bit position
 *  \param pos_c Checking bit position
 *  \return Modified or unmodified byte depending on checking bit
 */
uint8_t conditional_swap(uint8_t input, int pos_a, int pos_b, int pos_c);

int main(int argc, char** argv) {
    std::cout << (int)conditional_swap(0b0000'0010, 2, 1, 0) << std::endl;
    std::cout << (int)conditional_swap(0b0000'0011, 2, 1, 0) << std::endl;
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

uint8_t clear_bits(uint8_t input, int pos_a, int pos_b) {
    return input & ~((1 << pos_a) | (1 << pos_b));
}

uint8_t conditional_swap(uint8_t input, int pos_a, int pos_b, int pos_c) {
    if (get_bit(input, pos_c)) {
        const bool a = get_bit(input, pos_a);
        const bool b = get_bit(input, pos_b);
        
        input = clear_bits(input, pos_a, pos_b);
        input |= (a << pos_b) | (b << pos_a);
    }

    return input;
}
