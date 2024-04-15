/*
 * In this Kata, you will be given an array of arrays and 
 * your task will be to return the number of unique arrays that 
 * can be formed by picking exactly one element from each subarray.
 *
 * For example: solve([[1,2],[4],[5,6]]) = 4, 
 * because it results in only 4 possibilites. 
 * They are [1,4,5],[1,4,6],[2,4,5],[2,4,6].
 *
 * Make sure that you don't count duplicates; 
 * for example solve([[1,2],[4,4],[5,6,6]]) = 4, 
 * since the extra outcomes are just duplicates.
 */
#include <vector>
#include <unordered_set>

int solve(const std::vector<std::vector<int>> &data) {
    // To store the number of unique combinations
    int num_combinations = 1;
    
    // Iterate through each subarray in the given data
    for (const auto &subarray : data) {
        // Use a set to remove duplicate elements
        std::unordered_set<int> unique_elements(subarray.begin(), subarray.end());
        
        // Multiply the number of unique elements in each subarray to get the total combinations
        num_combinations *= unique_elements.size();
    }
    
    // Return the total number of unique combinations
    return num_combinations;
}

// ALTERNATIVE
#include <functional>
#include <numeric>
#include <unordered_set>
#include <vector>

int solve(const std::vector<std::vector<int>>& data) {
  return std::transform_reduce(data.cbegin(), data.cend(), 1, std::multiplies(), [](const auto& xs) {
    return std::unordered_set<int>(xs.cbegin(), xs.cend()).size();
  });
}
