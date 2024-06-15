/*
 * Given a sequence of integers, 
 * return the sum of all the integers that have an even index, 
 * multiplied by the integer at the last index.
 *
 * Indices in sequence start from 0.
 * If the sequence is empty, you should return 0.
 */
#include <vector>

int even_last(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    
    return sum * nums.back();
}

// ALTERNATIVE
#include <vector>

int even_last(const std::vector<int>& nums) {
    int sum = 0;
    for(auto it = nums.cbegin(); it < nums.cend(); it += 2) sum += *it;
    return nums.empty() ? 0 : nums.back() * sum;
}
