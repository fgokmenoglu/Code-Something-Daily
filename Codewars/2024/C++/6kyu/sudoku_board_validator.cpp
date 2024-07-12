/*
 * Sudoku Solution Validator
 * Write a function that accepts a Sudoku board, and returns true if it is a valid Sudoku solution, or false otherwise. 
 * The cells of the input Sudoku board may also contain 0's, which will represent empty cells. 
 * Boards containing one or more zeroes are considered to be invalid solutions.
 * 
 * Details
 * All inputs are guaranteed to be 2D boards of size 9x9 with possible values in range 0-9.
 * Rows, columns and blocks (3x3 small squares) must contain each number from range 1-9 exactly once.
 * User solution must not modify input boards.
 */
#include <array>
#include <bitset>

bool validate(const std::array<std::array<int, 9>, 9>& board) {
    std::array<std::bitset<9>, 9> rows{}, cols{}, boxes{};

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num = board[i][j];
            if (num == 0) return false;  // 0 is not allowed in a valid solution
            
            --num;  // Adjust to 0-based index for bitset
            int box_index = (i / 3) * 3 + (j / 3);

            // Check if the number is already set in row, column or box
            if (rows[i][num] || cols[j][num] || boxes[box_index][num]) {
                return false;  // Duplicate found
            }

            // Set the bit for this number in row, column and box
            rows[i].set(num);
            cols[j].set(num);
            boxes[box_index].set(num);
        }
    }

    return true;
}
