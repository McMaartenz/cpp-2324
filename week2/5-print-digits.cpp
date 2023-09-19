#include <cstdlib>
#include <iostream>
#include <fstream>

/*! \brief Print a file to STDOUT only containing the digits
 *  \param file_name File to print
 *  \return Whether successfully printed
 */
bool print_digits_file(const std::string& file_name);

int main(int argc, char** argv) {
    const bool okay = print_digits_file("../LICENSE");

    std::cout << okay << std::endl;
    return EXIT_SUCCESS;
}

bool print_digits_file(const std::string& file_name) {
    std::ifstream in_file(file_name);
    
    if (!in_file.is_open()) {
        return false;
    }

    char c;
    while (!in_file.eof()) {
        c = in_file.get();

        if (c >= '0' && c <= '9') {
            std::cout << c;
        }
    }
    
    in_file.close();
    return true;
}
