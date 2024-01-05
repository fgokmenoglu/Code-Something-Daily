/*
 * Given an array of numbers, return a new array of length number containing the last even numbers from the original array (in the same order). 
 * The original array will be not empty and will contain at least "number" even numbers.
 * 
 * For example:
 * 
 * ([1, 2, 3, 4, 5, 6, 7, 8, 9], 3) => [4, 6, 8]
 * ([-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26], 2) => [-8, 26]
 * ([6, -25, 3, 7, 5, 5, 7, -3, 23], 1) => [6]
 */
#include <vector>

std::vector<int> evenNumbers(std::vector<int> arr, int n) {
  std::vector<int> output = {};
  std::vector<int> temp = arr;
  int count = 0;
  
  reverse(temp.begin(), temp.end());
  
  for (size_t i = 0; i < temp.size(); ++i)
    if (temp[i] % 2 == 0 && count < n) {
      output.push_back(temp[i]);
      ++count;
    }
  
  reverse(output.begin(), output.end());
  
  return output;
}

// ALTERNATIVE
#include <vector>

std::vector<int> evenNumbers(std::vector<int> arr, int n) {
  std::vector<int> earr(n);
  auto i = arr.rbegin();
  
  while ( n > 0 && i != arr.rend() ) {
    if ( *i % 2 == 0 ) {
      earr[n-1] = *i;
      n -= 1;
    }
    
    i++;
  }
  
  return earr;
}
