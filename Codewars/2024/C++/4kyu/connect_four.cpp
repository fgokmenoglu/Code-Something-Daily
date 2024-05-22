/*
 * You can take a look at wiki description of Connect Four game.
 *
 * The grid is 6 row by 7 columns, those being named from A to G.
 * You will receive a list of strings showing the order of the pieces which dropped in columns:
 *
 * std::vector<std::string> pieces_position_list
 * {
 *   "A_Red",
 *   "B_Yellow",
 *   "A_Red",
 *   "B_Yellow",
 *   "A_Red",
 *   "B_Yellow",
 *   "G_Red",
 *   "B_Yellow"
 * }
 *
 * The list may contain up to 42 moves and shows the order the players are playing.
 * The first player who connects four items of the same color is the winner.
 * You should return "Yellow", "Red" or "Draw" accordingly.
 */
#include <string>
#include <vector>
#include <array>
#include <iostream>

std::string who_is_winner(std::vector<std::string> pieces_position_list) {
    // Initialize the Connect Four board
    std::array<std::array<std::string, 7>, 6> board{};
    
    // Keeps track of the next available row in each column
    std::array<int, 7> column_heights = {0, 0, 0, 0, 0, 0, 0};
    
    // Convert column character to index
    auto column_index = [](char col) -> int {
        return col - 'A';
    };
    
    // Directions for checking four in a row (right, down, down-right, down-left)
    const std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    
    // Check if there is a connect four from the current position
    auto check_winner = [&](int row, int col, const std::string& color) -> bool {
        for (const auto& [dr, dc] : directions) {
            int count = 1;
            // Check in the positive direction
            for (int k = 1; k < 4; ++k) {
                int nr = row + k * dr, nc = col + k * dc;
                if (nr >= 0 && nr < 6 && nc >= 0 && nc < 7 && board[nr][nc] == color) {
                    ++count;
                } else {
                    break;
                }
            }
            // Check in the negative direction
            for (int k = 1; k < 4; ++k) {
                int nr = row - k * dr, nc = col - k * dc;
                if (nr >= 0 && nr < 6 && nc >= 0 && nc < 7 && board[nr][nc] == color) {
                    ++count;
                } else {
                    break;
                }
            }
            // If we have four in a row
            if (count >= 4) {
                return true;
            }
        }
        return false;
    };
    
    // Process each move
    for (const auto& move : pieces_position_list) {
        int col = column_index(move[0]);
        std::string color = move.substr(2);
        
        int row = column_heights[col]++;
        board[row][col] = color;
        
        if (check_winner(row, col, color)) {
            return color;
        }
    }
    
    return "Draw";
}
