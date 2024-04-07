/*
 * In this kata you get the start number and the end number of a region and 
 * should return the count of all numbers except numbers with a 5 in it. 
 * The start and the end number are both inclusive!
 *
 * Examples:
 * 1,9 -> 1,2,3,4,6,7,8,9 -> Result 8
 * 4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> Result 12
 *
 * The result may contain fives. ;-)
 * The start number will always be smaller than the end number. 
 * Both numbers can be also negative!
 */
#include <stdbool.h>

bool containsFive(int number) {
  if (number < 0)
        number = -number; // Make the number positive for negative range

  while (number > 0) {
    if (number % 10 == 5)
      return true; // Return true if any digit is '5'
      
    number /= 10; // Move to the next digit
  }
  
  return false; // No digit is '5'
}

int dontGiveMeFive(int start, int end) {
  int count = 0;
  
  for (int i = start; i <= end; ++i)
    if (!containsFive(i))
      count++;
  
  return count;
}
