/*
 * Given a non-negative integer, return an array or a list of the individual digits in order.
 *
 * Examples:
 * 123 => {1,2,3}
 * 1 => {1}
 * 8675309 => {8,6,7,5,3,0,9}
 */
#include <vector>
#include <algorithm>

std::vector<int> digitize(int n) {
  if (n == 0)
    return {0};
  
  std::vector<int> out = {};

  while (n > 0) {
    out.push_back(n % 10);
    n /= 10;
  }

  std::reverse(out.begin(), out.end());
  return out;
}

// ALTERNATIVE
#include <vector>

std::vector<int> digitize(int n) {
  std::vector<int> result;
  for (auto num : std::to_string(n)) {
    result.push_back(num - '0');
  }
  return result;
}
