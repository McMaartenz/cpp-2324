#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

/*! \brief Print the added floating points to STDOUT
 *  \param file_name File to print
 *  \return Whether successfully printed
 */
bool print_add_floats_file(const std::string& file_name);

/*! \brief Convert a string to an integer
 *  \param string C-style string
 *  \return The number
 */
int make_number(const std::string& string);

/*! \brief Convert a string to a float
 *  \param string C-style string
 *  \return The decimal
 */
float make_float(const std::string& string);

int main(int argc, char** argv) {
    const bool okay = print_add_floats_file("../LICENSE");

    std::cout << okay << std::endl;
    return EXIT_SUCCESS;
}

bool print_add_floats_file(const std::string& file_name) {
    std::ifstream in_file(file_name);
    
    if (!in_file.is_open()) {
        return false;
    }

    char c;
    float sum = 0;
    bool floating_point = false;
    
    std::ostringstream oss;
    while (!in_file.eof()) {
        c = in_file.get();

        if (c >= '0' && c <= '9' || c == '-' && !oss.tellp() || c == '.' && !floating_point) {
            oss << c;

            if (c == '.') {
                floating_point = true;
            }
        }
        else if (oss.tellp() > 0) {
            if (floating_point) {
                const float f = make_float(oss.str());
                sum += f;

                floating_point = false;
            }
            else {
                const int n = make_number(oss.str());
                sum += (float)n;
            }
            oss.str("");
            oss.clear();
        }
    }

    if (oss.tellp() > 0) {
        if (floating_point) {
            const float f = make_float(oss.str());
            sum += f;
        }
        else {
            const int n = make_number(oss.str());
            sum += (float)n;
        }
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

float make_float(const std::string& string) {
    float f;
    std::istringstream iss(string);
    
    iss >> f;
    return f;
}
