/*
 * Remove the duplicates from a list of integers, keeping the last ( rightmost ) occurrence of each element.
 * 
 * Example:
 * For input: [3, 4, 4, 3, 6, 3]
 * 
 * remove the 3 at index 0
 * remove the 4 at index 1
 * remove the 3 at index 3
 * Expected output: [4, 6, 3]
 */
#include <vector>
#include <unordered_map>

std::vector<int> solve(std::vector<int> vec) {
    std::unordered_map<int, int> lastOccurrence;
    std::vector<int> result;

    // Traverse the input vector in reverse order
    for (int i = vec.size() - 1; i >= 0; i--) {
        int current = vec[i];

        // Check if we haven't seen this element before
        if (lastOccurrence.find(current) == lastOccurrence.end()) {
            lastOccurrence[current] = 1; 
            result.push_back(current);   // Add the element to the result vector
        }
    }

    // Reverse the result vector to maintain the original order
    std::reverse(result.begin(), result.end());

    return result;
}

// ALTERNATIVE
#include <vector>
#include <unordered_set>

std::vector<int> solve(std::vector<int> vec){    
    std::unordered_set<int> s(vec.rbegin(), vec.rend());
    vec.assign(s.begin(),s.end());
    return vec;
}
