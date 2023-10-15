#include <iostream>
#include <cstdlib>

void print_banier(int height, int width);

int main(int argc, char** argv) {
    print_banier(10, 7);    
    return EXIT_SUCCESS;
}

void print_banier(int height, int width) {
    const int diverge_height = height - (width / 2);

    int weight = width / 2, spacing = 1;
    for (int i = 0; i < height; i++) {
        if (i < diverge_height) {
            std::cout << std::string(width, '#') << std::endl;
            continue;
        }

        // Splitted
        const std::string tags = std::string(weight--, '#');
        std::cout << tags << std::string(spacing, ' ') << tags << std::endl;
        spacing += 2;
    }
}
