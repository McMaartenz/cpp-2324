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

int main(int argc, char** argv) {
    srand(time(NULL));

    std::cout << random(3, 5) << std::endl;
    std::cout << random(5, 5) << std::endl;
    std::cout << random(7, 5) << std::endl;
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
