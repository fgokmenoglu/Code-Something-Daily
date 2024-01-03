/*
 * Given a string s, write a method (function) that will return true if its a valid single integer or floating number or false if its not.
 * 
 * Valid examples:
 * 
 * should return true:
 * isDigit("3")
 * isDigit("  3  ")
 * isDigit("-3.23")
 *  
 * should return false:
 * isDigit("3-4")
 * isDigit("  3   5")
 * isDigit("3 5")
 * isDigit("zero")
 */
#include <string>

bool is_digit(std::string s) { 
  for (unsigned i = 0; i < s.size(); i++) {
    char c = s[i];
    
    switch(c) {
      case '.' : case '0' ... '9' : continue;
      case '-' : if (i == 0) continue; 
    }
    
    return false;
  }
  
  return s.size();
}
