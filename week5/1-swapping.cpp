#include <cstdlib>
#include <iostream>

/*! \brief Swap numbers */
void swap(int& a, int& b);

int main(int argc, char** argv) {
    int x = 4;
    int y = 2;

    std::cout << "x: " << x << ", y: " << y << std::endl;
    
    swap(x, y);
    std::cout << "x: " << x << ", y: " << y << std::endl;

    return EXIT_SUCCESS;
}

void swap(int& a, int& b) {
    const int c = b;
    b = a;
    a = c;
}
