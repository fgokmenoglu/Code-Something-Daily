/*
 * Your task is to rotate a matrix 90 degree to the left. 
 * The matrix is an array of integers with dimension n,m.
 *
 * Example:
 * Input: {{-1, 4, 5},
 *         {2, 3, 4}}
 * Output: {{5, 4},
 *          {4, 3},
 *          {-1, 2}}
 */
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> rotateMatrixLeft(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return {};
    }

    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Create a new matrix with swapped dimensions
    std::vector<std::vector<int>> rotated(m, std::vector<int>(n));

    // Transpose and reverse
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rotated[m - 1 - j][i] = matrix[i][j];
        }
    }

    return rotated;
}
