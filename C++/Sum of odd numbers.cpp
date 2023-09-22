/*
 * Given the triangle of consecutive odd numbers:
 * 
 *              1
 *           3     5
 *        7     9    11
 *    13    15    17    19
 * 21    23    25    27    29
 * ...
 * Calculate the sum of the numbers in the nth row of this triangle (starting at index 1) e.g.: (Input --> Output)
 * 
 * 1 -->  1
 * 2 --> 3 + 5 = 8
 */
#include <vector>
#include <numeric>

long long rowSumOddNumbers(unsigned int n){
  std::vector<int> result = {};
  int element = n * n - n + 1;
  
  for (unsigned int i = 1; i <= n; i++)
  {    
    result.push_back(element);
    element += 2;
  }
  
  return std::accumulate(result.begin(), result.end(), 0);
}
