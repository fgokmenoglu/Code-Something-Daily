/*
 * The goal of this exercise is to convert a string to a new string where each character in the new string is "(" 
 * if that character appears only once in the original string, or ")" if that character appears more than once in 
 * the original string. Ignore capitalization when determining if a character is a duplicate.
 * 
 * Examples
 *    "din"      =>  "((("
 *    "recede"   =>  "()()()"
 *    "Success"  =>  ")())())"
 *    "(( @"     =>  "))((" 
 * 
 * Notes
 * Assertion messages may be unclear about what they display in some languages. 
 * If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!
 */
#include <string>
#include <unordered_map>
#include <cctype>

std::string duplicate_encoder(const std::string& word) {
  std::unordered_map<char, int> mapping;
  std::string output = "";
  
  for (char ch : word) {
    ch = std::tolower(ch);
    ++mapping[ch];
  }
  
  for (char ch : word) {
    ch = std::tolower(ch);
    
    if (mapping[ch] > 1)
      output += ')';
    else
      output += '(';
  }
  
  return output;
}

// ALTERNATIVE
#include <string>
#include <map>
#include <cctype>

std::string duplicate_encoder(const std::string& word) {
    std::map<char, int> table;
    for (auto x : word) table[std::tolower(x)]++;
    
    std::string result;
    for (auto x: word) result += (table[std::tolower(x)] == 1) ? "(" : ")";
    
    return result;
}
