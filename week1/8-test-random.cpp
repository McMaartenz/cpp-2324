#include <cstdlib>
#include <iostream>
#include <ctime>

/*! \brief Generate a random number between \a min and \a max
 *  \param min Min number to generate
 *  \param max Max number to generate
 *  \exception Fails if \a min >= \a max
 *  \return A random number between the bounds
 */
int random(int min, int max);

/*! \brief Run tests
 *  \return Whether all test runs were successful
 */
bool run_tests(void);

int main(int argc, char** argv) {
    srand(time(NULL));

    const bool success = run_tests();
    std::cout << "Success: " << success << std::endl;
    return EXIT_SUCCESS;
}

int random(int min, int max) {
    if (min >= max) {
        std::cout << "Invalid minimum, maximum\n";
        return 0;
    }

    int n = min + rand() % (max + 1 - min);
    return n;
}

bool run_tests(void) {
    int min, max, received, iterations = 100;
    while (iterations--) {
        min = rand() % 100;
        max = min + 1 + rand() % 100;

        std::cout << "Expected range [" << min << ".." << max << "] ... ";
        received = random(min, max);

        if (received < min || received > max) {
            std::cout << "FAIL: " << received << std::endl;
            return false;
        }

        std::cout << "OK\n";
    }

    return true;
}
