/*
i
i is the imaginary unit, it is defined by 
i
²
=
−
1
i²=−1, therefore it is a solution to 
x
²
+
1
=
0
x²+1=0.

Your Task

Complete the function pofi that returns 
i
i to the power of a given non-negative integer in its simplest form, as a string (answer may contain
i
i).

*/
#include <string>

std::string pofi(unsigned n) {
  return (std::string[]){"1", "i", "-1", "-i"}[n % 4];
}
