#include <cstdlib>
#include <iostream>

/*! \brief Get most significant bit
 *  \param input Byte to read
 *  \return Whether bit is high
 */
bool get_MSB(uint8_t input);

int main(int argc, char** argv) {
    std::cout << get_MSB(128);
    std::cout << get_MSB(127);
    return EXIT_SUCCESS;
}

bool get_MSB(uint8_t input) {
    return input & 0b1000'0000;
}
