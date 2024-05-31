/*
 * A bird flying high above a mountain range is able to estimate the height of the highest peak.
 * 
 * 
 * Example
 * The birds-eye view
 * ^^^^^^
 *  ^^^^^^^^
 *   ^^^^^^^
 *   ^^^^^
 *   ^^^^^^^^^^^
 *   ^^^^^^
 *   ^^^^
 * The bird-brain calculations
 * 111111
 *  1^^^^111
 *   1^^^^11
 *   1^^^1
 *   1^^^^111111
 *   1^^^11
 *   1111
 * 111111
 *  12222111
 *   12^^211
 *   12^21
 *   12^^2111111
 *   122211
 *   1111
 * 111111
 *  12222111
 *   1233211
 *   12321
 *   12332111111
 *   122211
 *   1111
 * 
 * Height = 3
 */
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

int peak_height(std::vector<std::string>& mountain) {
    int rows = mountain.size();
    if (rows == 0) return 0;
    int cols = mountain[0].size();
    if (cols == 0) return 0;

    std::vector<std::vector<int>> heights(rows, std::vector<int>(cols, 0));
    std::queue<std::pair<int, int>> q;

    // Initialize heights for boundary cells
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (mountain[r][c] == '^' && 
                (r == 0 || c == 0 || r == rows - 1 || c == cols - 1 ||
                 mountain[r-1][c] == ' ' || mountain[r+1][c] == ' ' ||
                 mountain[r][c-1] == ' ' || mountain[r][c+1] == ' ')) {
                heights[r][c] = 1;
                q.push({r, c});
            }
        }
    }

    // Directions for the BFS
    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int height = 1;

    while (!q.empty()) {
        int size = q.size();
        ++height;
        for (int i = 0; i < size; ++i) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mountain[nr][nc] == '^' && heights[nr][nc] == 0) {
                    heights[nr][nc] = height;
                    q.push({nr, nc});
                }
            }
        }
    }

    int maxHeight = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            maxHeight = std::max(maxHeight, heights[r][c]);
        }
    }

    return maxHeight;
}
