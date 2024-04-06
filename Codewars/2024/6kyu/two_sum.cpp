/*
 * Write a function that takes an array of numbers (integers for the tests) and a target number. 
 * It should find two different items in the array that, when added together, give the target value. 
 * The indices of these items should then be returned in a tuple / list (depending on your language) like so: (index1, index2).
 * For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.
 * The input will always be valid (numbers will be an array of length 2 or greater, and all of the items will be numbers; 
 * target will always be the sum of two different items from that array).
 * 
 * two_sum({1, 2, 3}, 4); // returns {0, 2} or {2, 0}
 * two_sum({3, 2, 4}, 6); // returns {1, 2} or {2, 1}
 */
#include <vector>
#include <unordered_map>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    std::unordered_map<int, std::size_t> numMap;  // Map to store the difference and its index

    for (std::size_t i = 0; i < numbers.size(); ++i) {
        auto it = numMap.find(numbers[i]);

        // Check if the current number exists in the map
        if (it != numMap.end()) {
            // Found the pair
            return {it->second, i}; // Return the indices
        }

        // Store the difference and the current index
        numMap[target - numbers[i]] = i;
    }

    return {}; // In case no pair is found (should not happen according to problem statement)
}
