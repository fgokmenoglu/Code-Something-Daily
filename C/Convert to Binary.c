/*
 * Task Overview
 * Given a non-negative integer n, write a function to_binary/ToBinary which returns that number in a binary format.
 * 
 * Example:
 * 
 * to_binary(1)  // should return 1
 * to_binary(5)  // should return 101
 * to_binary(11) // should return 1011
 */
#include <math.h>

unsigned long long to_binary(unsigned short num) {
    unsigned long long binNumber = 0;
    int power = 0;
    
    while (num > 0) {
        int rem = num % 2;
        unsigned long long temp = pow(10, power);
        binNumber += rem * temp;
        power++;
        num /= 2;
    }
  
  return binNumber;
}

// ALTERNATIVE
unsigned long long to_binary(unsigned long long num) {
    unsigned long long binNumber = 0;
    unsigned long long temp = 1;
  
    while (num > 0) {
      binNumber += (num & 1) * temp;
      temp *= 10;
      num >>= 1;
    }
  
    return binNumber;
}
