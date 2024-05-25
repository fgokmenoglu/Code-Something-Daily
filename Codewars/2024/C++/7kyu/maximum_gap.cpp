/*
 * Given an array/list [] of integers, 
 * find the maximum difference between the  
 * successive elements in its sorted form. 
 *
 * Notes
 * Array/list size is at least 3 .
 * Array/list's numbers Will be mixture of positives and negatives also zeros_
 * Repetition of numbers in the array/list could occur.
 * The Maximum Gap is computed Regardless the sign.
 */

#include <vector>
#include <algorithm>

using namespace std;

int maxGap(vector<int> numbers) {
    // Sort the numbers in ascending order
    sort(numbers.begin(), numbers.end());

    // Initialize the maximum gap
    int max_gap = 0;

    // Compute the maximum gap between successive elements
    for (size_t i = 1; i < numbers.size(); ++i) {
        int gap = numbers[i] - numbers[i - 1];
        if (gap > max_gap) {
            max_gap = gap;
        }
    }

    return max_gap;
}

// ALTERNATIVE
int maxGap(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end());
    int result = 0;
  
    for (auto a = numbers.begin(), b = std::next(a); b != numbers.end(); ++a, ++b)
        result = std::max(result, *b - *a);
    
    return result;
}
