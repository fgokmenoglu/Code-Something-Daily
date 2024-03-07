/*
 * Given a number, write a function to output its reverse digits. (e.g. given 123 the answer is 321)
 * Numbers should preserve their sign; i.e. a negative number should still be negative when reversed.
 *
 * Examples
 * 123 ->  321
 * -456 -> -654
 * 1000 ->    1
 */
#include <string>
#include <algorithm>

long long reverseNumber(long long n) {
  bool is_negative = false;
  if (n < 0) is_negative = true;
  
  std::string str_n = std::to_string(n);
  reverse(str_n.begin(), str_n.end());
  
  return is_negative ? -1 * stoll(str_n) : stoll(str_n);
}

// ALTERNATIVE
long long reverseNumber(long long n) {
  long long x = 0;
  while(n != 0){
    x = x * 10 + n % 10;
    n /= 10;
  }
  return x;
}
