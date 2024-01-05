/*
 * In this kata, you need to write a function that takes a string and a letter as input and then returns the index of the second occurrence of that letter in the string. 
 * If there is no such letter in the string, then the function should return -1. 
 * If the letter occurs only once in the string, then -1 should also be returned.
 *
 * Examples:
 *
 * secondSymbol('Hello world!!!','l') --> 3
 * secondSymbol('Hello world!!!', 'A') --> -1
 */
#include <string>

int secondSymbol(const std::string& str, char symbol) { 
  std::size_t found = str.find(symbol);
  
  if (found != std::string::npos) {
    std::size_t found2 = str.find(symbol, found + 1);
    return found2 != std::string::npos ? found2 : -1;
  }
  
  return -1; // there is no such symbol in the given string
}

// ALTERNATIVE
#include <string>

int secondSymbol(const std::string& str, char symbol) {
  return str.find(symbol, str.find(symbol) + 1);
}

// The constant, std::string::npos, is defined with a value of -1, 
// which because size_t is an unsigned integral type, it is the 
// largest possible representable value for this type.
