/*
 * Determine the total number of digits in the integer (n>=0) given as input to the function. 
 * For example, 9 is a single digit, 66 has 2 digits and 128685 has 6 digits. Be careful to avoid overflows/underflows.
 * All inputs will be valid.
 */
#include <stdint.h>

int digits(uint64_t n) {
  int numDigits = 0;
  
  if (n == 0)
    return 1;
  
  while(n > 0) {
    ++numDigits;
    n /= 10;
  }
  
  return numDigits;
}

// ALTERNATIVE
#include <stdint.h>
#include <string> // for to_string()

using namespace std;

int digits(uint64_t n) {
  return to_string(n).length();
}
