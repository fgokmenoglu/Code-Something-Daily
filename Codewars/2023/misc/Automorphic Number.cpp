/*
 * Definition
 * A number is called Automorphic number if and only if its square ends in the same digits as the number itself.
 * 
 * Task
 * Given a number determine if it Automorphic or not .
 */
#include <string>

using namespace std; 

string autoMorphic (int number) {
  string itself = to_string(number);
  string squared = to_string(number * number);
  return squared.substr(squared.length() - itself.length()) == itself ? "Automorphic" : "Not!!";
}

// ALTERNATIVE
const char* autoMorphic(int n) {
  for (auto square = n * n; n; square /= 10, n /= 10)
    if (square % 10 != n % 10)
      return "Not!!";
  return "Automorphic";
}
