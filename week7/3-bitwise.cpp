#include <iostream>
#include <cstdlib>

int controlegetal(unsigned char input);

int main(int argc, char** argv) {
    std::cout << controlegetal(0x55) << std::endl;
    std::cout << controlegetal(0xFF) << std::endl;
    std::cout << controlegetal(0x96) << std::endl;
    std::cout << controlegetal(0xE2) << std::endl;
    std::cout << controlegetal(0x80) << std::endl;
    std::cout << controlegetal(0x5D) << std::endl;
    return EXIT_SUCCESS;
}

int controlegetal(unsigned char input) {
    int control_number = 0;
    for (int i = 0; i < 8; i++, input >>= 1) {
        control_number += ((i % 2 == 0) ? 1 : -1) * (input & 1);
    }

    return control_number;
}
