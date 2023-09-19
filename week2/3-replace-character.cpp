#include <cstdlib>
#include <iostream>
#include <fstream>

/*! \brief Print a file to STDOUT
 *  \param file_name File to print
 *  \return Whether successfully printed
 */
bool print_file(const std::string& file_name);

int main(int argc, char** argv) {
    const bool okay = print_file("../LICENSE");

    std::cout << okay << std::endl;
    return EXIT_SUCCESS;
}

bool print_file(const std::string& file_name) {
    std::ifstream in_file(file_name);
    
    if (!in_file.is_open()) {
        return false;
    }

    char c;
    while (!in_file.eof()) {
        c = in_file.get();

        switch (c) {
        case 'e':
            c = '3';
            break;
            
        case 'i':
            c = '1';
            break;

        case 'o':
            c = '0';
            break;

        case 's':
            c = '5';
            break;

        default:
            break;
        }

        std::cout << c;
    }

    in_file.close();
    return true;
}
