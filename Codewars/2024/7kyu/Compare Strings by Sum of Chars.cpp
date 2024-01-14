/*
 * Compare two strings by comparing the sum of their values (ASCII character code).
 * 
 * For comparing treat all letters as UpperCase
 * null/NULL/Nil/None should be treated as empty strings
 * If the string contains other characters than letters, treat the whole string as it would be empty
 * Your method should return true, if the strings are equal and false if they are not equal.
 * 
 * Examples:
 * "AD", "BC"  -> equal
 * "AD", "DD"  -> not equal
 * "gf", "FG"  -> equal
 * "zz1", ""   -> equal (both are considered empty)
 * "ZzZz", "ffPFF" -> equal
 * "kl", "lz"  -> not equal
 * null, ""    -> equal
 */
#include <string>
#include <algorithm>
#include <cctype>

bool compare(std::string s1, std::string s2) {
  std::cout << "s1: " << s1 << " and s2: " << s2 << std::endl;
  int sum1 = 0, sum2 = 0;
  
  std::transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char ch) { return std::toupper(ch); });
  std::transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char ch) { return std::toupper(ch); });
    
  for (auto ch : s1) {
    if (!isalpha(ch)) {
      sum1 = 0;
      break;
    }
    
    sum1 += (int) ch;
  }
    
  for (auto ch : s2) {
    if (!isalpha(ch)) {
      sum2 = 0;
      break;
    }
    
    sum2 += (int) ch;
  }
    
  return sum1 == sum2;
