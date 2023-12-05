/*
 * Task
 * Given an array/list [] of integers, construct a product array of same size such that prod[i] is equal to the product of all the elements of arr[] except arr[i].
 * 
 * Notes
 * Array/list size is at least 2.
 * Array/list's numbers will be only positives.
 * Repetition of numbers in the array/list could occur.
 */
#include <vector>
#include <numeric> // accumulate
#include <functional> // multiplies<int>

using namespace std; 

vector<int> productArray (vector<int> numbers) {
  vector<int> output = {};
  int temp = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>());
  
  for (size_t i = 0; i < numbers.size(); i++)
    output.push_back(temp / numbers[i]);
  
  return output;
}

// ALTERNATIVE
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> productArray(std::vector<int> numbers) {
  std::vector<int> result(numbers.size());
  int prod = std::accumulate(numbers.begin(), numbers.end(), 1, [](int a, int b) { return a * b; });
  std::transform(numbers.begin(), numbers.end(), result.begin(), [prod](int a) { return prod / a; });
  
  return result;
}
