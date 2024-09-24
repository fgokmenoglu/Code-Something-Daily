#include <vector>
#include <ranges>

/**
 * @brief Generates a vector of integers from n to 1 in descending order.
 * 
 * This function takes a positive integer n and returns a vector containing
 * integers from n down to 1 in descending order.
 * 
 * @param n A positive integer representing the starting number.
 * @return std::vector<int> A vector of integers from n to 1 in descending order.
 * 
 * @pre n > 0
 * 
 * @example
 * reverseSeq(5) returns [5, 4, 3, 2, 1]
 */
std::vector<int> reverseSeq(int n) {
    return std::vector<int>(n, 0) | std::views::transform([n](int i) { return n - i; });
}
