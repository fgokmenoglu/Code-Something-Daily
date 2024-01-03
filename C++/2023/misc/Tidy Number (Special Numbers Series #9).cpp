/*
 * Definition
 * A Tidy number is a number whose digits are in non-decreasing order.
 * 
 * Task
 * Given a number, Find if it is Tidy or not.
 * 
 * Notes
 * Number passed is always Positive.
 * Return the result as a Boolean
 * 
 * Input >> Output Examples
 * tidyNumber (12) ==> return (true)
 * Explanation:
 * The number's digits { 1 , 2 } are in non-Decreasing Order (i.e) 1 <= 2 .
 * 
 * tidyNumber (32) ==> return (false)
 * Explanation:
 * The Number's Digits { 3, 2} are not in non-Decreasing Order (i.e) 3 > 2 .
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

bool tidyNumber (int number) {
  vector<int> digits = {};
  
  while (number > 0) {
    digits.push_back(number % 10);
    number /= 10;
  }
  
  reverse(digits.begin(), digits.end());
  
  return is_sorted(digits.begin(), digits.end());
}

// ALTERNATIVE
#include <string>
#include <algorithm>

using namespace std;

bool tidyNumber (int number) {
  string num = to_string(number);
  sort(num.begin(), num.end());
  
  return num == to_string(number) ? true : false;
}
