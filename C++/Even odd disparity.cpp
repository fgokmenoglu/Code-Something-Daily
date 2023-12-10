/*
 * Given an array, return the difference between the count of even numbers and the count of odd numbers. 0 will be considered an even number.
 * 
 * For example:
 * solve([0,1,2,3]) = 0 because there are two even numbers and two odd numbers. Even - Odd = 2 - 2 = 0.  
 * Let's now add two letters to the last example:
 * 
 * solve([0,1,2,3,'a','b']) = 0. Again, Even - Odd = 2 - 2 = 0. Ignore letters. 
 * The input will be an array of lowercase letters and numbers only.
 * 
 * In some languages (Haskell, C++, and others), input will be an array of strings:
 * solve ["0","1","2","3","a","b"] = 0 
 */
#include <vector>
#include <string>
#include <cctype>

bool isNumber(const std::string& s) {
    return std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int solve(std::vector<std::string> v) {
  int evenCount = 0, oddCount = 0;
  
  for (size_t i = 0; i < v.size(); ++i)
    if (isNumber(v[i]))
      if (stoi(v[i]) % 2 == 0)
        ++evenCount;
      else
        ++oddCount;
  
  return evenCount - oddCount;
}

// ALTERNATIVE
#include <string>
#include<vector>

int solve(std::vector<std::string>v) {
    int a = 0;
  
    for (std::string s : v)
        if(isdigit(s[0]))
            stoi(s) % 2 == 0 ?  a++ : a--;
  
    return a;
}
