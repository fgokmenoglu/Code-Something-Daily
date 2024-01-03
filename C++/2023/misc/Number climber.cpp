/*
 * For every positive integer N, there exists a unique sequence starting with 1 and ending with N and such that every number in the sequence is either the double of the preceeding number or the double plus 1.
 *
 * For example, given N = 13, the sequence is [1, 3, 6, 13], because . . . :
 *
 * 3 =  2*1 +1
 * 6 =  2*3
 * 13 = 2*6 +1
 * Write a function that returns this sequence given a number N. 
 * Try generating the elements of the resulting list in ascending order, i.e., without resorting to a list reversal or prependig the elements to a list.
 */
#include <vector>

std::vector<int> climb(int n) {
    std::vector<int> sequence;
    
    // Start from n and work backwards
    while (n > 1) {
        sequence.push_back(n);
        // If n is odd, subtract 1 and divide by 2
        // If n is even, just divide by 2
        n = (n % 2) ? (n - 1) / 2 : n / 2;
    }

    // Add the starting element
    sequence.push_back(1);

    // Reverse the sequence to get it in ascending order
    std::reverse(sequence.begin(), sequence.end());
    
    return sequence;
}

// ALTERNATIVE
#include <vector>
#include <cmath>

std::vector<int> climb(int n) {
  int x, msb;
  int idx = 0;
  std::vector<int> l;

  // Get index of most significant bit
  for (x = n, msb = 0; x != 1; x >>= 1, msb++);

  l.push_back(1); // Add 1
  
  for (int i = msb - 1; i >= 0; i--) {
    idx = (static_cast<int>(std::pow(2, i)) & n) > 0 ? 1 : 0;
    x = 2 * x + idx;
    l.push_back(x); // Add next number
  }
  
  return l;
}
