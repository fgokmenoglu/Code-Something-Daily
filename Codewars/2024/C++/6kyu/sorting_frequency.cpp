#include <vector>
#include <unordered_map>
#include <algorithm>

/* Code Description:
 * In this kata, you will sort elements in an array by decreasing frequency of elements.
 * If two elements have the same frequency, sort them by increasing value.
 *
 * solve([2,3,5,3,7,9,5,3,7]) = [3,3,3,5,5,7,7,2,9]
 * -- We sort by highest frequency to lowest frequency.
 * -- If two elements have same frequency, we sort by increasing value.
 */

std::vector<int> solve(const std::vector<int> &vec) {
    // Step 1: Count the frequency of each element
    std::unordered_map<int, int> frequency;
    for (int num : vec) {
        frequency[num]++;
    }
    
    // Step 2: Create a copy of the input vector to sort
    std::vector<int> result = vec;
    
    // Step 3: Define the custom sorting function
    auto compareFunction = [&frequency](int a, int b) {
        if (frequency[a] != frequency[b]) {
            // Sort by decreasing frequency
            return frequency[a] > frequency[b];
        } else {
            // If frequencies are equal, sort by increasing value
            return a < b;
        }
    };
    
    // Step 4: Sort the result vector using the custom sorting function
    std::sort(result.begin(), result.end(), compareFunction);
    
    return result;
}
