#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

/*! \brief Print the added sum of the file's digits to STDOUT
 *  \param file_name File to print
 *  \return Whether successfully printed
 */
bool print_add_digits_file(const std::string& file_name);

/*! \brief Convert a string to an integer
 *  \param string C-style string
 *  \return The number
 */
int make_number(const std::string& string);

int main(int argc, char** argv) {
    const bool okay = print_add_digits_file("../LICENSE");

    std::cout << okay << std::endl;
    return EXIT_SUCCESS;
}

bool print_add_digits_file(const std::string& file_name) {
    std::ifstream in_file(file_name);
    
    if (!in_file.is_open()) {
        return false;
    }

    char c;
    size_t sum = 0;
    
    std::ostringstream oss;
    while (!in_file.eof()) {
        c = in_file.get();

        if (c >= '0' && c <= '9' || c == '-' && !oss.tellp()) {
            oss << c;
        }
        else if (oss.tellp() > 0) {
            const int n = make_number(oss.str());
            oss.str("");
            oss.clear();

            sum += n;
        }
    }

    if (oss.tellp() > 0) {
        const int n = make_number(oss.str());
        sum += n;
    }

    std::cout << sum << std::endl;

    in_file.close();
    return true;
}

int make_number(const std::string& string) {
    int n;
    std::istringstream iss(string);
    
    iss >> n;
    return n;
}
