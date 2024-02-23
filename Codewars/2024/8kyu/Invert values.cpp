/*
 * Given a set of numbers, return the additive inverse of each. Each positive becomes negatives, and the negatives become positives.
 * 
 * invert([1,2,3,4,5]) == [-1,-2,-3,-4,-5]
 * invert([1,-2,3,-4,5]) == [-1,2,-3,4,-5]
 * invert([]) == []
 */
#include <vector>
#include <algorithm>
#include <functional>

std::vector<int> invert(std::vector<int> values) {
    return std::transform(values.begin(), values.end(), values.begin(),
               std::bind(std::multiplies<int>(), std::placeholders::_1, -1));;
}
