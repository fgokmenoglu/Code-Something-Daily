/*
 * Definition
 * A number is a Special Number if it’s digits only consist 0, 1, 2, 3, 4 or 5
 * Given a number determine if it special number or not.
 *
 * Notes
 * The number passed will be positive (N > 0) .
 * All single-digit numbers within the interval [1:5] are considered as special number.
 */
#include <string>

using namespace std; 

string specialNumber (int number) {
  string numberStr = to_string(number);
  string specialStr = "012345";
  
  for (size_t i = 0; i < numberStr.length(); i++)
    if (count(specialStr.cbegin(), specialStr.cend(), numberStr[i]) == 0)
      return "NOT!!";
  
  return "Special!!";
}

// ALTERNATIVE
#include <string>
#include <algorithm>

using namespace std; 

string specialNumber (int number) {
  auto s = to_string(number);
  
  return all_of(s.cbegin(), s.cend(), [](auto ch) { return ch <= '5'; }) ? "Special!!" : "NOT!!";
}
