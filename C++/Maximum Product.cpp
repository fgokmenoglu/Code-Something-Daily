/*
 * Task
 * Given an array of integers , Find the maximum product obtained from multiplying 2 adjacent numbers in the array.
 */
#include <vector>
#include <numeric>
#include <algorithm>

int adjacentElementsProduct(std::vector<int> in) {
  std::adjacent_difference(in.cbegin(), in.cend(), in.begin(), std::multiplies<int>());
    
  return *std::max_element(std::next(in.cbegin()), in.cend());
}
