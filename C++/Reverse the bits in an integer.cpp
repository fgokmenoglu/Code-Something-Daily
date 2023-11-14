/*
 * Write a function that reverses the bits in an integer.
 * 
 * For example, the number 417 is 110100001 in binary. Reversing the binary is 100001011 which is 267.
 * 
 * You can assume that the number is not negative.
 */
#include <vector>
#include <cmath>

unsigned int reverse_bits(unsigned int n) {
  std::vector<int> binaryDigits = {};
  unsigned int output = 0;
  
  while (n > 0) {
    binaryDigits.push_back(n % 2);
    n /= 2;
  }
  
  std::reverse(binaryDigits.begin(), binaryDigits.end());
  
  for (size_t i = 0; i < binaryDigits.size(); i++)
    output += binaryDigits[i] * pow(2, i);  
  
  return output;
}
