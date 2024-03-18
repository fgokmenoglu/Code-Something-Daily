/*
 * The depth of an integer n is defined to be how many multiples of n 
 * it is necessary to compute before all 10 digits have appeared at least once in some multiple.
 *
 * Example: n = 42
 * Multiple         value         digits     comment
 * 42*1              42            2,4 
 * 42*2              84             8         4 existed
 * 42*3              126           1,6        2 existed
 * 42*4              168            -         all existed
 * 42*5              210            0         2,1 existed
 * 42*6              252            5         2 existed
 * 42*7              294            9         2,4 existed
 * 42*8              336            3         6 existed 
 * 42*9              378            7         3,8 existed
 *
 * Looking at the above table under digits column you can find all the digits from 0 to 9; 
 * hence it required 9 multiples of 42 to get all the digits. So the depth of 42 is 9. 
 *
 * Write a function named computeDepth which computes the depth of its integer argument.
 * Only positive numbers greater than zero will be passed as an input.
 */
#include <map>

unsigned integer_depth(unsigned n) {
  unsigned out = 1;
  unsigned temp = n;
  std::map<unsigned, unsigned> digits = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
  
  while (true) {    
    while (temp > 0) {
      digits[temp % 10] += 1;
      temp /= 10;
    }
    
    bool isDone = true;
    
    for (unsigned i = 0; i < 10; ++i)
      if (digits[i] == 0)
        isDone = false;
    
    if (isDone)
      break;
    
    out += 1;
    temp = n * out;
  }
  
  return out;
}

// ALTERNATIVE
unsigned integer_depth(unsigned n) {
    bool seen[10] = {0};  // Array to keep track of seen digits
    unsigned count = 0;   // Count of multiplications
    unsigned total_seen = 0;  // Total number of unique digits seen

    while (total_seen < 10) {
        count++;
        unsigned product = n * count;

        // Process each digit of the product
        while (product > 0) {
            unsigned digit = product % 10;
          
            if (!seen[digit]) {
                seen[digit] = true;
                total_seen++;
            }
          
            product /= 10;
        }
    }

    return count;
}
