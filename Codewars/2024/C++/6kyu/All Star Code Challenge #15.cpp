/* 
 * Task:
 * The scroller works by replacing the current text string with a similar text string, but with the first letter shifted to the end; this simulates movement.
 * Your father is far too busy with the business to worry about such details, so, naturally, he's making you come up with the text strings.
 * Create a function named rotate() that accepts a string argument and returns an array of strings with each letter from the input string being rotated to the end.
 *
 * Example:
 * rotate("Hello") // => {"elloH", "lloHe", "loHel", "oHell", "Hello"}
 *
 * Notes:
 * The original string should be included in the output array. 
 * The order matters. Each element of the output array should be the rotated version of the previous element. 
 * The output array SHOULD be the same length as the input string. 
 * The function should return an empty array with a 0 length string, '', as input.
 */
#include <string>
#include <vector>

std::vector<std::string> rotate(const std::string& s) {
  std::string temp = s + s;
  size_t len = s.length();
  std::vector<std::string> out = {};
  
  for (size_t i = 0; i < len; ++i)
    out.push_back(temp.substr(i + 1, len));  
  
  return out;
}

// ALTERNATIVE
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> rotate(const std::string& s) {
  std::vector<std::string> output;
  std::string tempString{s};
  
  for(auto c : s) {
    std::rotate(tempString.begin(), tempString.begin() + 1, tempString.end());
    output.push_back(tempString);
  }
  
  return output;
}
