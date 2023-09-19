#include <cstdlib>
#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
    std::string
        s1 = "hoi",
        s2 = "patroon",
        s3 = "sleutel",
        s4 = "kaart",
        s5 = "trein",
        s6 = "muziek";

    std::istringstream iss(s1);
    s2 = iss.str();

    std::ostringstream oss;
    oss << s3;
    s4 = oss.str();

    std::stringstream ss(s5);
    s6 = ss.str();

    std::cout
        << s1 << std::endl
        << s2 << std::endl
        << s3 << std::endl
        << s4 << std::endl
        << s5 << std::endl
        << s6 << std::endl;

    return EXIT_SUCCESS;
}
