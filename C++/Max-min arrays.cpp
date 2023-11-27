/*
 * In this Kata, you will be given an array of unique elements, and your task is to rearrange the values so that the first max value is followed by the first minimum, followed by second max value then second min value, etc.
 * 
 * For example:
 * 
 * solve([15,11,10,7,12]) = [15,7,12,10,11]
 * The first max is 15 and the first min is 7. The second max is 12 and the second min is 10 and so on.
 */
#include <vector>
#include <algorithm>

std::vector<int> solve(std::vector<int> v) {
    std::vector<int> output = {};
    sort(v.begin(), v.end());
    
    size_t i = 0;
    size_t j = v.size() - 1;

    while (i <= j) {
        if (i != j) {
            output.push_back(v[j--]); // Add the max value
            output.push_back(v[i++]); // Add the min value
        } else {
            // If there's an odd number of elements, add the middle element
            output.push_back(v[i]);
            break;
        }
    }
    
    return output;
}

// ALTERNATIVE
#include <algorithm>

using std::max_element;
using std::min_element;
using std::swap;

std::vector<int> solve(std::vector<int> v) {
  for (auto it {v.begin()}; it != v.end(); ++it) {
    swap (*it, *max_element(it, v.end()));
        
    if (++it != v.end()) swap (*it, *min_element(it, v.end()));
  }
    
  return v;
}
