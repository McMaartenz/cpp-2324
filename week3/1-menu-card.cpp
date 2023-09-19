#include <cstdlib>
#include <iostream>
#include <fstream>

void read_menu_item(std::ifstream& file);

int main(int argc, char** argv) {
    std::ifstream file("./text/menu.txt");
    if (!file.is_open()) {
        std::cout << "Could not open file\n";
        return EXIT_FAILURE;
    }

    while (!file.eof()) {
        read_menu_item(file);
    }
    
    file.close();
    return EXIT_SUCCESS;
}

void read_menu_item(std::ifstream& file) {
    std::string line;
    std::getline(file, line);
    std::cout << line << std::endl;
}
