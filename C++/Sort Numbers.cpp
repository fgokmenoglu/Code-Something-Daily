/*
 * Finish the solution so that it sorts the passed in array of numbers. If the function passes in an empty array or null/nil value then it should return an empty array.
 * 
 * For example:
 * 
 * sortNumbers({1, 2, 10, 50, 5}) // sholud return {1, 2, 5, 10, 50}
 * sortNumbers({}) // should return {}
 */
#include <vector>

std::vector<int> solution(std::vector<int> nums) 
{
  std::sort(nums.begin(), nums.end());
  
  return nums;
}
