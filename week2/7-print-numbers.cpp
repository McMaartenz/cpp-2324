#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

/*! \brief Print the numbers of the file's digits to STDOUT
 *  \param file_name File to print
 *  \return Whether successfully printed
 */
bool print_numbers_file(const std::string& file_name);

int main(int argc, char** argv) {
    const bool okay = print_numbers_file("../LICENSE");

    std::cout << okay << std::endl;
    return EXIT_SUCCESS;
}

bool print_numbers_file(const std::string& file_name) {
    std::ifstream in_file(file_name);
    
    if (!in_file.is_open()) {
        return false;
    }

    char c;
    
    std::ostringstream oss;
    while (!in_file.eof()) {
        c = in_file.get();

        if (c >= '0' && c <= '9') {
            oss << c;
        }
        else if (oss.tellp() > 0) {
            std::cout << oss.str() << std::endl;
            oss.str("");
            oss.clear();
        }
    }

    if (oss.tellp() > 0) {
        std::cout << oss.str() << std::endl;
    }

    in_file.close();
    return true;
}
