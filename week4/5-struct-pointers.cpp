#include <cstdlib>
#include <iostream>

/*! \brief A thing.. */
struct thing {
    int i;
    int* p;
};

/*! \brief Print a thing
 *  \param t Thing to print
 */
void print_thing(const thing& t);

int main(int argc, char** argv) {
    thing x;
    x.i = 1;
    x.p = new int{2};

    print_thing(x);

    thing* const px = &x;
    px->i = 5;

    print_thing(*px);

    delete x.p;
    return EXIT_SUCCESS;
}

void print_thing(const thing& t) {
    std::cout << "thing.i: " << t.i << std::endl;
    std::cout << "thing.*p: " << *t.p << std::endl;
}
