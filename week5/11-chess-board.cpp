#include <cstdlib>
#include <iostream>

/*! \brief Make a 2D board of size \a size 
 *  \param size Size of board
 *  \return A 2D board pointer. Caller frees
 */
int** make_board(size_t size);

/*! \brief Print a 2D board to STDOUT 
 *  \param board A 2D board
 *  \param size Size of board
 */
void print_board(const int** board, size_t size);

/*! \brief Free an existing 2D board, or nothing on nullptr
 *  \param board A pointer to a 2D board. Modified to nullptr after
 *  \param size Size of board
 */
void clear_board(int**& board, size_t size);

int main(int argc, char** argv) {
    int** board = make_board(8);

    print_board(const_cast<const int**>(board), 8);
    clear_board(board, 5);
    return EXIT_SUCCESS;
}

int** make_board(size_t size) {
    int** board = new int*[size];
    for (size_t r = 0; r < size; r++) {
        board[r] = new int[size];
        for (size_t c = 0; c < size; c++) {
            board[r][c] = (r + c) % 2 == 0;
        }
    }

    return board;
}

void clear_board(int**& board, size_t size) {
    if (!board) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        delete[] board[i];
    }

    delete[] board;
    board = nullptr;
}

void print_board(const int** board, size_t size) {
    for (size_t r = 0; r < size; r++) {
        for (size_t c = 0; c < size; c++) {
            const int value = board[r][c];
            char x;

            switch (value) {
            case 0: { x = ' '; break; }
            case 1: { x = '#'; break; }
            default:{ x = '?'; break; }
            }

            std::cout << x << x;
        }

        std::cout << std::endl;
    }
}
