/*
 * In this Kata, you will be given two strings a and b and your task will be to return the characters that are not common in the two strings.
 * 
 * For example:
 * 
 * solve("xyab","xzca") = "ybzc" 
 * --The first string has 'yb' which is not in the second string. 
 * --The second string has 'zc' which is not in the first string.
 * 
 * Notice also that you return the characters from the first string concatenated with those from the second string.
 */
#include <string>

std::string solve(std::string a, std::string b) {
  std::string output = "";
  
  for (auto ch : a)
    if (b.find(ch) == std::string::npos)
      output.push_back(ch);
  
  for (auto ch : b)
    if (a.find(ch) == std::string::npos)
      output.push_back(ch);
  
  return output;
}
