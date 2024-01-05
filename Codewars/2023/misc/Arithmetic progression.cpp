/*
 * In your class, you have started lessons about arithmetic progression. 
 * Since you are also a programmer, you have decided to write a function that will return 
 * the first n elements of the sequence with the given common difference d and first element a. 
 * Note that the difference may be zero!
 * 
 * The result should be a string of numbers, separated by comma and space.
 * 
 * Example
 * # first element: 1, difference: 2, how many: 5
 * arithmetic_sequence_elements(1, 2, 5) == "1, 3, 5, 7, 9"
 */
#include <string>

std::string arithmeticSequenceElements(int a, int d, int n) {
  std::string output = "";
  int temp = a;
  
  for (int i = 1; i <= n; i++) {
    output += std::to_string(a) + ", ";
    a += d;
  }
  
  output.pop_back();
  output.pop_back();
  
  return output;
}

// ALTERNATIVE
#include <string>

std::string arithmeticSequenceElements(int a, int d, int n) {
  std::string result = std::to_string(a);
  
  for (int i = 1; i < n; i++)
    result += ", " + std::to_string(a + i * d);
  
  return result;
}
