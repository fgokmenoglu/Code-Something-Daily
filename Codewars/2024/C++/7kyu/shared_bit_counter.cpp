/*
 * Complete the method that returns true if 2 integers share at least two 1 bits, otherwise return false. 
 * For simplicity assume that all numbers are non-negative.
 *
 * Examples
 * 7  =  0111 in binary
 * 10  =  1010
 * 15  =  1111
 *
 * 7 and 10 share only a single 1-bit (at index 2) --> false
 * 7 and 15 share 3 1-bits (at indexes 1, 2, and 3) --> true
 * 10 and 15 share 2 1-bits (at indexes 0 and 2) --> true
 *
 * Hint: you can do this with just string manipulation, but binary operators will make your life much easier.
 */
bool shared_bits(long a, long b) {
    // Compute the bitwise AND to get common bits
    long common_bits = a & b;
    
    // Count the number of 1s in the common bits
    int count = 0;
    while (common_bits != 0) {
        count += common_bits & 1;  // Increment if the lowest bit is 1
        common_bits >>= 1;         // Shift right by 1 to check the next bit
        
        // Early exit if we already have at least two 1s
        if (count >= 2) {
            return true;
        }
    }
    
    return false;
}

// ALTERNATIVE
#include <bitset>
bool shared_bits(long a, long b){
  std::bitset<32> c;
  c = a & b;
  return c.count()>=2 ;
}
