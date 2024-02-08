/*
 * In this Kata, you will be given an integer array ... 
 * and your task is to return the sum of elements ...
 * occupying prime-numbered indices.
 *
 * Note: The first element of the array is at index 0.
 */
#include <vector>

bool isPrime(int num) {
  for (int i = 2; i * i <= num; ++i) 
    if (num % i == 0)
      return false;
  
  return true;
}

int solve(std::vector<int> v) {
  int sum = 0;
  
  for (size_t i = 2; i < v.size(); ++i)
    if (isPrime(i))
      sum += v[i];
    
  return sum;
}
