#include <cstdlib>
#include <iostream>

//! \brief Size of bits we are using
constexpr size_t BITS_SIZE = 64;

//! \brief Rule sets
enum RuleSets {
    RULE_30 = 0b0001'1110,
    RULE_90 = 0b0101'1010,
    RULE_110 = 0b0110'1110,
    RULE_184 = 0b1011'1000,
};

/*! \brief Current life state */
struct State {
    uint64_t playfield;
    uint8_t rule_set; //!< Stephen Wolfram's binary-decimal notation
};

/*! \brief Print current generation
 *  \param state State to read
 */
void print_generation(const State& state);

/*! \brief Generate next generation
 *  \param state State to read
 *  \return Updated state
 */
State next_generation(const State& state);

/*! \brief Get bit at position
 *  \param value Value to use
 *  \param pos Bit position
 *  \return Whether bit is high
 */
bool get_bit(uint64_t value, size_t pos);

int main(int argc, char** argv) {
    State state;
    state.playfield = (uint64_t)1 << 32;
    state.rule_set = RULE_30;

    int x = 25;
    while (x--) {
        print_generation(state);
        state = next_generation(state);
    }

    return EXIT_SUCCESS;
}

void print_generation(const State& state) {
    for (size_t i = 0; i < BITS_SIZE; i++) {
        const bool alive = get_bit(state.playfield, BITS_SIZE - 1 - i);
        std::cout << (alive ? 'O' : '.');
    }

    std::cout << std::endl;
}

State next_generation(const State& state) {
    State next;
    next.playfield = 0;
    next.rule_set = state.rule_set;

    // Exclude boundaries
    for (size_t i = 1; i < BITS_SIZE - 1; i++) {
        const bool
            a = get_bit(state.playfield, BITS_SIZE - i + 1),
            b = get_bit(state.playfield, BITS_SIZE - i),
            c = get_bit(state.playfield, BITS_SIZE - i - 1);

        const int n = (a << 2) | (b << 1) | c;
        if (get_bit(state.rule_set, n)) {
            next.playfield |= ((uint64_t)1 << (BITS_SIZE - i));
        }
    }

    return next;
}

bool get_bit(uint64_t value, size_t pos) {
    return value & ((uint64_t)1 << pos);
}
