/*
 * Create an identity matrix of the specified size( >= 0).
 * 
 * Some examples:
 * 
 * (1)  =>  [[1]]
 *
 * (2) => [ [1,0],
 *          [0,1] ]
 * 
 *        [ [1,0,0,0,0],
 *          [0,1,0,0,0],
 * (5) =>   [0,0,1,0,0],
 *          [0,0,0,1,0],
 *          [0,0,0,0,1] ]   
 */
#include <vector>

std::vector<std::vector<int>> getMatrix(int n) {
    // Check if n is non-negative
    if (n < 0) {
        // Return an empty matrix if n is negative
        return std::vector<std::vector<int>>();
    }

    // Create a 2D vector initialized with zeros
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    // Fill the diagonal elements with 1s
    for (int i = 0; i < n; ++i) {
        matrix[i][i] = 1;
    }

    return matrix;
}
