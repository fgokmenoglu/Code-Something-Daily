/*
 * Build a function that returns an array of integers from n to 1 where n>0.
 * 
 * Example : n=5 --> [5,4,3,2,1]
 */
#include <stdlib.h>

unsigned short* reverse_seq(unsigned short num) {
  unsigned short* ptr = (unsigned short*) malloc(num * sizeof(unsigned short));
  
  for (unsigned short i = num; i > 0; i--)
    ptr[num - i] = i;

  return ptr;
}
