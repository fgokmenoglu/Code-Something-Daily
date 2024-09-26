#include <vector>

/**
 * @brief Finds the minimum value in a vector of integers.
 * 
 * This function iterates through the given vector and returns the smallest integer.
 * 
 * @param list A vector of integers to search through.
 * @return The smallest integer in the vector.
 * 
 * @note The function assumes that the input vector is not empty.
 * 
 * Examples:
 *   [4,6,2,1,9,63,-134,566]         -> min = -134
 *   [-52, 56, 30, 29, -54, 0, -110] -> min = -110
 *   [42, 54, 65, 87, 0]             -> min = 0
 *   [5]                             -> min = 5
 */
int min(std::vector<int> list) {
    int min_value = list[0];  // Initialize with the first element
    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i] < min_value) {
            min_value = list[i];
        }
    }
    return min_value;
}

/**
 * @brief Finds the maximum value in a vector of integers.
 * 
 * This function iterates through the given vector and returns the largest integer.
 * 
 * @param list A vector of integers to search through.
 * @return The largest integer in the vector.
 * 
 * @note The function assumes that the input vector is not empty.
 * 
 * Examples:
 *   [4,6,2,1,9,63,-134,566]         -> max = 566
 *   [-52, 56, 30, 29, -54, 0, -110] -> max = 56
 *   [42, 54, 65, 87, 0]             -> max = 87
 *   [5]                             -> max = 5
 */
int max(std::vector<int> list) {
    int max_value = list[0];  // Initialize with the first element
    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i] > max_value) {
            max_value = list[i];
        }
    }
    return max_value;
}
