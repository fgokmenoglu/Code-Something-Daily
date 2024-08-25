#include <utility>
#include <vector>
#include <algorithm>

/* Task Description:
 * Write a function that returns both the minimum and
 * maximum number of the given list/array.
 */

std::pair<int, int> min_max(const std::vector<int>& arr)
{
    if (arr.empty()) {
        throw std::invalid_argument("Vector cannot be empty");
    }
    
    auto [min_it, max_it] = std::minmax_element(arr.begin(), arr.end());
    return {*min_it, *max_it};
}
