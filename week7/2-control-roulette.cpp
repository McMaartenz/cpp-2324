#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include <unordered_map>

void controleer_roulette(char* input_file_name, char* output_file_name);

int main(int argc, char** argv) {
    controleer_roulette("invoerfile", "uitvoerfile");

    return EXIT_SUCCESS;
}

void controleer_roulette(char* input_file_name, char* output_file_name) {
    const std::filesystem::path input_path{input_file_name},
                                output_path{output_file_name};

    std::ifstream input_file(input_path);
    std::ofstream output_file(output_path);

    if (!input_file.good() || !output_file.good()) {
        std::cerr << "Unable to access input/output files\n";
        std::abort();
    }

    std::unordered_map<int, int> count{};

    int num;
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);        
        iss >> num;

        count[num]++;
    }

    for (int i = 0; i <= 36; i++) {
        output_file << "Getal " << i << " is " << count[i] << " keer gevallen.\n";
    }
}
