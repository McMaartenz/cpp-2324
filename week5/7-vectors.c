#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/*! \brief A vector */
typedef struct {
    int64_t x;
    int64_t y;
} vec;

/*! \brief Print a vector to STDOUT
 *  \param vector Printed vector
 */
void print_vec(const vec* vector);

/*! \brief Add vector \a a with vector \a b and put result in \a sum
 *  \param sum Sum of vectors \a a and \a b
 *  \param a First vector
 *  \param b Second vector
 */
void sum_vec(vec* sum, const vec* a, const vec* b);

/*! \brief Copy a vector from source to destination
 *  \param dest Destination to copy to
 *  \param src Source to copy from
 */
void copy_vec(vec* dest, const vec* src);

int main(int argc, char** argv) {
    vec a = {3, 4};
    vec b = {1, 2};
    vec sum, c;

    print_vec(&a);
    print_vec(&b);

    sum_vec(&sum, &a, &b);
    print_vec(&sum);

    copy_vec(&c, &sum);
    print_vec(&c);
    return EXIT_SUCCESS;
}

void print_vec(const vec* vector) {
    printf("{ x: %lld, y: %lld }\n", vector->x, vector->y);
}

void sum_vec(vec* sum, const vec* a, const vec* b) {
    copy_vec(sum, a);
    sum->x += b->x;
    sum->y += b->y;
}

void copy_vec(vec* dest, const vec* src) {
    *dest = *src;
}
