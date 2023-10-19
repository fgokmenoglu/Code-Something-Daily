/*
 * Your task is to sum the differences between consecutive pairs in the array in descending order.
 * 
 * Example
 * [2, 1, 10]  -->  9
 * In descending order: [10, 2, 1]
 * 
 * Sum: (10 - 2) + (2 - 1) = 8 + 1 = 9
 * 
 * If the array is empty or the array has only one element the result should be 0
 */
#include <vector>
#include <functional> // greater<int>()

int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty())
    return 0;
  
  int sum = 0; 
  std::vector<int> temp = arr;
  sort(temp.begin(), temp.end(), std::greater<int>());
  
  for(size_t i = 0; i < temp.size() - 1; i++)
    sum += temp[i] - temp[i + 1];    
    
  return sum;
}

// ALTERNATIVE
#include <vector>
#include <algorithm> // minmax_element

int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  
  auto p = std::minmax_element(arr.cbegin(), arr.cend());
  
  return *p.second - *p.first;
}
