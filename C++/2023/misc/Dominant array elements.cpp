/*
 * An element in an array is dominant if it is greater than all elements to its right. 
 * You will be given an array and your task will be to return a list of all dominant elements. For example:
 *
 * solve([1,21,4,7,5]) = [21,7,5] because 21, 7 and 5 are greater than elments to their right. 
 * solve([5,4,3,2,1]) = [5,4,3,2,1]
 *
 * Notice that the last element is always included. All numbers will be greater than 0.
 */
#include <vector>
#include <algorithm>

std::vector<int> solve(std::vector<int> array) {
  std::vector<int> output = {};
  
  for (size_t i = 0; i < array.size(); i++) {
    bool dominant = true;
    
    for (size_t j = i + 1; j < array.size(); j++) {
      if (array[j] > array[i])
        dominant = false;
    }
    
    if (dominant)
      if (std::count(output.cbegin(), output.cend(), array[i]) == 0)
        output.push_back(array[i]);
  }
  
  return output;
}

// ALTERNATIVE
#include <algorithm>
#include <vector>

std::vector<int> solve(const std::vector<int>& xs) {
  std::vector<int> res;
  
  for (auto i = xs.crbegin(); i != xs.crend(); ++i)
    if (res.empty() || *i > res.back())
      res.push_back(*i);
  
  std::reverse(res.begin(), res.end());
  
  return res;
}
