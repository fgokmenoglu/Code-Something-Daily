/*
 * Task
 * Given a string str, reverse it and omit all non-alphabetic characters.
 * 
 * Example
 * For str = "krishan", the output should be "nahsirk".
 * 
 * For str = "ultr53o?n", the output should be "nortlu".
 * 
 * Input/Output
 * [input] string str
 * A string consists of lowercase latin letters, digits and symbols.
 * 
 * [output] a string
 */
#include <string>
#include <algorithm>

std::string reverse_letter(const std::string &str) {
  std::string output = str;
  
  output.erase(std::remove_if(output.begin(), output.end(), 
    [](auto const& ch) -> bool { return !std::isalpha(ch); }), output.end());
  
  reverse(output.begin(), output.end());
  
  return output;
}
