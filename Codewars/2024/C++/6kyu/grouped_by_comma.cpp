#include <string>
#include <algorithm>

/**
 * @brief Groups an integer by commas every three digits
 *
 * This function takes an integer and returns a string representation
 * of that number with commas inserted every three digits from right to left.
 *
 * @param n The input integer to be grouped
 * @return std::string The comma-separated string representation of the input
 *
 * @pre 0 <= n < 2147483647
 */
std::string group_by_commas(int n)
{
    std::string result = std::to_string(n);
    int length = result.length();
    
    for (int i = length - 3; i > 0; i -= 3) {
        result.insert(i, ",");
    }
    
    return result;
}
