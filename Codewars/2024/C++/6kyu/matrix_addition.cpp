#include <vector>

/**
 * @brief Performs addition of two square matrices.
 * 
 * This function accepts two square matrices (N x N two-dimensional arrays) and
 * returns their sum. Both input matrices must be of the same size N x N and
 * contain only integers.
 * 
 * @param a The first input matrix.
 * @param b The second input matrix.
 * @return std::vector<std::vector<int>> The resulting matrix after addition.
 * 
 * @note The addition is performed element-wise: each cell [n][m] of the result
 *       is the sum of cell [n][m] from matrix 'a' and cell [n][m] from matrix 'b'.
 */
std::vector<std::vector<int>> matrixAddition(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b) {
    int N = a.size(); // Size of the square matrix
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    
    return result;
}
