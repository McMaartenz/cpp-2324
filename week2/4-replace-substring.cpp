#include <cstdlib>
#include <iostream>
#include <fstream>

/*! \brief Print a file to STDOUT whilst replacing the \a search with \a replace
 *  \param file_name File to print
 *  \param search Substring to search for
 *  \param replace Replacement to replace \a search result
 *  \return Whether successfully printed
 */
bool print_and_replace_file(const std::string& file_name, const std::string& search, const std::string& replace);

int main(int argc, char** argv) {
    const bool okay = print_and_replace_file("../LICENSE", "copyright disclaimer", "non-disclosure agreement");

    std::cout << okay << std::endl;
    return EXIT_SUCCESS;
}

bool print_and_replace_file(const std::string& file_name, const std::string& search, const std::string& replace) {
    std::ifstream in_file(file_name);
    
    if (!in_file.is_open()) {
        return false;
    }

    char c;
    size_t match = 0;
    while (!in_file.eof()) {
        c = in_file.get();

        if (c != search[match]) {
            if (match) {
                for (size_t i = 0; i < match; i++) {
                    std::cout << search[i];
                }
                match = 0;
            }
            else {
                std::cout << c;
                continue;
            }
        }
        else if (++match == search.length()) {
            for (size_t i = 0; i < replace.length(); i++) {
                std::cout << replace[i];
            }
            match = 0;
        }
    }

    if (match > 0) {
        for (size_t i = 0; i < match; i++) {
            std::cout << search[i];
        }
    }

    in_file.close();
    return true;
}
