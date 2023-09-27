#include <cstdlib>
#include <iostream>

/*! \brief Shift \a byte by \a amount amount 
 *  \param byte Byte to modify
 *  \param amount Amount to shift \a byte by
 */
void shift(uint8_t& byte, size_t amount);

int main(int argc, char** argv) {
    uint8_t b = 24;

    shift(b, 2);

    std::cout << "b: " << (uint32_t)b << std::endl;
    return EXIT_SUCCESS;
}

void shift(uint8_t& byte, size_t amount) {
    byte <<= amount;
}
